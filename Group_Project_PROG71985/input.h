#pragma once
/*****************************************************************************
*                      PROG71985/ Group Project                              *
*                    Professor: Steve Hendrikse                              *
*                                                                            *
*		 BY:	 Michelle Novar, Saba Berenji, Sierra Erb                    *
*        DATE: 	 December,2022                                               *
* DESCRIPTION:   The input header file of a user-friendly task manager       *
*                with a menu containing several options to add, remove,      *
*                display, and update the tasks                               *
******************************************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAXLEN 1000  //maximum number of characters the user can enter for the description

// what we're promising

void GetString(char str[], int max);  //GetString function prototype
char GetLetter(void);                //GetLetter function prototype
char menuinput(void);                //menuinput function prototype