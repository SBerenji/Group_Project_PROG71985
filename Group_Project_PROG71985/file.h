#pragma once

/*****************************************************************************
*                      PROG71985/ Group Project                              *
*                    Professor: Steve Hendrikse                              *
*                                                                            *
*		 BY:	 Michelle Novar, Saba Berenji, Sierra Erb                    *
*        DATE: 	 December,2022                                               *
* DESCRIPTION:   The file io header file of a  user-friendly task manager    *
*                with a menu containing several options to add, remove,      *
*                display, and update the tasks                               *
******************************************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdbool.h>
#include <stdlib.h>
#include "input.h"
#include "menu.h"
#include "task.h"



// what we're promising 
void WriteFile(PLISTNODE* list);  //WriteFile function prototype
void ReadFile(PLISTNODE* list);   //ReadFile function prototype

