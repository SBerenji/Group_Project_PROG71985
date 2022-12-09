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
void AddTask(PLISTNODE* list, char titledata[], char descriptdata[]); //PushToSatck function prototype
void RemoveTask(PLISTNODE* list); 
bool isEmpty(PLISTNODE* list);
void DisplayAll(PLISTNODE list);
void DisplaySingleTask(PLISTNODE list);/*

void ValidateAndPrintRange(PLISTNODE list);

void DisplayRange(PLISTNODE list, int minimum, int maximum);

void Swaps(int* firstnumber, int* secondnumber);*/

void UpdateTask(PLISTNODE* list);
void SelectWhatToUpdate(PLISTNODE current);
int TaskCount(PLISTNODE list);
void PrintTaskCount(int count);
void SearchForTask(PLISTNODE list);
void RangeTask(PLISTNODE list);

void LastItem(PLISTNODE list);
