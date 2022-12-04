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
#include "menu.h"
#include "input.h"


int main(void)
{
	PSTACK list = InitializeStack(&list);
	//PSTACK current;

	char choice;
	char title[TITLE];
	char desc[MAXLEN];

	
	while ((choice = menuinput()) != 'h')  //call the menuinput function and exit the loop if the input is 'f'
	{

		switch (choice)  //using switch case statement for the menu options
		{
		case 'a':
			puts("Pleases enter a single-word title for your task e.g Gym'");
			GetString(title, TITLE);
			puts("Now please enter the description of your task:");
			GetString(desc, MAXLEN);
			AddTask(&list, title, desc);

			printf("This is what you entered\nTitle: %s\nDescription: %s\nTask number: %d", 
				&list->taskdata.tasktitle, &list->taskdata.taskdescription, &list->taskdata.tasknumber);
			
			if (isEmpty(&list))
				puts("Yes it is empty");
			else
				puts("no it is not empty");
			break;
			
		case 'b':
			puts("Pleases enter the title of the task you want to delete");
			GetString(title, MAXLEN);
			RemoveTask(&list, title);
			if (isEmpty(&list))
				puts("Yes it is empty");
			else
				puts("no it is not empty");
			break;

		case 'c':

			break;

		case 'd':
			puts("Select which task you want to display by entering its title: ");
			GetString(title, MAXLEN);
			DisplaySingleTask(list, title);
			break;
		case 'e':
			puts("Select range of tasks you want to display (eg. Task 1-5): ");
			ValidateAndPrintRange(list);
			break;
		case 'f':
			puts("Here are all your tasks:");
			DisplayAll(list);
			break;
		
		case 'g':
			break;

		default:
			puts("\nInvalid input!");  //print when the user chooses an invalid option from the menu
			puts("Please try again.");

		}
	}
	//PSTACK list = InitializeStack(&list);  //Initialize the list;
	//char tempstr[MAXLEN];
	//char character;

	//puts("Please enter a string: ");
	//GetString(tempstr, MAXLEN);  //get user input

	//for (int i = 0; i < strlen(tempstr); i++)
	//{
	//	PushToSatck(&list, tempstr[i]);  //push the string character by character to the stack
	//}

	//puts("The string in reverse order:");

	//for (int i = 0; i < strlen(tempstr); i++)
	//{
	//	character = PopFromStack(&list);
	//	printf("%c", character); //Display the characters one by one resulting in the reverse display of the string 
	//}

	//printf("\n");

	free(list);

	if (isEmpty(&list))
		puts("Yes it is empty");
	else
		puts("no it is not empty");

	return 0;
}
