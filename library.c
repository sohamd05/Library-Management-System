#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include <termios.h>
#include<ctype.h>
#include"library.h"
#include"linkedlist.h"
#include"book_operation.h"

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_LINE_LENGTH 1000

void cls(){
    system("clear");
	//sleep(1);
    printf("\n\t\t\t\tLibrary Management System\t\t\t\t\n");
    printf("\n################################################################################\n\n");

}
void cls1(){
    system("clear");
	sleep(1);
    printf("\n\t\t\t\tINITIALIZING PROTOCOL...Please Wait....\t\t\t\t\n");
	sleep(2);
   return;
}
int isNumber(char ch){
    	int digit = ch - '0';
    	if (digit >=0 && digit <=9){
        	return 1;
    	}
    	else
    		return 0;
}

void registeration(){
	user regis;
	int x,y;
	//FILE *ptr ;
	const char* filename = "userdb.csv";
    	char arr[120], arr2[9], ch, pass[10];
    	//putting NULL to avoid garbage

    	for(x=0;x<20;x++){
    	
        	regis.reg[x%8]='\0';
        	regis.password[x%10]='\0';
        	regis.fname[x]='\0';
        	regis.mname[x]='\0';
        	regis.lname[x]='\0';
        	//regis.pass[x%10]='\0';
    	}
	//we could issue atmost 4 books at a time...and can issue 11 books in total;
    	for(x=0;x<4;x++){  
        	for(y=0;y<10;y++){  
            		regis.issue[x][y]='\0';
        	}
    	}
    	
    	//main registration...
    	cls();
    	printf("\nUser Registration");
    	printf("\n====================\nPlease enter Q or q to Quit\n");
    	
		regNo:
    	char regs[9];
    	printf("\nEnter the registration number: ");
    	scanf("%s",regs);

		if(regs[0] == 'q' || regs[0] == 'Q'){
				//main();
				return ;
		}

		strcpy(regis.reg,regs);
		if((searchCSV(filename,regis.reg))==1){
			printf("\nThis Registration already exists , please Enter again!!\n");
			goto regNo;
		}
    	
    	paSS:
    	char Pass[10],Pass1[10];
    	printf("Enter your Password: ");
    	scanf("%s",Pass);
    	
    	printf("Enter your Password again : ");
    	scanf("%s",Pass1);
    	
        if(strcmp(Pass,Pass1)!=0){
            printf("\nPasswords do not match!!\n");
            goto paSS;
        }
    	
    	printf("\n");
    	//password is same
    	for(int z = 0 ; z <= 10 ; z++){
    		regis.password[z] = Pass[z];
    	}

    	//move forward to take name
    	printf("Please Enter your first name: ");
    	scanf("%s",regis.fname);
    	
    	if(regis.fname[0] == 'q' || regis.fname[0] == 'Q'){
    		return;
    	}
    	
    	printf("Please Enter your middle name: ");
    	scanf("%s",regis.mname);
    	
    	if(regis.mname[0] == 'q' || regis.mname[0] == 'Q'){
    		return;
    	}
    	
    	printf("Please Enter your last name: ");
    	scanf("%s",regis.lname);
    	
    	if(regis.fname[0] == 'q' || regis.fname[0] == 'Q'){
    		return;
    	}
	
	//take the contents and paste them in csv file...
	
		FILE *ptr;
		ptr = fopen("userdb.csv","a+");
		//fprintf(ptr,"%s,%s,%s,%s,%s,%s,%s,%s,%s\n",regis.reg,regis.password,regis.fname,regis.mname,regis.lname,regis.issue[0],regis.issue[1],regis.issue[2],regis.issue[3]);
		//return;
   		//fclose(ptr);

		//confirming the details
    	cls();
    	printf("\nConfirm the detail:");
    	printf("\n======================");
    	printf("\n\nReg no.: %s",regis.reg);
    	printf("\nPassword: %s",regis.password);
    
		
    	printf("\nFirstname: %s\nMiddlename: %s\nLastname: %s",regis.fname,regis.mname,regis.lname);
    	printf("\n\nPress E to edit any other key to continue...");

    //CHECK IF USER NEEDS TO EDIT THE DETAIL
   	 	char cha;
		int temp = getc(stdin);
		scanf("%c",&cha);
    	if(cha=='e'||cha=='E')
        	goto regNo;

    	fprintf(ptr,"%s,%s,%s,%s,%s,%s,%s,%s,%s\n",regis.reg,regis.password,regis.fname,regis.mname,regis.lname,regis.issue[0],regis.issue[1],regis.issue[2],regis.issue[3]);
    	printf("\nUser registration successful!");

		fclose(ptr);
		//main();

}


void studentLogin(){
		user student;
		const char* filename = "userdb.csv";
    	int y;
    	char ch, arr[200];
    	cls();
    	printf("\nUser Login");
		printf("\n==============\n\n");
		printf("PLease Enter Q or q to QUIT..\n");
		username:
		char reg[9];
		printf("\nEnter your login id no.: ");
		//fgets(student.reg);
		scanf("%s",reg);

        if(reg[0] == 'q' || reg[0] == 'Q'){
            return;
		}

        if((searchCSV(filename,reg))==0){
            printf("\nInvalid Login Id..\n");
            goto username;
        }

		if(reg[0]=='\0'){
			printf("\nInvalid login id number!");
			goto username;
		}
		strcpy(student.reg,reg);

		if((searchCSV(filename,student.reg))==1){
			
			goto pass;
		}

		else{ // returned val is 0;
			printf("Invalid login!...please enter a valid id...\n");
			goto username;
		}


		pass:
		 char pass[10];
		// printf("Enter your password: ");
		// scanf("%s",pass);

		printf("Enter your password: ");
		fflush(stdout);
		char *input = getpass("");
		
		strncpy(pass,input,sizeof(pass)-1);

		strcpy(student.password,pass);
		int i = 0;
	
		if(student.password[0] == 'q' || student.password[0] == 'Q'){
            return;
        }

		if((searchCSV(filename,student.password))==1){ //check password is present in csv file if present go to 
			goto std;
			welcome();
			printf("\nLogin Successful !\n");
			
		}

		else{
			printf("\n### Password Wrong !!!, Please Enter a Password again..###\n\n");
			goto pass;
			//exit(0);
		}
	
		//if above conditions are true then do below
		//issue book ... submit book ... display the books ... 
		std:

		cls();
		printf("\n\tServices available:");
        printf("\n====================================================\n");
        printf("\n1. ISSUE A BOOK                 2. RETURN A BOOK");
        printf("\n3. VIEW BOOKS              	  4. LOGOUT");
		
        printf("\n\nEnter your choice: ");
		scanf("%d",&i);
		printf("\n\n\nTo Quit please enter q or Q\n\n");
		if(i == 'q' || i == 'Q'){
			return;
		}
		/*
		void view_books();
		void issue_book();
		void submit_book();
		*/
		else{
		switch(i){
			case 1:
					issue_book();
					break;
			
			case 2:
					submit_book();
					break;
			
			case 3:
			        cls();
					view_books();
					goto std;
					break;
						
			case 4:
					logout();
					return;


			default:
					printf("\nInvalid choice!!\n");
					goto std;
					//cls();
					break;
		}
	}
	
}
	void adminLogin(){

			admin Admin;
			int i,j,x;
			//char ch, arr[200];
			cls();
			printf("\nAdmin Login");
			printf("\n==============\n\n");
			printf("PLease Enter Q or q to QUIT..\n");
			
			Adm:
			char reg[9];
			char reg1[9] = "11223344";
			char pass1[10]="admin@123";
			
			strcpy(Admin.reg, reg1);
			strcpy(Admin.password, pass1);

			printf("\nEnter your login id no.: ");
			scanf("%s",reg);
		
			if(reg[0] == 'q' || reg[0] == 'Q'){
				return;
			}
			i = strcmp(Admin.reg,reg);
			if(i != 0){
				printf("Invalid login..Please enter a valid login\n\n");
				goto Adm;
			}

		else{
			// printf("Enter your password: ");
			// scanf("%s",pass);
			char pass[10];
			printf("Enter your password: ");
			fflush(stdout);
			char *input = getpass("");
		
		strncpy(pass,input,sizeof(pass)-1);

			j = strcmp(Admin.password,pass);
			if(pass[0]=='\0'){
				printf("\nInvalid login id number!");
				goto Adm;
			}
			j = strcmp(Admin.password,pass);

			if(j != 0){
					printf("\nPassword mismatch");
					goto Adm;
			}
		}
			//if above conditions are true then do below
			std:

			cls();
			printf("\n\tServices available:");
			printf("\n====================================================\n");
			printf("\n1. ADD BOOK                 2. DELETE BOOK");
			printf("\n3. VIEW BOOKS               4. DISPLAY USERS");
			printf("\n5. LOGOUT						  ");

			printf("\n\nEnter your choice: ");
			scanf("%d",&x);

			printf("\n\n\nTo Quit please enter q or Q\n\n");
			
			/*void printList(list l);
			void freeList(list *l);
			void displayUserBook();*/
		
			switch(x){
				case 1:
						addBooks();
						goto std;
						break;
				
				case 2:
						deleteRow();
						goto std;
						//exit(0);
						//break;
				
				case 3:
						cls();
						view_books();
						goto std;
						//break;
							
				case 4:
						cls();
						view_users();
						goto std;
						//break;

				case 5:
						cls();
						logout();
						//goto std;
						break;

					
				default:
						printf("\nInvalid choice!!\n");
						//sleep(0.5);
						//cls();
						break;
			}
		

	}


	int searchCSV(const char* filename, const char* searchItem) {
		FILE* file = fopen(filename, "r");
		if (file == NULL) {
			printf("Failed to open the file: %s\n", filename);
			return 0;
		}

		char line[MAX_LINE_LENGTH];
		char* token;
		char* row[MAX_COLS];
		int row_count = 0;
		int col_count = 0;
		int found = 0;

		while (fgets(line, sizeof(line), file)) {
			token = strtok(line, ",");
			col_count = 0;

			while (token != NULL) {
				row[col_count] = token;
				col_count++;
				token = strtok(NULL, ",");
			}

			// Check if the search item exists in the row
			for (int i = 0; i < col_count; i++) {
				if (strcmp(row[i], searchItem) == 0) {
					found = 1;
					//printf("Item found at Row: %d, Column: %d\n", row_count, i);
				}
			}

			row_count++;
		}

		fclose(file);

		return found;
	}

void logout() {
	cls();
    char c;
    printf("\nAre you sure you want to logout?\n");
    printf("\nIF YES PRESS (y) AND FOR NO (n): ");
    fflush(stdin);
    scanf(" %c", &c);

    if (c == 'y') {
        // main();
    }
    return;
}

void welcome(){
	user regis;
	cls();
    if(regis.mname[1]=='\0'){
        printf("\t\t\t\tWelcome ");
		printf("\n");

	}
    else{
        //printf("\t\t\t\tWelcome %s %s",regis.fname,regis.lname);
		printf("%s",regis.mname);
    	printf("\n\n\n\t\t\t\tPress any key to continue...");
	}
	getc(stdin);

	return;
}