#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;
void insertfront(int value) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}
void insertend(int value) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
}
void insertPosition(int value, int p) {
    if (p <= 0) {
        printf("Invalid position!\n");
        return;
    }
    if (p == 1) {
        insertfront(value);
        return;
    }
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = value;
    struct node *temp = head;
    for (int i = 1; i < p - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Invalid position! Position is greater than queue length.\n");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void display() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf("->");
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    int choice, value, position;

    while (1) {
        printf("\n--- Hospital Patient Queue ---\n");
        printf("1. Add critical patient at front\n");
        printf("2. Add routine patient at end\n");
        printf("3. Insert patient at position\n");
        printf("4. Display queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter patient token: ");
            scanf("%d", &value);
            insertfront(value);
            printf("Queue after insertion: ");
            display();
        }
        else if (choice == 2) {
            printf("Enter patient token: ");
            scanf("%d", &value);
            insertend(value);
            printf("Queue after insertion: ");
            display();
        }
        else if (choice == 3) {
            printf("Enter patient token: ");
            scanf("%d", &value);
            printf("Enter position: ");
            scanf("%d", &position);
            insertPosition(value, position);
            printf("Queue after insertion: ");
            display();
        }
        else if (choice == 4) {
            printf("Current queue: ");
            display();
        }
        else if (choice == 5) {
            printf("Program ended.\n");
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}