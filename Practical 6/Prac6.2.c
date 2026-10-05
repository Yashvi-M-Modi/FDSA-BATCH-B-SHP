#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
    char page[100];
    struct node *next;
};
struct node *top = NULL;
void visit(char page[]) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    strcpy(newnode->page, page);
    newnode->next = top;
    top = newnode;
}
void back() {
    if (top == NULL) {
        printf("No history left.\n");
        return;
    }
    struct node *temp = top;
    top = top->next;

    free(temp);
}
void display() {
    if (top == NULL) {
        printf("No page in history.\n");
        return;
    }
    printf("Current page: %s\n", top->page);
}
int main() {
    int choice;
    char page[100];
    while (1) {
        printf("\n1. Visit\n");
        printf("2. Back\n");
        printf("3. Display current page\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter page: ");
            scanf(" %[^\n]", page);
            visit(page);
            display();
        }else if (choice == 2) {
            back();
            display();
        }else if (choice == 3) {
            display();
        }else if (choice == 4) {
            printf("Program ended.\n");
            break;
        }else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}