
/*****************************************************************************
*                      PROG71985/ Group Project                              *
*                    Professor: Steve Hendrikse                              *
*                                                                            *
*		 BY:	 Michelle Novar, Saba Berenji, Sierra Erb                    *
*        DATE: 	 December,2022                                               *
* DESCRIPTION:   A user-friendly task manager with a menu containing several *
*                options to add, remove, display, and update the tasks       *
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
	puts("i) Display last task on the list");
	puts("j) Display the task list in alphabetical order");
	puts("k) QUIT \n");
	printf("------------------------------------------\n");

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
