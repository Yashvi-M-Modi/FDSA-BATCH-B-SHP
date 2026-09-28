#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char stack[100][50];
int n;
int top = - 1;
void push(char tray[]){
    if(top == n-1){
        printf("Tray Container is Full.");
        return;
    }
    top ++;
    strcpy(stack[top], tray);
}
void pop(){
    if(top == -1){
        printf("Tray Container is Empty.");
        return;
    }
    printf("Taken Tray: %s\n", stack[top]);
    top --;
}
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Current Stack:\n");
    for (int i = top; i >= 0; i--) {
        printf("%s\n", stack[i]);
    }
    printf("Top Tray: %s\n", stack[top]);
}
int main() {
    int choice;
    char tray[50];
    printf("Enter capacity of Tray Container: ");
    scanf("%d", &n);
    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Add a Tray.\n");
        printf("2. Take a Tray.\n");
        printf("3. Display the Top Tray.\n");
        printf("4. Exit.\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the name of Tray you want to add: ");
                scanf("%s", tray);
                push(tray);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Program is exiting.\n");
                return 0;
        }
    }

    return 0;
}
