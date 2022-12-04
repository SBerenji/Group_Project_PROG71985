/*****************************************************************************
*                      PROG71985/ Group Project                              *
*                    Professor: Steve Hendrikse                              *
*                                                                            *
*		 BY:	 Michelle Novar, Saba Berenji, Sierra Erb                    *
*        DATE: 	 November,2022                                               *
* DESCRIPTION:                                     *
******************************************************************************/

#include "menu.h"
#include "calendar.h"


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


void GetRange(int firstnumber, int secondnumber)
{
	while (scanf_s("%d %d", &firstnumber, &secondnumber) == 2)
	{
		if (firstnumber > secondnumber)
		{
			Swaps(&firstnumber, &secondnumber);
		}
	}
}