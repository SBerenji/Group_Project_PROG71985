#pragma once
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


#include <stdio.h>  
#include <stdbool.h>
#include "input.h"
#include "menu.h"
#include "task.h"

#include <stdlib.h>

// what we're promising 
void WriteFile(PLISTNODE* list);
void ReadFile(PLISTNODE* list);

