#pragma once

/*****************************************************************************
*                      PROG71985/ Group Project                              *
*                    Professor: Steve Hendrikse                              *
*                                                                            *
*		 BY:	 Michelle Novar, Saba Berenji, Sierra Erb                    *
*        DATE: 	 December,2022                                               *
* DESCRIPTION:   A user-friendly task manager with a menu containing several *
*                options to add, remove, display, and update the tasks       *
******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#define MAXLEN 1000  //maximum number of characters the user can enter

// what we're promising

void GetString(char str[], int max);

//void GetRange(int firstnumber, int secondnumber);

char GetLetter(void);

char menuinput(void);