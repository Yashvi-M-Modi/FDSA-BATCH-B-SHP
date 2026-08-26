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
        printf("Invalid position!\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void deletevalue(int value) {
    if (head == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    struct node *temp = head;
    struct node *prev = NULL;
    if (temp->data == value) {
        head = head->next;
        free(temp);
        printf("Patient deleted successfully.\n");
        return;
    }
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Patient not found!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Patient deleted successfully.\n");
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
void printreverse(struct node *temp) {
    if (temp == NULL)
        return;
    printreverse(temp->next);
    printf("%d", temp->data);
    if (temp != head)
        printf("->");
}
int main() {
    int choice, value, position;

    while (1) {
        printf("\n--- Hospital Patient Queue ---\n");
        printf("1. Add patient at front\n");
        printf("2. Add patient at end\n");
        printf("3. Insert patient at position\n");
        printf("4. Delete patient\n");
        printf("5. Forward traversal\n");
        printf("6. Reverse printing\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter patient token: ");
            scanf("%d", &value);
            insertfront(value);
            printf("Queue after insertion: ");
            display();
        }else if (choice == 2) {
            printf("Enter patient token: ");
            scanf("%d", &value);
            insertend(value);
            printf("Queue after insertion: ");
            display();
        }else if (choice == 3) {
            printf("Enter patient token: ");
            scanf("%d", &value);
            printf("Enter position: ");
            scanf("%d", &position);
            insertPosition(value, position);
            printf("Queue after insertion: ");
            display();
        }else if (choice == 4) {
            printf("Enter patient token to delete: ");
            scanf("%d", &value);
            deletevalue(value);
            printf("Queue after deletion: ");
            display();
        }else if (choice == 5) {
            printf("Queue from front to back: ");
            display();
        }else if (choice == 6) {
            printf("Queue from last to first: ");
            printreverse(head);
            printf("\n");
        }else if (choice == 7) {
            printf("Program ended.\n");
            break;
        }else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}