#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include<ctype.h>
#include"library.h"
#include"book_operation.h"
#define MAX_LENGTH 100


void view_books() {
    // open the file in read mode
    FILE* fp = fopen("bookdb.csv", "r");
    if (fp == NULL) {
        printf("Unable to open file 'bookdb.csv' for reading.\n");
        return;
    }
	printf("\n");
    // read each line of the file and display the book information
    char line[512];
    printf("Name\tAuthor\tISBN\n");
    while (fgets(line, sizeof(line), fp)) {
        // parse the line to get the book's information
        char* tok = strtok(line, ",");
        book b;
        strcpy(b.name, tok);
        tok = strtok(NULL, ",");
        strcpy(b.author, tok);
        tok = strtok(NULL, ",");
        strcpy(b.isbn, tok);

        // display the book information
        printf("%s\t%s\t%s\n", b.name, b.author, b.isbn);
    }
  //close the file
    fclose(fp);
    
    char quit;
    printf("PRESS 'q' OR 'Q' TO QUIT\n");
    getc(stdin);
    quit = getc(stdin);
    if(quit == 'q' || quit == 'Q'){
        return;
    }
}


void issue_book(/*char* registerNO/*/) {
    int i, j, x, limit = 1, book_pos = 6, book_found = 0;
    char arr[12], book1[100];
    char c;

    user user1 = {0};
    book newBook;

    FILE* fp;

    cls();
    printf("\nIssue book");
    printf("\n=================\n");

    for (i = 0; i < 4; i++) {
        if (user1.issue[i][1] == '\0') {
            limit = 0;
            break;
        }
    }

    book_pos = i + 1;

    if (limit == 0) {
    isbn:
        printf("\nEnter the 10-digit ISBN of the book: ");
        scanf("%s", arr);

        if (arr[0] == 'q') {
            return;
        }
        arr[11] = '\0';

        for (i = 0; arr[i] != '\0'; i++) {
            if (!isNumber(arr[i])) {
                printf("\nInvalid input! Please enter a numeric ISBN.");
                goto isbn;
            }
        }
    }

    fp = fopen("bookdb.csv", "r");
    if (fp == NULL) {
        printf("\nError: Unable to open file.");
        return;
    }

    while (fgets(book1, sizeof(book1), fp) != NULL) {
        sscanf(book1, "%[^,],%[^,],%[^,]", newBook.isbn, newBook.name, newBook.author);

        if (strcmp(newBook.isbn, arr) == 0) {
            book_found = 1;
            printf("%i", book_found);
            break;
        }
    }

    if (book_found == 1) {
        cls();
        printf("\n%s\t%s\t%s", newBook.isbn, newBook.name, newBook.author);
        printf("\n\nPress q to cancel or any other alphabet to continue issuing process...");
        scanf(" %c", &c);
        if (c == 'q' || c == 'Q') {
            return;
        }
        else {
            // strcpy(user1.issue[book_pos], newBook.isbn);
            // //usedb madhe toh isbn number de.
            // char* registerNO;
            // FILE *ptr;
            // ptr = fopen("userdb.csv", "w+");

            // if (ptr == NULL) {
            //     printf("\nError: Unable to open file.");
            //     return;
            // }
            // //mla aata tyachya 6th 7th 8th 9th row check karaichi ahe 
            // findRowNumber(ptr, arr);
            // int i = findDataPresentInCSV(int row);

            // const char* filename = "userdb.csv";
            // int result = checkColumnsInRow(filename, rowNumber);

            // if (result == 0) {
            //     //printf("No data found in columns 6 to 9 of the specified row.\n");
            //      const char* sourceFile = "bookdb.csv";
            //      const char* destinationFile = "userdb.csv";
            //     transferData(sourceFile, destinationFile);

            strcpy(user1.issue[book_pos], newBook.isbn);
            printf("\nBook successfully issued!");
            sleep(2);
            printf("\nYou will be taken to the Main Menu.");
            fflush(stdout);
            sleep(2);
            
            } 
        }

    else {
        printf("\nInvalid ISBN number entered");
        goto isbn;
    }

    fclose(fp);
}


void submit_book()
{
    int i,j,book_pos,found=0,no_book=1;
    char arr[12],book1[100],c;
    book newBook;
    user user1;
    FILE *fp;
    //FILE *fp=fopen("temp.csv","r");
    for(i=0;i<12;i++)
        arr[i]='\0';
    cls();
    printf("\nBook submit");
    printf("\n================\n\n");
    for(i=0;i<4;i++)
    {
        if(user1.issue[i][1]!='\0')
        {
            no_book=0;
            break;
        }
    }
    if(no_book==1)
    {
        printf("\n\n\t\tYou don't have any books pending. Press any key to go back...");
        getc(stdin);
        return;
    }
    input:
    printf("\nEnter the isbn number of the book you want to submit: ");
    //gets(arr);
    scanf("%s",arr);
    //printf("%s",arr);
    if(arr[0] == 'q'){
            return;

    for(i=0;i<10;i++)
    {
        if(!isNumber(arr[i]))
        {
            printf("\nInvalid input!");
            goto input;
        }
    }
    for(i=0;i<4;i++)
    {
        if(strcmp(user1.issue[i],arr)==0)
        {
            found=1;
            book_pos=i;
            break;
        }
    }

    if(found=1)
    {
        //rewind(bookdb);
        FILE *fp;
        fp = fopen("bookdb.csv", "r");
        if (fp == NULL) {
            printf("\nError: Unable to open file.");
            return;
        }
        fclose(fp);
        while(fgets(book1,71,fp)!=NULL)
        {
            for(i=0;i<30;i++)
            {
                newBook.author[i]='\0';
                newBook.name[i]='\0';
                newBook.isbn[i%11]='\0';
            }
            i=0;
            j=0;
            while(book1[i]!=',')
            {
                newBook.name[j]=book1[i];
                i++;
                j++;
            }
            i++;
            j=0;
            while(book1[i]!=',')
            {
                newBook.author[j]=book1[i];
                i++;
                j++;
            }
            i++;
            j=0;
            while(book1[i]!='\n')
            {
                newBook.isbn[j]=book1[i];
                i++;
                j++;
            }
            if(strcmp(newBook.isbn,user1.issue[book_pos])==0)
            {
                printf("\n\n  ISBN\t\t\tName\t\t\tAuthor");
                printf("\n---------------------------------------------------------------------------------");
                printf("\n%s\t\t%s\t\t\t%s",newBook.isbn,newBook.name,newBook.author);
            }

        }
        printf("\n\nPress C to cancel or press any key to continue...");
        getc(stdin);
        c=getc(stdin);
        if(c=='c'||c=='C')
            return;
        else
        {
            for(i=0;i<11;i++)
            {
                user1.issue[book_pos][i]='\0';
            }
        }
    }
    else
    {
        printf("\nBook not found!");
        getc(stdin);
        return;
    }

}
}

void view_users() {
    // open the file in read mode
    FILE* fp = fopen("userdb.csv", "r");
    if (fp == NULL) {
        printf("Unable to open file 'bookdb.csv' for reading.\n");
        return;
    }
	printf("\n");
    // read each line of the file and display the book information
    char line[512];
    //printf("Register\tPassword\tName\tMidName\tLast Name\t Book1 \t Book2 \t Book3 \t Book4\n");
    while (fgets(line, sizeof(line), fp)) {
        // parse the line to get the book's information

        char* tok = strtok(line, ",");
        user b;
        strcpy(b.reg, tok);
        tok = strtok(NULL, ",");
        strcpy(b.password, tok);
        tok = strtok(NULL, ",");
        strcpy(b.fname, tok);
        tok = strtok(NULL, ",");
        strcpy(b.mname, tok);
        tok = strtok(NULL, ",");
        strcpy(b.lname,tok);
        tok = strtok(NULL, ",");
    
        //display user information
        printf("%s\t%s\t%s\t%s\t%s\n", b.reg, b.password, b.fname, b.mname, b.lname);
    }
  //close the file
    fclose(fp);
    
    char quit;
    printf("\n");
    printf("PRESS 'q' OR 'Q' TO QUIT\n");
    getc(stdin);
    quit = getc(stdin);
    if(quit == 'q' || quit == 'Q'){
        return;
    }
    // 
}

void addBooks(){
    book addB;
    admin ADM;
	int x,y;
	//FILE *ptr ;
	const char* filename = "bookdb.csv";
    //char arr[120], arr2[9], ch, pass[10];
    	//putting NULL to avoid garbage

	for(x=0;x<20;x++){

    	addB.name[x]='\0';
    	addB.author[x]='\0';
    	addB.isbn[x]='\0';
	}

	cls();
	printf("\nADD BOOKS TO LIBRARY");
	printf("\n====================\nPlease enter Q or q to Quit\n\n");

    isbnno:
    char isb[11];
    	//move forward to take name
	printf("Enter ISBN N0: ");
	scanf("%s",isb);

	strcpy(addB.isbn,isb);

        x = searchCSV(filename,addB.isbn);
        //printf("%d\n",x);
        if(x == 1){
            printf("Book already exists in the database.\n\n");
            goto isbnno;
        }

    	printf("Enter Book Name : ");
    	fgets(addB.name,30,stdin);
    	scanf("%s",addB.name);
    	if(addB.name[0] == 'q' || addB.name[0] == 'Q'){
    		return;
    	}
    	
    	printf("Enter Author's Name : ");
    	fgets(addB.author,30,stdin);
        scanf("%s",addB.author);
    	if(addB.author[0] == 'q' || addB.author[0] == 'Q'){
    		return;
    	}
	
	//take the contents and paste them in csv file...
	
		FILE *ptr;
		ptr = fopen("bookdb.csv","a+");
        if (ptr == NULL) {
            printf("\nError: Unable to open file.");
            fclose(ptr);
            return;
        }
        //fprintf(ptr,"%s,%s,%s\n",addB.isbn,addB.name,addB.author);
		//confirming the details
    	cls();
    	printf("\nConfirm the detail:");
    	printf("\n======================");
    	printf("\n\nBook Name: %s",addB.name);
    	printf("\nAuthor: %s",addB.author);
        printf("\nISBN NO: %s",addB.isbn);
    
    	printf("\n\nPress E to edit any other key to continue...");

    //CHECK IF USER NEEDS TO EDIT THE DETAIL
   	 	char cha;
		
        int temp = getc(stdin);
        scanf("%c",&cha);
    	
        if(cha=='e'||cha=='E')
        	goto isbnno;

    	fprintf(ptr,"%s,%s,%s\n",addB.isbn,addB.name,addB.author);
    	printf("\nBook registration successful!\n");
		fclose(ptr);
        return;
}

void deleteRow() {
    const char* filename = "bookdb.csv";
    const char* entry ;
	char data[11];

	int rowToDelete;

    printf("\nEnter the books ISBN to delete: ");
    //scanf("%d", &rowToDelete);
	scanf("%s",data);
	entry = data;

	rowToDelete = findRowNumber(filename, entry);
    FILE* file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Failed to open the file: %s\n", filename);
        return;
    }

    FILE* tempFile = tmpfile();
    if (tempFile == NULL) {
        printf("Failed to create temporary file.\n");
        fclose(file);
        return;
    }

    char line[1000];
    int currentRow = 1;

    // Read each line from the original file
    while (fgets(line, sizeof(line), file)) {
        // If the current row is the row to delete, skip it
        if (currentRow == rowToDelete) {
            currentRow++;
            continue;
        }

        // Write the line to the temporary file
        fputs(line, tempFile);
        currentRow++;
    }

    fclose(file);

    // Reopen the original file in write mode
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open the file: %s\n", filename);
        fclose(tempFile);
        return;
    }

    // Rewind the temporary file
    rewind(tempFile);

    // Copy the content from the temporary file to the original file
    while (fgets(line, sizeof(line), tempFile)) {
        fputs(line, file);
    }

    fclose(file);
    fclose(tempFile);

    printf("Row %d deleted successfully.\n", rowToDelete);
}


int findRowNumber(const char* filename, const char* entry) {

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file %s\n", filename);
        return -1;
    }

    char line[1024];
    int currentRow = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        currentRow++;

        // delimiter ','
        char* token = strtok(line, ",");
        while (token != NULL) {
            // Remove leading and trailing spaces from the token
            char* trimmedToken = strtok(token, " \t\r\n");

            // Compare the trimmed token with the specified entry
            if (strcmp(trimmedToken, entry) == 0) {
                fclose(file);
                return currentRow;
            }

            token = strtok(NULL, ",");
        }
    }
    fclose(file);
    return -1;
}


// int checkColumnsInRow(const char* filename, int rowNumber) {
//     FILE* file = fopen(filename, "r");
//     if (file == NULL) {
//         printf("Error: Unable to open the file.\n");
//         return -1;
//     }

//     char line[MAX_LENGTH];
//     int currentRow = 1;
//     int columnNumber = 1;

//     while (fgets(line, sizeof(line), file) != NULL) {
//         if (currentRow == rowNumber) {
//             char* token = strtok(line, ",");

//             while (token != NULL) {
//                 if (columnNumber >= 6 && columnNumber <= 9) {
//                     if (strlen(token) > 0 && token[0] != '\n') {
//                         fclose(file);
//                         return columnNumber;
//                     }
//                 } else if (columnNumber > 9) {
//                     fclose(file);
//                     return INT_MAX;
//                 }

//                 token = strtok(NULL, ",");
//                 columnNumber++;
//             }

//             break;
//         }

//         currentRow++;
//     }

//     fclose(file);

//     return 0;
// }

// void transferData(const char* sourceFile, const char* destinationFile) {
//     FILE* source = fopen(sourceFile, "r");
//     if (source == NULL) {
//         printf("Error: Unable to open the source file.\n");
//         return;
//     }

//     FILE* destination = fopen(destinationFile, "w");
//     if (destination == NULL) {
//         printf("Error: Unable to open the destination file.\n");
//         fclose(source);
//         return;
//     }

//     char line[MAX_LENGTH];

//     while (fgets(line, sizeof(line), source) != NULL) {
//         // Extract the data you want to transfer (e.g., 6th column)
//         char* token = strtok(line, ",");
//         int columnNumber = 1;

//         while (token != NULL) {
//             if (columnNumber == 6) {
//                 // Write the extracted data to the destination file
//                 fprintf(destination, "%s,", token);
//                 break;
//             }

//             token = strtok(NULL, ",");
//             columnNumber++;
//         }
//     }

//     fclose(source);
//     fclose(destination);

//     //printf("Data transfer completed.\n");
// }