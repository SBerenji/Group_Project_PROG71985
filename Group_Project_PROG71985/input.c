#define _CRT_SECURE_NO_WARNINGS
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
#include "task.h"
#include "input.h"
#include "file.h"


void GetString(char str[], int max)   //GetString function definition that gets the string from user
{                                    //No validation included as it is being used for a task manager

	if (fgets(str, max, stdin) != NULL)
	{

		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] == '\n')
				str[i] = '\0';
		}
	}
}


char GetLetter(void) //GetLetter function definition
{
	char option;


	if ((scanf("%c", &option) != 1) || ((option < 'A' || option < 'a' && option > 'Z') || option > 'z'))
	{
		puts("Invalid input");
		return 0;
	}

	while ((getchar()) != '\n');  //discard the newline character

	return option;

}

char menuinput(void) //menuinput function definition
{
	char option;

	if (scanf(" %c", &option) == 1)  //get user input
	{
		while ((getchar()) != '\n');  //discard the newline character
	}
	return option;

}