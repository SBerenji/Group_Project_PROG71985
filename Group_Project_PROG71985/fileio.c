/*#include "calendar.h" */ // delete later 
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