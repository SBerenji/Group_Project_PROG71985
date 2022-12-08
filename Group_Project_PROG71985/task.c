//put the documentation here

/*****************************************************************************
*                      PROG71985/ Group Project                              *
*                    Professor: Steve Hendrikse                              *
*                                                                            *
*		 BY:	 Michelle Novar, Saba Berenji, Sierra Erb                    *
*        DATE: 	 November,2022                                               *
*		 DESCRIPTION:													     *
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
	//PSTACK previous;

	newnode = (PLISTNODE)malloc(sizeof(LISTNODE));  //dynamically allocate memory

	if (newnode == NULL)  //if malloc returns NULL 
	{
		fprintf(stderr, "error allocating memory\n");  //error message if memory allocation is unsuccessful
		exit(EXIT_FAILURE);
	}

	if (isEmpty(&list))
	{
		//newnode->taskdata.tasknumber = 1;
		*list = newnode; /* first structure */
	}

	else  /* subsequent structures */
		//previous->next = current;

	{
		newnode->next = NULL;
		//newnode->taskdata.tasknumber++;
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
		puts("There are no tasks to display");
		return;
	}
	puts("Pleases enter the title of the task you want to delete");
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
	if (*list == NULL)  //return true if stack is empty
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
		//printf("Task number: \nTask title: %s\nTask description: %s\n", current->taskdata.tasknumber, current->taskdata.tasktitle, current->taskdata.taskdescription);
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
			//printf("Task number: %d\nTask title: %s\nTask description: %s\n", current->taskdata.tasknumber, current->taskdata.tasktitle, current->taskdata.taskdescription);
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

int TaskCount(PLISTNODE list)
{
	int count = 0;

	PLISTNODE current = list;

	if (isEmpty(&list))
	{
		return 0;
	}

	//while (current != NULL)
	//{
	//	current = current->next;
	//	count++;
	//}

	do
	{
		count++;
		current = current->next;
	} while (current != NULL);
	return count;

	/*if (count == 1)
		puts("There is 1 item on the list\n");

	else
		printf("There are %d items on your list.\n", count);*/

}

void PrintTaskCount(int count)
{
	if (count == 1)
		puts("There is 1 item on the list\n");
	else
		printf("There are %d items on your list.\n", count);
}

void ValidateAndPrintRange(PLISTNODE list)
{
	PLISTNODE current = list;
	int firstinput = '\0';
	int secondinput = '\0';

	GetRange(firstinput, secondinput);

	if (firstinput < 1 || secondinput > current->taskdata.tasknumber)
	{
		puts("Invalid range.\n");
	}
	else
	{
		DisplayRange(list, firstinput, secondinput);
	}

}

void Swaps(int* firstnumber, int* secondnumber)
{
	int temporary = *firstnumber;
	*firstnumber = *secondnumber;
	*secondnumber = temporary;
}

void DisplayRange(PLISTNODE list, int firstnumber, int secondnumber)
{
	PLISTNODE current = list;
	for (int i = firstnumber; i <= secondnumber; i++)
	{
		puts("Task title: %s\nTask description: %s\n", current->taskdata.tasktitle, current->taskdata.taskdescription);
	}
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
	bool found = false;

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
			found = true;
			printf("You have this task on your list.\n");
		}
		current = current->next;
	} while (current != NULL);

	if (current == NULL && !found)  //the whole list has been searched and this task does not exist on it
		printf("You do NOT have this task on your list\n");
}
