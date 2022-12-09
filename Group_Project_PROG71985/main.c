//put the documentation here

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
#include "menu.h"
#include "input.h"
#include "file.h"


int main(void)
{

	PLISTNODE list = InitializeStack(&list);

	ReadFile(&list);  //read from the file

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
			RangeTask(list);
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

	WriteFile(&list);

	return 0;
}
