
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
	if (isEmpty(&list))
	{
		puts("There are no tasks to display");
		return;
	}

	puts("Your task list from most recent to the first task you added");
	do
	{
		printf("\nTask title: %s\nTask description: %s\n", current->taskdata.tasktitle, current->taskdata.taskdescription);
		current = current->next;
	} while (current != NULL);

}

void DisplaySingleTask(PLISTNODE list)  //should void DisplaySingleTask(PSTACK list, const int max)
{
	PLISTNODE current = list;
	char infotodisplay[TITLE];
	bool found = false;

	if (isEmpty(&list))
	{
		puts("There are no tasks to display");
		return;
	}

	puts("Select which task you want to display by entering its title: ");
	GetString(infotodisplay, TITLE);

	do
	{
		if (strcmp(current->taskdata.tasktitle, infotodisplay) == 0)
		{
			printf("\nTask title: %s\nTask description: %s\n", current->taskdata.tasktitle, current->taskdata.taskdescription);
			found = true;  //added so the message ""This task does not exist on your list" would not be displayed after printing the desired task
		}
			
		current = current->next;

	} while (current != NULL);

	if (current == NULL && !found)  //added this part - Saba
	{
		puts("This task does not exist on your list");
		return;
	}

}



void RangeTask(PLISTNODE list)
{
	PLISTNODE current = list;
	char letter;
	int flag = 0;

	if (TaskCount(list) == 0)
	{
		puts("There are no tasks on your list to display");
		return;
	}

	puts("Please enter a letter to display the titles starting with that letter");
	if (letter = GetLetter())
	{
		do
		{
			if (current->taskdata.tasktitle[0] == letter)
			{
				printf("\nTask title: %s\nTask description: %s\n", current->taskdata.tasktitle, current->taskdata.taskdescription);
				flag++;
			}
			current = current->next;
		} while (current != NULL);

		if (flag == 0)
			puts("There are no titles on your list that start with this letter");

	}


}

int TaskCount(PLISTNODE list)
{
	int count = 0;

	PLISTNODE current = list;

	if (isEmpty(&list))
	{
		return 0;
	}

	do
	{
		count++;
		current = current->next;
	} while (current != NULL);
	return count;


}

void PrintTaskCount(int count)
{
	if (count == 1)
		puts("There is 1 item on the list\n");
	else
		printf("There are %d items on your list.\n", count);
}

void UpdateTask(PLISTNODE* list)
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


	if (current == NULL && !found)  //the whole list has been searched and this task does not exist on it
		printf("This task does not exist on the list\n");
}


void SelectWhatToUpdate(PLISTNODE current)
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
			strcpy(current->taskdata.tasktitle, title);
			UpdateMenu();
			break;
		case 'b':
			printf("Enter the new task description: \n");
			GetString(description, MAXLEN);
			strcpy(current->taskdata.taskdescription, description);
			UpdateMenu();
			break;
		default:
			puts("\nInvalid input!");  //print when the user chooses an invalid option from the menu
			puts("Please try again.");
			UpdateMenu();
		}
	}
}

void SearchForTask(PLISTNODE list)
{
	PLISTNODE current = list;
	char infotodisplay[TITLE];
	int found = 0;

	if (isEmpty(&list))
	{
		puts("There are no tasks on your list");
		return;
	}

	puts("Select which task you want to search for:");
	GetString(infotodisplay, TITLE);

	do
	{
		if (strcmp(current->taskdata.tasktitle, infotodisplay) == 0)
		{
			found++;
		}
		current = current->next;
	} while (current != NULL);

	if (current == NULL && !found)  //the whole list has been searched and this task does not exist on it
		printf("You do NOT have this task on your list\n");
}

void LastItem(PLISTNODE list)
{
	PLISTNODE current = list;
	int number;

	if (isEmpty(&list))
	{
		puts("There are no tasks to display");
		return;
	}
	else
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		printf("This is the last item you entered: \n");
		printf("\nTask title: %s\nTask description: %s\n", current->taskdata.tasktitle, current->taskdata.taskdescription);
	}
	
}
	if (current == NULL && found == 0)  //the whole list has been searched and this task does not exist on it
	{
		puts("You do NOT have this task on your list\n");
		return;
	}

	if (found == 1)
		puts("You have this task on your list.\n");
	if(found > 1)
		printf("You have %d tasks with the same title on your list.\n", found);

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


