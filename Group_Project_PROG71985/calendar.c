//put the documentation here

/*****************************************************************************
*                      PROG71985/ Group Project                              *
*                    Professor: Steve Hendrikse                              *
*                                                                            *
*		 BY:	 Michelle Novar, Saba Berenji, Sierra Erb                    *
*        DATE: 	 November,2022                                               *
* DESCRIPTION:                                     *
******************************************************************************/

#include "calendar.h"
#include "input.h"


PSTACK InitializeStack(PSTACK list)  //InitializeStack function definition
{
	list = NULL;  //Initialize the list to NULL and the return the list
	return list;
}


void AddTask(PSTACK* list, char titledata[], char descriptdata[])  //PushToSatck function definition, this function adds all the new nodes to the front of the list
{
	PSTACK newnode = NULL;
	//PSTACK previous;

	newnode = (PSTACK)malloc(sizeof(STACK));  //dynamically allocate memory

	if (newnode == NULL)  //if malloc returns NULL 
	{
		fprintf(stderr, "error allocating memory\n");  //error message if memory allocation is unsuccessful
		exit(EXIT_FAILURE);
	}

	if (isEmpty(&list))
	{
		newnode->taskdata.tasknumber = 1;
		*list = newnode; /* first structure */
	}

	else  /* subsequent structures */
		//previous->next = current;

	{
		newnode->next = NULL;
		newnode->taskdata.tasknumber++;
	}

	strcpy(newnode->taskdata.tasktitle, titledata);
	strcpy(newnode->taskdata.taskdescription, descriptdata);


	newnode->next = *list;

	*list = newnode;

	//int size = sizeof(newdata);
	//int length = size / sizeof(newdata[0]);

	//for (int i = 0; i < length; i++)
	//{
	//	current->data[i] = newdata[i];
	//}
	//previous = current;
	
	//puts("The task has been added to your task manager");
}


//void AddItem(PSTACK* list, int newInfo)   //may use this function instead
//{
//	PSTACK new_node = *list;
//
//	new_node = (PSTACK)malloc(sizeof(STACK));
//	if (!new_node)
//	{
//		fprintf(stderr, "error allocating memory\n");
//		exit(EXIT_FAILURE);
//	}
//	new_node->data = newInfo;
//	new_node->next = *list;
//
//	*list = new_node;
//}




void RemoveTask(PSTACK* list, char infoToBeDeleted[])   //should change it
{
	PSTACK current = *list;

	if (strcmp(current->taskdata.tasktitle, infoToBeDeleted) == 0)
	{
		if (current->next != NULL)  //info is in head.  and list is greater than 1 element
			*list = current->next;
		else   //i think that this is what should happen if there is only the single element (and we delete it)
			*list = NULL;

		free(current);
		puts("You deleted the task.");
		return;
	}

	PSTACK prev = current;  // we will need the previous node for to link over the deleted one
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


bool isEmpty(PSTACK* list)  //isEmpty function definition
{
	if (*list == NULL)  //return true if stack is empty
		return true;
	else
		return false;
}



//void Display(PSTACK list)
//{
//	PSTACK current = list;
//	if (!current)
//	{
//		puts("There are no tasks to display");
//		return;
//	}// list is empty, don't print!
//		;
//
//	do
//	{
//		printf("%s", current->data);
//		current = current->next;
//	} while (current != NULL);
//
//	printf("\n");
//}



void DisplayAll(PSTACK list)
{

	PSTACK current = list;
	if (isEmpty(list)) //!current)
	{
		puts("There are no tasks to display");
		return;
	}// list is empty, don't print!

	do
	{
		printf("Task number: %d\nTask title: %s\nTask description: %s\n", current->taskdata.tasknumber, current->taskdata.tasktitle, current->taskdata.taskdescription);
		current = current->next;
	} while (current != NULL);

	printf("\n");
}


void DisplaySingleTask(PSTACK list, char* infotodisplay[])
{
	PSTACK current = list;
	if (!current)
	{
		puts("There are no tasks to display");
		return;
	}// list is empty, don't print!

	do
	{
		if (strcmp(current->taskdata.tasktitle, infotodisplay) == 0)
			printf("Task number: %d\nTask title: %s\nTask description: %s\n", current->taskdata.tasknumber, current->taskdata.tasktitle, current->taskdata.taskdescription);
		current = current->next;
	} while (current != NULL);

	printf("\n");
}

void ValidateAndPrintRange(PSTACK list)
{
	PSTACK current = list;
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

void DisplayRange(PSTACK list, int firstnumber, int secondnumber)
{
	PSTACK current = list;
	for (int i = firstnumber; i <= secondnumber; i++)
	{
		puts("Task number: %d\nTask title: %s\nTask description: %s\n", current->taskdata.tasknumber, current->taskdata.tasktitle, current->taskdata.taskdescription);
	}
}










//
//
//void PopFromStack(PSTACK* list)  //PopFromStack funtion definition, this function removes the topmost element from the stack and returns its value
//{
//	PSTACK current = *list;
//	char info;
//
//	if (!isEmpty(current))  //if current is not empty
//	{
//		*list = current->link;
//		info = current->data;
//		free(current);  //remove current from stack
//	}
//}
//
//
