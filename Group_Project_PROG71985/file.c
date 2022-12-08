/*#include "calendar.h" */ // delete later 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  // delete later
#include <stdbool.h>
#include "input.h"
#include "menu.h"
#include "task.h"


//
//
// // file io  one way
//
//void saveToDisk(TASK); // for .h file 
//void readFromDisk(TASK);  // for .h file
//
//void saveToDisk(TASK list) // save tasks
//{
//	FILE* database;
//
//	if ((database = fopen("appt.txt", "wb")) == NULL)
//	{
//		printf(stderr, "Cannot create a file");
//	}
//
//	TASK taskdata = list;
//	while (taskdata) != NULL)
//	{
//	fprintf(database, "%s\n", taskdata->tasknumber);  // from struct task - taskdata was listHead before
//	fprintf(database, "%s\n", taskdata->tasktitle);
//	fprintf(database, "%d\n", taskdata->taskdescription);
//	taskdata = taskdata->next;
//	}
//	fclose(database);
//}
//
//void readFromDisk(TASK list)
//{
//	int temptasknumber;
//	char temptasktitle[TITLE];
//	char temptaskdescription[MAXLEN];
//
//	TASK taskdata = NULL;
//	FILE* loadFile;
//
//	if ((loadFile = fopen("appt.txt", "rb")) == NULL)
//	{
//		printf(stderr, "Cannot create a file");
//		exit(EXIT_FAILURE);
//	}
//
//	for (int i = 0; i != EOF; i++)
//	{
//		fgets(temptasknumber, loadFile);
//		fgets(temptasktitle, TITLE, loadFile);
//		fgets(temptaskdescription, MAXLEN, loadFile);
//		int temptasknumber = atoi(temp);
//
//		taskdata = AddAppt(temptasknumber, temptasktitle, temptaskdescription);
//		// list = AddAppt(list, taskdata);
//		list = (PSTACK * list; char* newdata[]);
//	}
//
//	fclose(loadFile);
//}
//
//
////bool CompareAppt(PSTACK, PSTACK);  // for .h file                                                                   // compare appt
////
////bool CompareAppt(PSTACK list, PSTACK data) // for .c file compare files for remove etc
////{
////    if (list.type == data.type)   // this compares the list to data
////        return true;
////    else
////        return false;
////}
////
//
//
//
//
//// file io the other way using arguments 
//
//
////count.c -- using standard I/O - week 6 ex 6
////using standard I/O 
////
////#define _CRT_SECURE_NO_WARNINGS  
////
////#include <stdio.h> 
////#include <stdlib.h> 
////#include <string.h> 
////
////#define BUFFERSIZE      100 
//
////int main(int argc, char* argv[])
////{
////    unsigned char  buffer[BUFFERSIZE];
////    FILE* fpRead;
////    FILE* fpWrite;
////
////    if (argc != 4)          // command line parameter - takes 3 items
////    {
////        fprintf(stderr, "Usage: %s source destination\n", argv[0]);
////        exit(EXIT_FAILURE);
////    }
////
////    if ((fpRead = fopen(argv[1], "rb")) == NULL)                        // rb not r    
////    {
////        fprintf(stderr, "Can't open %s for reading\n", argv[1]);        // 2???
////        exit(EXIT_FAILURE);
////    }
////
////    if ((fpWrite = fopen(argv[2], "wb")) == NULL)                        // wb not w    
////    {
////        fprintf(stderr, "Can't open %s for writing\n", argv[2]);        //
////        exit(EXIT_FAILURE);
////    }
////
////    int numItemsRead = 0;
////    do
////    {
////        numItemsRead = fread(&buffer, sizeof(unsigned char), BUFFERSIZE, fpRead);
////        fwrite(&buffer, sizeof(unsigned char), numItemsRead, fpWrite);
////    } while (numItemsRead == BUFFERSIZE);
////
////    fclose(fpRead);
////    fclose(fpWrite);
////}
//
//
//
//
//
///*#include "calendar.h" */ // delete later 
//#include <stdio.h>  // delete later
//#include <stdbool.h>
////#include "input.h"
////#include "menu.h"
//
//
//
//
// // file io  one way
//
//void saveToDisk(TASK); // for .h file 
//void readFromDisk(TASK);  // for .h file
//
//void saveToDisk(TASK list) // save tasks
//{
//	FILE* database;
//
//	if ((database = fopen("appt.txt", "wb")) == NULL)
//	{
//		printf(stderr, "Cannot create a file");
//	}
//
//	TASK taskdata = list;
//	while (taskdata) != NULL)
//	{
//	fprintf(database, "%s\n", taskdata->tasknumber);  // from struct task - taskdata was listHead before
//	fprintf(database, "%s\n", taskdata->tasktitle);
//	fprintf(database, "%d\n", taskdata->taskdescription);
//	taskdata = taskdata->next;
//	}
//	fclose(database);
//}
//
//void readFromDisk(TASK list)
//{
//	int temptasknumber;
//	char temptasktitle[TITLE];
//	char temptaskdescription[MAXLEN];
//
//	TASK taskdata = NULL;
//	FILE* loadFile;
//
//	if ((loadFile = fopen("appt.txt", "rb")) == NULL)
//	{
//		printf(stderr, "Cannot create a file");
//		exit(EXIT_FAILURE);
//	}
//
//	for (int i = 0; i != EOF; i++)
//	{
//		fgets(temptasknumber, loadFile);
//		fgets(temptasktitle, TITLE, loadFile);
//		fgets(temptaskdescription, MAXLEN, loadFile);
//		int temptasknumber = atoi(temp);
//
//		taskdata = AddAppt(temptasknumber, temptasktitle, temptaskdescription);
//		// list = AddAppt(list, taskdata);
//		list = (PSTACK * list; char* newdata[]);
//	}
//
//	fclose(loadFile);
//}
//
//
////bool CompareAppt(PSTACK, PSTACK);  // for .h file                                                                   // compare appt
////
////bool CompareAppt(PSTACK list, PSTACK data) // for .c file compare files for remove etc
////{
////    if (list.type == data.type)   // this compares the list to data
////        return true;
////    else
////        return false;
////}
////
//
//
//
//
//// file io the other way using arguments 
//
//
////count.c -- using standard I/O - week 6 ex 6
////using standard I/O 
////
////#define _CRT_SECURE_NO_WARNINGS  
////
////#include <stdio.h> 
////#include <stdlib.h> 
////#include <string.h> 
////
////#define BUFFERSIZE      100 
//
////int main(int argc, char* argv[])
////{
////    unsigned char  buffer[BUFFERSIZE];
////    FILE* fpRead;
////    FILE* fpWrite;
////
////    if (argc != 4)          // command line parameter - takes 3 items
////    {
////        fprintf(stderr, "Usage: %s source destination\n", argv[0]);
////        exit(EXIT_FAILURE);
////    }
////
////    if ((fpRead = fopen(argv[1], "rb")) == NULL)                        // rb not r    
////    {
////        fprintf(stderr, "Can't open %s for reading\n", argv[1]);        // 2???
////        exit(EXIT_FAILURE);
////    }
////
////    if ((fpWrite = fopen(argv[2], "wb")) == NULL)                        // wb not w    
////    {
////        fprintf(stderr, "Can't open %s for writing\n", argv[2]);        //
////        exit(EXIT_FAILURE);
////    }
////
////    int numItemsRead = 0;
////    do
////    {
////        numItemsRead = fread(&buffer, sizeof(unsigned char), BUFFERSIZE, fpRead);
////        fwrite(&buffer, sizeof(unsigned char), numItemsRead, fpWrite);
////    } while (numItemsRead == BUFFERSIZE);
////
////    fclose(fpRead);
////    fclose(fpWrite);
////}



// count.c -- using standard I/O - week 6 ex 6, steve's code 
// using standard I/O 
// 
//#define _CRT_SECURE_NO_WARNINGS  
// 
//#include <stdio.h> 
//#include <stdlib.h> 
//#include <string.h> 
// 
//#define BUFFERSIZE      100 
// 
//int main(int argc, char* argv[]) 
//{ 
//    unsigned char  buffer[BUFFERSIZE]; 
//    FILE* fpRead; 
//    FILE* fpWrite; 
// 
//    if (argc != 3)          // ** I set command line parameters in project properties. 
//    { 
//        fprintf(stderr, "Usage: %s source destination\n", argv[0]); 
//        exit(EXIT_FAILURE); 
//    } 
// 
//    if ((fpRead = fopen(argv[1], "rb")) == NULL)                        // ** Open as binary! 
//    { 
//        fprintf(stderr, "Can't open %s for reading\n", argv[1]); 
//        exit(EXIT_FAILURE); 
//    } 
// 
//    if ((fpWrite = fopen(argv[2], "wb")) == NULL)                        // ** Open as binary! 
//    { 
//        fprintf(stderr, "Can't open %s for writing\n", argv[2]); 
//        exit(EXIT_FAILURE); 
//    } 
// 
//    int numItemsRead = 0; 
//    do 
//    { 
//        numItemsRead = fread(&buffer, sizeof(unsigned char), BUFFERSIZE, fpRead); 
//        fwrite(&buffer, sizeof(unsigned char), numItemsRead, fpWrite); 
//    } while (numItemsRead == BUFFERSIZE); 
// 
//    fclose(fpRead); 
//    fclose(fpWrite); 
//} 









/////SABA ADDED



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
				return 0;

		} while (filep != EOF);

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


