#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <unistd.h>
#include <termios.h>
#include<limits.h>
#include"library.h"
//#include"book_operation.h"
//#include"linkedlist.h"

#define MAX_LENGTH 100

int main(){
	sleep(0.5);
	cls1();
	//cls();
	
	main_menu:
	cls();
	int choice;
	struct termios term, term_orig;
	
	printf("\n\t\tMain Menu");
    printf("\n============================================");
    printf("\n\n1. Register\t2. Login\t3.  Admin Login \t 4. Quit");

	printf("\nEnter your Choice :");
	    // Save the current terminal settings
    tcgetattr(STDIN_FILENO, &term);
    term_orig = term;

    // Disable line buffering and input echoing
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);

    // Read a single character from the input
    choice = getchar();

    // Restore the original terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &term_orig);


	switch(choice){
		case '1':
			registeration();
			goto main_menu;
			break;
		case '2':
			studentLogin();
			goto main_menu;
			break;
		case '3':
			adminLogin();
			//exit(0);
			goto main_menu;
			break;
		case '4':
			printf("\n");
			exit(0);
			break;
		
		default:
			printf("\n\t\tInvalid Choice");
			cls();
			goto main_menu;
			break;
		}
    return 0;
}



// int main() {

//     int rowNumber;

//     printf("Enter the row number: ");
//     scanf("%d", &rowNumber);

// 	const char* filename = "userdb.csv";
//     int result = checkColumnsInRow(filename, rowNumber);

//     if (result == 0) {
//         printf("No data found in columns 6 to 9 of the specified row.\n");
//     } 
// 	else if (result == INT_MAX) {
//         printf("Column limit exceeded (beyond column 9).\n");
//     } 
// 	else {
//         printf("%d.\n", result);
//     }

//     return 0;
// }


