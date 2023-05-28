#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkedlist.h"

void printList(list l){

     while (l != NULL) {
       // printf("%s \n", l->reg, l->fname, l->mname, l->lname);
        l = (l)->next;
    }
return;
}
void freeList(list *l){
    list temp;
     while (l != NULL) {
        temp = *l;
        *l = (*l) -> next;
        free(temp);
    }
    return;
}

void display_users_with_books() {
    FILE* user_database;
    char line[200], * token;
    list head = NULL;
    list tail = NULL;

    // Open the user database file
    user_database = fopen("userdb.csv", "r");

    // Check if file opened successfully
    if (user_database == NULL) {
        printf("Error opening user database file.\n");
        return;
    }

    // Read each line of the file and extract the necessary information
    while (fgets(line, sizeof(line), user_database) != NULL) {
        // Split the line into tokens using comma as the delimiter
        token = strtok(line, ",");
        int col_num = 0;
        list current_node = NULL;

        while (token != NULL) {
            // If this is the first column, store the registration number
            if (col_num == 0) {
                // Allocate memory for a new node
                list new_node = (list)malloc(sizeof(node));
                strcpy(new_node->reg, token);
                new_node->next = NULL;

                // If this is the first node, set it as head and tail
                if (head == NULL) {
                    head = new_node;
                    tail = new_node;
                }
                // Otherwise, append the node to the end of the list
                else {
                    tail->next = new_node;
                    tail = new_node;
                }

                // Set the current node to the new node
                current_node = new_node;
            }
            // If this is the last column, check if the user has issued any books
            else if (col_num == 5) {
                // If the user has issued books, add their name to the current node
                if (strlen(token) > 1) {
                    char fname[20], mname[20], lname[20];
                    sscanf(token, "%[^','],%[^','],%[^',']", fname, mname, lname);
                    strcpy(current_node->fname, fname);
                    strcpy(current_node->mname, mname);
                    strcpy(current_node->lname, lname);
                }
            }

            // Move to the next token
            token = strtok(NULL, ",");
            col_num++;
        }
    }

    // Close the user database file
    fclose(user_database);

    // Print the list of users who have issued books
    printf("\nUsers with issued books:\n");
    list current = head;
    while (current != NULL) {
        if (strlen(current->fname) > 0) {
            printf("%s\t\n", current->reg);
        }
        current = current->next;
    }

    // Free the memory used by the linked list
    freeList(&head);
}

