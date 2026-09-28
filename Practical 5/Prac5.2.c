#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
    char student[50];
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
struct node *tail = NULL;
void join(char name[]) {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    strcpy(newnode->student, name);
    if (head == NULL) {
        head = tail = newnode;
        newnode->next = head;
        newnode->prev = head;
    }
    else {
        newnode->next = head;
        newnode->prev = tail;
        tail->next = newnode;
        head->prev = newnode;
        tail = newnode;
    }
}
void leave(char name[]) {
    struct node *temp = head;
    if (head == NULL) {
        printf("Circle is empty.\n");
        return;
    }
    do {
        //If the object is found then return it.
        if (strcmp(temp->student, name) == 0) {
            if (head == tail) {
                head = tail = NULL;
            }
            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                if (temp == head)
                    head = temp->next;
                if (temp == tail)
                    tail = temp->prev;
            }
            free(temp);
            return;
        }
        //If object is not found than shift temp to its next element
        temp = temp->next;

    } while (temp != head);
    printf("Student not found.\n");
}
void display() {
    struct node *temp;
    if (head == NULL) {
        printf("Circle is empty.\n");
        return;
    }
    temp = head;
    do {
        printf("%s <-> ", temp->student);
        temp = temp->next;
    } while (temp != head);
    printf("back to %s\n", head->student);
}
int main() {
    int choice;
    char name[50];
    while (1) {
        printf("\n1. Join\n");
        printf("2. Leave\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter student name: ");
            scanf("%s", name);
            join(name);
            display();
        }
        else if (choice == 2) {
            printf("Enter student name: ");
            scanf("%s", name);
            leave(name);
            display();
        }
        else if (choice == 3) {
            display();
        }
        else if (choice == 4) {
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}