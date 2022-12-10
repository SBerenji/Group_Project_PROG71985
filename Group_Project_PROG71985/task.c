
/*****************************************************************************
*                      PROG71985/ Group Project                              *
*                    Professor: Steve Hendrikse                              *
*                                                                            *
*		 BY:	 Michelle Novar, Saba Berenji, Sierra Erb                    *
*        DATE: 	 December,2022                                               *
* DESCRIPTION:   A user-friendly task manager with a menu containing several *
*                options to add, remove, display, and update the tasks       *
******************************************************************************/

#include "menu.h"
#include "task.h"
#include "input.h"
#include "file.h"



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
		*list = newnode; /* first structure */
	}
	


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


	if (strcmp(current->taskdata.tasktitle, infoToBeDeleted) == 0)  //if the title is the same as the title of the last item on the list
	{

		puts("Is this the task you intend to delete?");
		printf("\nTask title: %s\nTask description: %s\n", current->taskdata.tasktitle, current->taskdata.taskdescription); //prints the info that matches the searched title

		puts("If yes enter 'y' and if no enter 'n'");
		char ch = getchar();
		while ((getchar()) != '\n');

		if (ch == 'y')   //since the list can have several tasks with the same title, the user should be asked if it intends to delete this task
		{
			if (current->next != NULL)
				*list = current->next;
			else
				*list = NULL;

			free(current);
			puts("You deleted the task.");
			return;
		}

		else
			current = current->next;
	}

	int flag = 0;

	PLISTNODE prev = current;  // we will need the previous node for to link over the deleted one
	while (current != NULL)
	{
		if (strcmp(current->taskdata.tasktitle, infoToBeDeleted) == 0)
		{
			puts("Is this the task you intend to delete?");
			printf("\nTask title: %s\nTask description: %s\n", current->taskdata.tasktitle, current->taskdata.taskdescription); //prints the info that matches the searched title

			puts("If yes enter 'y' and if no enter 'n'");
			char character = getchar();

			if (character == 'y')
			{
				flag++;
				break;
			}
			character = getchar();
		}

		prev = current;
		current = current->next;
	}



	if (current == NULL && flag == 0)
	{
		puts("The task that you want to remove from your task manager does not exist");
		return;  //wasn't found - and we hit the end
	}

	prev->next = current->next; //unlink the node from the list

	free(current);  // Free memory 
	puts("You deleted the task");
}


bool isEmpty(PLISTNODE* list)  //isEmpty function definition
{
	if (*list == NULL)  //return true if stack is empty
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

	puts("Enter the title of the task you want to display: ");
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
		}
			
		current = current->next; //move to the next item on the list

	} while (current != NULL); //we want to do this until we reach the end of the list

	if (current == NULL && !found)  //added this part - Saba
	{
		puts("This task does not exist on your list");
		return;
	}

}



void RangeTask(PLISTNODE list)  //RangeTask function definition
{
	PLISTNODE current = list;
	char letter1, letter2, temp;

	int flag = 0;

	if (TaskCount(list) == 0) //checks if the list is empty
	{
		puts("There are no tasks on your list to display");
		return;
	}

	puts("Please enter two letters to determine the range of the tasks you want to print\nbased on the first letter of their titles:");
	puts("\nLetter 1:");
	if (letter1 = GetLetter())  //get user input for the first letter
	{
		puts("Letter 2:");
		if (letter2 = GetLetter())  //get user input for the second letter if the first letter is valid
		{
			if (letter2 < letter1)  //if the second letter is smaller swap
			{
				temp = letter1;
				letter1 = letter2;
				letter2 = temp;
			}

			do
			{
				if ((letter1 <= current->taskdata.tasktitle[0]) && (current->taskdata.tasktitle[0] <= letter2)) //if the first letter of the title is between these two alphabets
				{
					printf("\nTask title: %s\nTask description: %s\n", current->taskdata.tasktitle, current->taskdata.taskdescription);
					flag++;  //increment everytime a task is found and printed
				}
				current = current->next;
			} while (current != NULL);
		}


		if (flag == 0)  //if flag is zero no tasks were found in this range
			puts("There are no titles in this range that start with these letters");
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
			printf("Is this the task you would like to update? If yes press y, if no press n\n");
			char ch = GetLetter();
			if (ch == 'y')
			{
				SelectWhatToUpdate(current);		
			}
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

	puts("Enter the title of the task you want to search for:");
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
		printf("This is the last item you entered based on your last save: \n");
		printf("\nTask title: %s\nTask description: %s\n", current->taskdata.tasktitle, current->taskdata.taskdescription);
	}
	
}


