#pragma once
/*****************************************************************************
*                      PROG71985/ Group Project                              *
*                    Professor: Steve Hendrikse                              *
*                                                                            *
*		 BY:	 Michelle Novar, Saba Berenji, Sierra Erb                    *
*        DATE: 	 December,2022                                               *
* DESCRIPTION:   The task header file of a user-friendly task manager        *
*                with a menu containing several options to add, remove,      *
*                display, and update the tasks                               *
******************************************************************************/



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAXLEN 1000  //maximum number of characters the user can enter
#define TITLE  20


// what we're promising

typedef struct task   
{
	char tasktitle[TITLE];
	char taskdescription[MAXLEN];
} TASK;


typedef struct listnode
{
	TASK taskdata;
	struct listnode* next;
} LISTNODE, * PLISTNODE;


PLISTNODE InitializeStack(PLISTNODE list);  //InitializeStack function prototype
void AddTask(PLISTNODE* list, char titledata[], char descriptdata[]); //AddTask function prototype
void RemoveTask(PLISTNODE* list); //RemoveTask function prototype
bool isEmpty(PLISTNODE* list);  //isEmpty function prototype
void DisplayAll(PLISTNODE list);   //DisplayAll function prototype
void DisplaySingleTask(PLISTNODE list);    //DisplaySingleTask function prototype
void UpdateTask(PLISTNODE* list);    //UpdateTask function prototype
void SelectWhatToUpdate(PLISTNODE current);  //SelectWhatToUpdate function prototype
int TaskCount(PLISTNODE list);   //TaskCount function prototype
void PrintTaskCount(int count);  //PrintTaskCount function prototype
void SearchForTask(PLISTNODE list);  //SearchForTask function prototype
void RangeTask(PLISTNODE list);   //RangeTask function prototype
void LastItem(PLISTNODE list);   //LastItem function prototype
 
