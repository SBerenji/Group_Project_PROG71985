//put the documentation here

/*****************************************************************************
*                      PROG71985/ Group Project                              *
*                    Professor: Steve Hendrikse                              *
*                                                                            *
*		 BY:	 Michelle Novar, Saba Berenji, Sierra Erb                    *
*        DATE: 	 November,2022                                               *
* DESCRIPTION:                                     *
******************************************************************************/

#include "calendar.h"


int main(void)
{
	PSTACK head = InitializeStack(&head);
	PSTACK current;

	char choice;
	char string[MAXLEN];

	
	while ((choice = menuinput()) != 'h')  //call the menuinput function and exit the loop if the input is 'f'
	{

		switch (choice)  //using switch case statement for the menu options
		{
		case 'a':
			puts("Pleases enter your new task");
			GetString(string, MAXLEN);
			current = AddAppt(&head, string);
			printf("This is what you entered: %s", current->data);
			
			/*if (isEmpty(&head))
				puts("Yes it is empty");
			else
				puts("no it is not empty");*/
			break;

		case 'b':
			puts("How");
			break;

		case 'c':
			puts("Are");
			break;

		case 'd':
			puts("You");
			break;

		case 'e':
			puts("!");
			break;
		
		case 'f':
			puts("hehe");
			break;
		
		case 'g':
			puts("lol");
			break;

		default:
			puts("\nInvalid input!");  //print when the user chooses an invalid option from the menu
			puts("Please try again.");

		}
	}
	//PSTACK list = InitializeStack(&list);  //Initialize the list;
	//char tempstr[MAXLEN];
	//char character;

	//puts("Please enter a string: ");
	//GetString(tempstr, MAXLEN);  //get user input

	//for (int i = 0; i < strlen(tempstr); i++)
	//{
	//	PushToSatck(&list, tempstr[i]);  //push the string character by character to the stack
	//}

	//puts("The string in reverse order:");

	//for (int i = 0; i < strlen(tempstr); i++)
	//{
	//	character = PopFromStack(&list);
	//	printf("%c", character); //Display the characters one by one resulting in the reverse display of the string 
	//}

	//printf("\n");

	return 0;
}
