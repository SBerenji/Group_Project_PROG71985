//put the documentation here

/*****************************************************************************
*                      PROG71985/ Group Project                              *
*                    Professor: Steve Hendrikse                              *
*                                                                            *
*		 BY:	 Michelle Novar, Saba Berenji, Sierra Erb                    *
*        DATE: 	 November,2022                                               *
* DESCRIPTION:                                     *
******************************************************************************/

#include "task.h"
#include "menu.h"
#include "input.h"
#include "file.h"


int main(void)
{

	PLISTNODE list = InitializeStack(&list);
	//PSTACK current;
	ReadFile(&list);

	char choice;
	char title[TITLE];
	char desc[MAXLEN];
	int count;

	menu();
	while ((choice = menuinput()) != 'k')  //call the menuinput function and exit the loop if the input is 'f'
	{

		switch (choice)  //using switch case statement for the menu options
		{
		case 'a':
			puts("Please enter a single-word title for your task eg. gym");
			GetString(title, TITLE);
			puts("Now please enter the description of your task:");
			GetString(desc, MAXLEN);
			AddTask(&list, title, desc);
			break;
			
		case 'b':
			RemoveTask(&list, TITLE);
			break;

		case 'c':
			UpdateTask(&list);
			break;

		case 'd':
			DisplaySingleTask(list);
			break;
		case 'e':
			puts("Select range of tasks you want to display (eg. Task 1-5): ");
			ValidateAndPrintRange(list);
			break;
		case 'f':
			DisplayAll(list);
			break;
		
		case 'g':
			SearchForTask(list);
			break;
		
		case 'h':
			count = TaskCount(list);
			PrintTaskCount(count);
			break;
		case 'i':
			LastItem(list);
			break;
		case 'j':
			//AlphabeticalList(&list);
			break;
		default:
			puts("\nInvalid input!");  //print when the user chooses an invalid option from the menu
			puts("Please try again.");

		}
		menu();
	}


	if (isEmpty(&list))
		puts("Yes it is empty");
	else
		puts("no it is not empty");

	WriteFile(&list);

	return 0;
}
