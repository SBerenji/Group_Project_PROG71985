/*****************************************************************************
*                      PROG71985/ Group Project                              *
*                    Professor: Steve Hendrikse                              *
*                                                                            *
*		 BY:	 Michelle Novar, Saba Berenji, Sierra Erb                    *
*        DATE: 	 December,2022                                               *
* DESCRIPTION:   The main source file of a user-friendly task manager        *
*                with a menu containing several options to add, remove,      *
*                display, and update the tasks                               *
******************************************************************************/

#include "task.h"
#include "menu.h"
#include "input.h"
#include "file.h"


int main(void)
{

	PLISTNODE list = InitializeStack(&list);  //initializing the list

	ReadFile(&list);  //read from the file (if there is any info saved)

	char choice;
	char title[TITLE];
	char desc[MAXLEN];
	int count;

	menu();
	while ((choice = menuinput()) != 'j')  //call the menuinput function and exit the loop if the input is 'j'
	{

		switch (choice)  //using switch case statement for the menu options
		{
		case 'a':
			puts("Please enter a single-word title for your task eg. gym");
			GetString(title, TITLE);  //get the task title from the user
			puts("Now please enter the description of your task:");   
			GetString(desc, MAXLEN);   //get the task description from the user
			AddTask(&list, title, desc);  //add the inormation to the list using AddTask function
			break;

		case 'b':
			RemoveTask(&list);
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

		default:
			puts("\nInvalid input!");  //print when the user chooses an invalid option from the menu
			puts("Please try again.");

		}
		menu();
	}

	WriteFile(&list);  //write the information to a file

	return 0;
}
