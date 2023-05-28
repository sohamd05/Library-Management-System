typedef struct user{
    char reg[10];
    char password[10];
    char fname[20];
    char mname[20];
    char lname[20];
    char issue[4][11];
}user;

typedef struct admin{
    char reg[10];
    char password[10];
}admin;

typedef struct book{
    char name[30];
    char author[30];
    char isbn[11];
}book;

typedef book Book;
void cls();
void cls1();
void registeration();
void studentLogin(); 
void adminLogin();
void welcome();
int searchCSV(const char* filename, const char* searchItem);
void logout();
int isNumber(char ch);
