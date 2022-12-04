
/*****************************************************************************
*                      PROG71985/ Group Project                              *
*                    Professor: Steve Hendrikse                              *
*                                                                            *
*		 BY:	 Michelle Novar, Saba Berenji, Sierra Erb                    *
*        DATE: 	 November,2022                                               *
* DESCRIPTION:                                      *
******************************************************************************/

#include "menu.h"


void menu(void)  //menu function definition which prints out the menu options
{
	puts("\nPlease choose from the menu below:");
	puts("a) Add a new task");
	puts("b) Delete an existing task");
	puts("c) Update an existing task ");
	puts("d) Display single task");
	puts("e) Display range task");
	puts("f) Display all task");
	puts("g) Search for task");
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
