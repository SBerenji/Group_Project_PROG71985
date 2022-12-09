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

typedef struct task
{
	char tasktitle[TITLE];
	char taskdescription[MAXLEN];
} TASK;


typedef struct listnode
{
	TASK taskdata;
	struct stack* next;
} LISTNODE, * PLISTNODE;



void menu(void);
char menuinput(void);




/* operation:       initialize the stack                       */
/* precondition:    list points to a stack                     */
/* postcondition:   stack is initialized to being empty (NULL) */
PLISTNODE InitializeStack(PLISTNODE list);  //InitializeStack function prototype


/* operation:       push the item onto top of stack                  */
/* precondition:    list points to the previously initialized stack  */
/*                  item is to be placed on top of stack             */
void AddTask(PLISTNODE* list, char titledata[], char descriptdata[]); //PushToSatck function prototype


/* operation:       remove item from top of the stack                    */
/* precondition:    list points to previously initialized stack          */
/* postcondition:   if stack is not empty, item at top of                */
/*                  stack is copied to a char variabel and deleted from  */
/*                  stack                                                */

//void PopFromStack(PSTACK* list);  //PopFromStack function prototype
void RemoveTask(PLISTNODE* list);
//
/////* operation:       check if stack is empty                       */
/////* precondition:    list points to previously initialized stack   */
/////* postcondition:   returns True if stack is empty, else False    */
bool isEmpty(PLISTNODE* list);


//void Display(PSTACK list);


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