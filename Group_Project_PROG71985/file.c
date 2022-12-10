
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
#include <stdbool.h>
#include "menu.h"
#include "task.h"
#include "input.h"
#include "file.h"

void ReadFile(PLISTNODE* list) //ReadFile function definition. Used to read the file created and update the program with its data
{
	FILE* filep;  //file pointer

	size_t size = sizeof(TASK);

	if ((filep = fopen("TaskList.txt", "rb")) == NULL)
	{
		puts("No file to read from");
		return;
	}
	else
	{
		do 
		{
			PLISTNODE newnode = NULL;
			newnode = (PLISTNODE)malloc(sizeof(LISTNODE));  //dynamically allocate memory

			if (newnode == NULL)  //if malloc returns NULL 
			{
				fprintf(stderr, "error allocating memory\n");  //error message if memory allocation is unsuccessful
				exit(EXIT_FAILURE);
			}

			if (list == NULL)
				list = newnode; /* first structure */

			else
			{
				newnode->next = NULL;

			}

			if (fread(newnode, size, 1, filep) == 1)
			{
				newnode->next = *list;
				*list = newnode;
			}
			else
				return;

		} while (&filep != EOF);

		fclose(filep);  //close the file
	}

}

void WriteFile(PLISTNODE* list)  //WriteFile function definition. Updates the file created after the user tries to exit the program
{
	FILE* filep;  //file pointer
	PLISTNODE current = *list;
	size_t size = sizeof(TASK);

	if ((filep = fopen("TaskList.txt", "wb")) == NULL)
	{
		puts("The data cannot be saved");   //gets displayed if the file cannot be created and then exits the program
		exit(EXIT_FAILURE);
	}
	else   //if the file can be created writes the information to the file
	{

		int number = TaskCount(*list);
		if (number > 0)
		{
			do
			{
				fwrite(current, size, 1, filep); //writing to the file
				current = current->next;
			}
			while (current != NULL);
			
		}
		else
			printf("No info to add");
	

		puts("All the information has been saved");
		fclose(filep);  //close the file
	}
}


