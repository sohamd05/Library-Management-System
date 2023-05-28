typedef struct node {
    char reg[10];
    char password[10];
    char fname[20];
    char mname[20];
    char lname[20];
    struct node* next;
}node;

typedef node* list;

void printList(list l);
void freeList(list *l);
void displayUserBook();