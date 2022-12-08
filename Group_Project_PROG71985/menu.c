
/*****************************************************************************
*                      PROG71985/ Group Project                              *
*                    Professor: Steve Hendrikse                              *
*                                                                            *
*		 BY:	 Michelle Novar, Saba Berenji, Sierra Erb                    *
*        DATE: 	 November,2022                                               *
*		 DESCRIPTION:													     *
******************************************************************************/

#include "menu.h"


void menu(void)  //menu function definition which prints out the menu options
{
	printf("------------------------------------------\n");
	puts("\nPlease choose from the menu below:");
	puts("a) Add a new task");
	puts("b) Delete an existing task");
	puts("c) Update an existing task ");
	puts("d) Display single task");
	puts("e) Display range task");
	puts("f) Display all task");
	puts("g) Search for task");
	puts("h) Number of items on the list");
	puts("i) QUIT \n");
	printf("------------------------------------------\n");

}

char menuinput(void) //menuinput function definition
{
	char option;
  //calling the menu function

	if (scanf(" %c", &option) == 1)  //get user input
	{
		while ((getchar()) != '\n');  //discard the newline character
	}
	return option;

}

void UpdateMenu(void)
{
	printf("------------------------------------------\n");
	puts("How would you like to update this task. Choose from the menu below:");
	printf("a) Update task title\n");
	printf("b) Update description of task\n");
	printf("c) Return to main menu\n");
	printf("------------------------------------------\n");
}
