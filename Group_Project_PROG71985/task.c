
/*****************************************************************************
*                      PROG71985/ Group Project                              *
*                    Professor: Steve Hendrikse                              *
*                                                                            *
*		 BY:	 Michelle Novar, Saba Berenji, Sierra Erb                    *
*        DATE: 	 December,2022                                               *
* DESCRIPTION:   A user-friendly task manager with a menu containing several *
*                options to add, remove, display, and update the tasks       *
******************************************************************************/

#include "task.h"
#include "input.h"
#include "menu.h"



PLISTNODE InitializeStack(PLISTNODE list)  //InitializeStack function definition
{
	list = NULL;  //Initialize the list to NULL and the return the list
	return list;
}


void AddTask(PLISTNODE* list, char titledata[], char descriptdata[])  //PushToSatck function definition, this function adds all the new nodes to the front of the list
{
	PLISTNODE newnode = NULL;
	if (isEmpty(&list))
	{
		//newnode->taskdata.tasknumber = 1;
		*list = newnode; /* first structure */
	}
	

	//PSTACK previous;

	newnode = (PLISTNODE)malloc(sizeof(LISTNODE));  //dynamically allocate memory

	if (newnode == NULL)  //if malloc returns NULL 
	{
		fprintf(stderr, "error allocating memory\n");  //error message if memory allocation is unsuccessful
		exit(EXIT_FAILURE);
	}

	if (isEmpty(&list))
	{
		*list = newnode; /* first structure */
	}


	else  /* subsequent structures */
	{
		newnode->next = NULL;
	}

	strcpy(newnode->taskdata.tasktitle, titledata);
	strcpy(newnode->taskdata.taskdescription, descriptdata);

	newnode->next = *list;

	*list = newnode;

	puts("The task has been added to your task manager");

}

void RemoveTask(PLISTNODE* list)   //void RemoveTask(PSTACK* list, int max)   <- should be like this but doesn't work for me - Saba
{
	PLISTNODE current = *list;
	char infoToBeDeleted[TITLE];


	if (isEmpty(list))
	{
		puts("There are no tasks to delete");
		return;
	}
	puts("Please enter the title of the task you want to delete");
	GetString(infoToBeDeleted, TITLE);

	if (strcmp(current->taskdata.tasktitle, infoToBeDeleted) == 0)
	{
			if (current->next != NULL)
				*list = current->next;
			else
				*list = NULL;

			free(current);
			puts("You deleted the task.");
			return;
	}

	PLISTNODE prev = current;  // we will need the previous node for to link over the deleted one
	while (current != NULL && strcmp(current->taskdata.tasktitle, infoToBeDeleted) != 0)
	{
		prev = current;
		current = current->next;
	}

	if (current == NULL)
	{
		puts("The task that you want to remove from your task manager does not exist");
		return;  //wasn't found - and we hit the end
	}
		
	prev->next = current->next; //unlink the node from the list

	free(current);  // Free memory 
	puts("You deleted the task.");
}


bool isEmpty(PLISTNODE* list)  //isEmpty function definition
{
	PLISTNODE current = *list;
	if (current == NULL)  //return true if stack is empty
		return true;
	else
		return false;
}



void DisplayAll(PLISTNODE list)
{
	PLISTNODE current = list;
	if (isEmpty(&list)) //checks if list is empty
	{
		puts("There are no tasks to display");
		return;
	}
	else //enters this if the list is not empty
	{
		puts("Your task list:");
		do //do while loop because we know there is at least one thing on the list so we will need to print at least one thing
		{
			printf("\nTask title: %s\nTask description: %s\n", current->taskdata.tasktitle, current->taskdata.taskdescription);
			current = current->next; //after it is printed current is changed to the next item on the list
		} while (current != NULL);
	}
}

void DisplaySingleTask(PLISTNODE list)  //should void DisplaySingleTask(PSTACK list, const int max)
{
	PLISTNODE current = list;
	char infotodisplay[TITLE];
	bool found = false; //we use this to determine if the task was ever found on the list or not 

	if (isEmpty(&list)) //checks if list is empty
	{
		puts("There are no tasks to display");
		return;
	}

	puts("Select which task you want to display by entering its title: ");
	GetString(infotodisplay, TITLE); //user enters the task title they want to display

	do //do while loop because we know there is at least one item on the list so we will definitly need to loop at least once
	{
		if (strcmp(current->taskdata.tasktitle, infotodisplay) == 0) //if they are exactly the same strcmp will return 0
		{
			printf("Here is one occurance of this task appearing in your list\n"); 
			printf("\nTask title: %s\nTask description: %s\n", current->taskdata.tasktitle, current->taskdata.taskdescription); //prints the info that matches the searched title
			found = true;  //added so the message ""This task does not exist on your list" would not be displayed after printing the desired task
			printf("Was this the task you wanted to display? If yes select y, if no select n\n"); //there could be more than one tasks witht he same title so we want to check if that was the right one
			char ch = GetLetter(); 
			if (ch == 'y')
				return; //it was the right want so we can exit this function because it was already printed
			ch = getchar(); 
		}
			
		current = current->next; //move to the next item on the list

	} while (current != NULL); //we want to do this until we reach the end of the list

	if (current == NULL && !found)  //added this part - Saba
	{
		puts("This task does not exist on your list");
		return;
	}

}






void RangeTask(PLISTNODE list)
{
	PLISTNODE current = list;
	char letter1, letter2;
	int flag = 0;

	if (TaskCount(list) == 0) //checks if the list is empty
	{
		puts("There are no tasks on your list to display");
		return;
	}

	puts("Please enter two letters to determine the range of the tasks you want to print based on the first letter of their titles:");
	puts("Letter 1:");
	if (letter1 = GetLetter())
	{
		puts("Letter 2:");
		if (letter2 = GetLetter())

			do
			{
				if ((letter1 <= current->taskdata.tasktitle[0]) && (current->taskdata.tasktitle[0] <= letter2))
				{
					printf("\nTask title: %s\nTask description: %s\n", current->taskdata.tasktitle, current->taskdata.taskdescription);
					flag++;
				}
				current = current->next;
			} while (current != NULL);

			if (flag == 0)
				puts("There are no titles on your list that start with these letters");
	}
}


int TaskCount(PLISTNODE list)  // this counts the tasks on list 
{
	int count = 0; 

	PLISTNODE current = list;

	if (isEmpty(&list))
	{
		return count; //if list is empty than count will still be zero
	}
	else
	{
		do //do while loop because we know there is at least one item on the list and will need to count++ at least once
		{
			count++; //count up by one for every iteration (for each item on the list)
			current = current->next;
		} while (current != NULL);
		return count;
	}
}

void PrintTaskCount(int count)  // this is needed to fix the grammar associated with the print statements  
{
	if (count == 1)
		puts("There is 1 item on the list\n"); //"is" since there is only one
	else
		printf("There are %d items on your list.\n", count); //"are" since there is only one
}

void UpdateTask(PLISTNODE* list)  // this is to update task 
{
	PLISTNODE current = *list;
	char tasktoupdate[TITLE];
	bool found = false; //this is required for when no items are found in the list and is used at the end of this function

	if (isEmpty(list)) //checks if there are no tasks on the list
	{
		puts("There is no task on the list to update");
		return;
	}

	puts("Select which task you want to update by entering its title: ");
	GetString(tasktoupdate, TITLE);

	do
	{
		if (strcmp(current->taskdata.tasktitle, tasktoupdate) == 0) //if they are identical it will equal 0
		{
			found = true; //change found to true because it was found
			printf("This is one of the tasks with that name:\n");
			printf("Task title: %s\nTask description: %s\n", current->taskdata.tasktitle, current->taskdata.taskdescription);
			printf("Is this the task you would like to update? If yes select y, if no select n\n");
			char ch = GetLetter();
			if (ch == 'y')
			{
				SelectWhatToUpdate(current);		
			}

			ch = getchar();	
		}
		
		current = current->next;
	} while (current != NULL); //loops through the entire list


	if (current == NULL && !found)  //the whole list has been searched and this task does not exist on it
		printf("This task does not exist on the list\n");
}




void SelectWhatToUpdate(PLISTNODE current) //this function contains the switch cases for the update menu 
{
	char choice;
	char title[TITLE];
	char description[MAXLEN];
	UpdateMenu();
	while ((choice = menuinput()) != 'c')  //call the menuinput function and exit the loop if the input is 'f'
	{
		switch (choice)  //using switch case statement for the menu options
		{
		case 'a':
			printf("Enter the new task title: \n");
			GetString(title, MAXLEN);
			strcpy(current->taskdata.tasktitle, title); //changes the current title to the newly selected one
			UpdateMenu();
			break;
		case 'b':
			printf("Enter the new task description: \n");
			GetString(description, MAXLEN);
			strcpy(current->taskdata.taskdescription, description); //changes the current description to the new one 
			UpdateMenu();
			break;
		default:
			puts("\nInvalid input!");  //print when the user chooses an invalid option from the menu
			puts("Please try again.");
			UpdateMenu();
		}
	}
}

void SearchForTask(PLISTNODE list) // this is to search for tast on list 
{
	PLISTNODE current = list;
	char infotodisplay[TITLE];
	int found = 0; //found is used to alter the print statement used at the end of this function

	if (isEmpty(&list))
	{
		puts("There are no tasks on your list"); //enters here if there are no tasks on the list
		return;
	}

	puts("Select which task you want to search for:");
	GetString(infotodisplay, TITLE);

	do
	{
		if (strcmp(current->taskdata.tasktitle, infotodisplay) == 0)
		{
			found++; //increments by one every time a matching task is found
		}
		current = current->next;
	} while (current != NULL); //iterates through the entire list

	if (current == NULL && found == 0)  //the whole list has been searched and this task does not exist on it
	{
		puts("You do NOT have this task on your list\n");
		return;
	}

	if (found == 1)
		puts("You have this task on your list.\n"); //only one was found
	if (found > 1)
		printf("You have %d tasks with the same title on your list.\n", found); //more than one was found so we put the number as well

}



void LastItem(PLISTNODE list)   // this is to show last item added
{
	PLISTNODE current = list;
	

	if (isEmpty(&list))
	{
		puts("There are no tasks to display");
		return;
	}
	else //if list is not empty enters here
	{
		while (current->next != NULL)
		{
			current = current->next;
		} //now current is at the end of the list because we have gone to the point where next is null (end of the list)
		printf("This is the last item you entered: \n");
		printf("\nTask title: %s\nTask description: %s\n", current->taskdata.tasktitle, current->taskdata.taskdescription);
	}
	
}





//void Swaps(int* firstnumber, int* secondnumber)
//{
//	int temporary = *firstnumber;
//	*firstnumber = *secondnumber;
//	*secondnumber = temporary;
//}
//
//void DisplayRange(PLISTNODE list, int firstnumber, int secondnumber)
//{
//	PLISTNODE current = list;
//	for (int i = firstnumber; i <= secondnumber; i++)
//	{
//		puts("Task title: %s\nTask description: %s\n", current->taskdata.tasktitle, current->taskdata.taskdescription);
//	}
//}

//
//void RangeTask(PLISTNODE list)
//{
//	PLISTNODE current = list;
//	char alphabet;
//
//	if (TaskCount(list) == 0)
//	{
//		puts("There are no tasks on your list to display");
//		return 0;
//	}
//
//
//	puts("Select the number of tasks you want to display from the beginning of the list (eg. 10 first items on the list): ");
//
//	if (range > TaskCount(list))
//	{
//		puts("The number you entered is out of range");
//		return 0;
//	}
//
//
//	if(range == TaskCount(list))    //if the number entered is equal to the number of tasks on the list same as if (strcmp(current->taskdata.tasktitle, infotodisplay) == 0)
//	{
//		do
//		{
//			printf("\nTask title: %s\nTask description: %s\n", current->taskdata.tasktitle, current->taskdata.taskdescription);
//			current = current->next;
//		} while (current != NULL);
//
//	}
//
//	else
//	{
//
//		do
//		{
//			current = current->next;
//		} while (current != NULL);
//
//		
//		for (int i = 0; i < range; i++)
//		{
//			current->next = NULL;
//			printf("\nTask title: %s\nTask description: %s\n", current->taskdata.tasktitle, current->taskdata.taskdescription);
//			current->next = list;
//			list = current;
//		}
//			
//	}
//	
//
//	//PLISTNODE prev = current;  // we will need the previous node for to link over the deleted one
//	//while (current != NULL && strcmp(current->taskdata.tasktitle, infoToBeDeleted) != 0)
//	//{
//	//	prev = current;
//	//	current = current->next;
//	//}
//
//	//if (current == NULL)
//	//{
//	//	puts("The task that you want to remove from your task manager does not exist");
//	//	return;  //wasn't found - and we hit the end
//	//}
//
//	//prev->next = current->next; //unlink the node from the list
//
//}
//
//void ValidateAndPrintRange(PLISTNODE list)
//{
//	PLISTNODE current = list;
//	int firstinput = '\0';
//	int secondinput = '\0';
//
//	GetRange(firstinput, secondinput);
//
//	if (firstinput < 1 || secondinput > current->taskdata.tasknumber)
//	{
//		puts("Invalid range.\n");
//	}
//	else
//	{
//		DisplayRange(list, firstinput, secondinput);
//	}
//
//}
//void DisplayRange(PLISTNODE list, int firstnumber, int secondnumber)
//{
//	PLISTNODE current = list;
//	for (int i = firstnumber; i <= secondnumber; i++)
//	{
//		puts("Task title: %s\nTask description: %s\n", current->taskdata.tasktitle, current->taskdata.taskdescription);
//	}
//}



//void RangeTask(PLISTNODE list)  // this is to search by range. 
//{
//	PLISTNODE current = list;
//	char letter;
//	int flag = 0;
//
//	if (TaskCount(list) == 0)
//	{
//		puts("There are no tasks on your list to display");
//		return;
//	}
//
//	puts("Please enter a letter to display the titles starting with that letter");
//	if (letter = GetLetter())
//	{
//		do
//		{
//			if (current->taskdata.tasktitle[0] == letter)
//			{
//				printf("\nTask title: %s\nTask description: %s\n", current->taskdata.tasktitle, current->taskdata.taskdescription);
//				flag++;
//			}
//			current = current->next;
//		} while (current != NULL);
//
//		if (flag == 0)
//			puts("There are no titles on your list that start with this letter");
//
//	}
//
//
//}



/*void UpdateTask(PLISTNODE* list)
{
	PLISTNODE current = *list;
	char tasktoupdate[TITLE];
	bool found = false;

	if (isEmpty(list))
	{
		puts("There is no task on the list to update");
		return;
	}

	puts("Select which task you want to update by entering its title: ");
	GetString(tasktoupdate, TITLE);

	int count = 0;
	do
	{
		if (strcmp(current->taskdata.tasktitle, tasktoupdate) == 0);
		{
			found = true;
			printf("This is the task you have selected:\n");
			printf("Task title: %s\nTask description: %s\n", current->taskdata.tasktitle, current->taskdata.taskdescription);
			SelectWhatToUpdate(current);
		}

		current = current->next;
	} while (current != NULL);

	if (count == 0)
	{
		printf("This task does not exist on the list\n");
	}
	else if (count == 1)
	{
		do
		{
			if (strcmp(current->taskdata.tasktitle, tasktoupdate) == 0)
			{
				found = true;
				printf("This is the task you have selected:\n");
				printf("Task title: %s\nTask description: %s\n", current->taskdata.tasktitle, current->taskdata.taskdescription);
				SelectWhatToUpdate(current);
			}

			current = current->next;
		} while (current != NULL);
	}
	else
	{
		printf("There are multiple tasks with the same name. You will be shown them in order they appear on the list.\n");
		do
		{
			if (strcmp(current->taskdata.tasktitle, tasktoupdate) == 0)
			{
				printf("Here is the first task with the name you searched for. If it is not the one you wanted to update select c.\n");
				printf("Task title: %s\nTask description: %s\n", current->taskdata.tasktitle, current->taskdata.taskdescription);
				SelectWhatToUpdate(current);
			}

			current = current->next;
		} while (current != NULL);
	}
}*/