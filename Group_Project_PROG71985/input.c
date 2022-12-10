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

//Saba authored this module
void GetString(char str[], int max)   //GetString function definition that gets the string from user
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

//
//void GetRange(int firstnumber, int secondnumber)
//{
//		int i = 0;
//		// int firstnumber = 0;
//		// int secondnumber = 0;
//
//		printf("Enter range ( eg. 1-5)\n");
//		printf("Enter minimum: ");
//		scanf_s("%d", &firstnumber);
//		printf("Enter maximum: ");
//		scanf_s("%d", &secondnumber);
//		printf("All characters in range %d to %d are:\n", firstnumber, secondnumber);
//		for (i = firstnumber; i <= secondnumber; ++i)
//		{
//			printf("%d\n", i);
//		}
//		// return 0;
//
//}


//Saba authored this module
char GetLetter(void) //menuinput function definition
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

//Saba authored this module
char menuinput(void) //menuinput function definition
{
	char option;

	if (scanf(" %c", &option) == 1)  //get user input
	{
		while ((getchar()) != '\n');  //discard the newline character
	}
	return option;

}