#pragma once
/*****************************************************************************
*                      PROG71985/ Group Project                              *
*                    Professor: Steve Hendrikse                              *
*                                                                            *
*		 BY:	 Michelle Novar, Saba Berenji, Sierra Erb                    *
*        DATE: 	 November,2022                                               *
* DESCRIPTION:                                      *
******************************************************************************/



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAXLEN 1000  //maximum number of characters the user can enter


typedef struct stack
{
	char data[MAXLEN];
	struct stack* next;
} STACK, * PSTACK;




void menu(void);
char menuinput(void);




/* operation:       initialize the stack                       */
/* precondition:    list points to a stack                     */
/* postcondition:   stack is initialized to being empty (NULL) */
PSTACK InitializeStack(PSTACK list);  //InitializeStack function prototype


/* operation:       push the item onto top of stack                  */
/* precondition:    list points to the previously initialized stack  */
/*                  item is to be placed on top of stack             */
PSTACK AddAppt(PSTACK* list, char* newdata[]); //PushToSatck function prototype


/* operation:       remove item from top of the stack                    */
/* precondition:    list points to previously initialized stack          */
/* postcondition:   if stack is not empty, item at top of                */
/*                  stack is copied to a char variabel and deleted from  */
/*                  stack                                                */

//void PopFromStack(PSTACK* list);  //PopFromStack function prototype
//
/////* operation:       check if stack is empty                       */
/////* precondition:    list points to previously initialized stack   */
/////* postcondition:   returns True if stack is empty, else False    */
bool isEmpty(PSTACK* list);




void GetString(char* str, int max);  //GetString function prototype