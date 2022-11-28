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


void menu(void)  //menu function definition which prints out the menu options
{
	puts("\nPlease choose from the menu below:");
	puts("a) Add a new appt");
	puts("b) Delete an existing appt");
	puts("c) Update an existing appt ");
	puts("d) Display single appt");
	puts("e) Display range appt");
	puts("f) Display all appt");
	puts("g) Search for appt");
	puts("h) QUIT \n");
		
}

char menuinput(void) //menuinput function definition
{
	char option;
	menu();  //calling the menu function

	if (scanf(" %c", &option) == 1)  //get user input
	{
		while ((getchar()) != '\n');  //discard the newline character
	}
	return option;
	
}





PSTACK InitializeStack(PSTACK list)  //InitializeStack function definition
{
	list = NULL;  //Initialize the list to NULL and the return the list
	return list;
}




void AddAppt(PSTACK* list, char* newdata[])  //PushToSatck function definition, this function adds all the new nodes to the front of the list
{
	PSTACK newnode = *list;
	//PSTACK previous;

	newnode = (PSTACK)malloc(sizeof(STACK));  //dynamically allocate memory

	if (newnode == NULL)  //if malloc returns NULL 
	{
		fprintf(stderr, "error allocating memory\n");  //error message if memory allocation is unsuccessful
		exit(EXIT_FAILURE);
	}

	if (isEmpty(list) )
		*list = newnode; /* first structure */

	else  /* subsequent structures */
		//previous->next = current;

	{
		newnode->next = NULL;
	}

	strcpy(newnode->data, newdata);

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




void RemoveItem(PSTACK* list, char infoToBeDeleted[])   //should change it
{
	PSTACK current = *list;

	if (strcmp(current->data, infoToBeDeleted) == 0)
	{
		if (current->next != NULL)  //info is in head.  and list is greater than 1 element
			*list = current->next;
		else   //i think that this is what should happen if there is only the single element (and we delete it)
			*list = NULL;

		free(current);
		return;
	}

	PSTACK prev = current;  // we will need the previous node for to link over the deleted one
	while (current != NULL && current->data != infoToBeDeleted)
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
}


bool isEmpty(PSTACK* list)  //isEmpty function definition
{
	if (*list == NULL)  //return true if stack is empty
		return true;
	else
		return false;
}


void GetString(char* str, int max)   //GetString function definition that gets the string from user
{                                    //No validation included as the instruction asked for string (a sequence of characters)
									//and did not ask for a certain kind of string like a name

	if (fgets(str, max, stdin) != NULL)
	{

		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] == '\n')
				str[i] = '\0';
		}
	}
}



void Display(PSTACK list)
{
	PSTACK current = list;
	if (!current)
	{
		puts("There are no tasks to display");
		return;
	}// list is empty, don't print!
		;

	do
	{
		printf("%s", current->data);
		current = current->next;
	} while (current != NULL);

	printf("\n");
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
