#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char song[60];
    struct node* next;
    struct node* prev;
};
struct node* head = NULL;
struct node* tail = NULL;

void addbeginning (char value[]){
    struct node* newnode;
    newnode= (struct node*)malloc(sizeof(struct node));
    strcpy(newnode->song, value);
    newnode->prev = NULL;
    newnode->next = head;
    if(head == NULL){
        head = tail = newnode;
    }else{
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}
void addatlast(char value[]){
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    strcpy(newnode->song, value);
    newnode->next = NULL;
    struct node *temp = head;
    if(head == NULL){
        head = tail = newnode;
    }else{
        newnode->next = NULL;
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }
}
void addbetween(char newsong[], char currentsong[]){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    strcpy(newnode->song, newsong);
    struct node* temp = head;
    while (temp != NULL && strcmp(temp -> song, currentsong) != 0){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Song Not Found!");
        return;
    }

    newnode -> prev = temp;
    newnode -> next = temp -> next;
    
    if(temp->next != NULL){
        temp->next->prev = newnode;
    }else{
        tail = newnode;
    }
    temp -> next = newnode;
}
void deletefront(){
    if(head == NULL){
        printf("Playlist is empty.");
        return;
    }
    struct node* temp = head;
    if(head->next == NULL){
        head = tail = NULL;
    }else{
        head = head -> next;
        head->prev = NULL;
    }
}
void display(){
    struct node* temp = head;
    while (temp != NULL){
        printf("%s->", temp->song);
        temp = temp -> next;
        if(temp->next != NULL){
            printf("<->");
        }
    }
}
int count(){
    int count = 0;
    struct node* temp = head;
    while (temp != NULL){
        count++;
    }
    return count;
}
int main(){
    int choice;
    char song[60];
    char currentsong[60];
    while (1){
        printf("Enter your choice from menu: \n");
        printf("1. Add song at beggining.\n");
        printf("2. Add song at the last.\n");
        printf("3. Add song in the middle.\n");
        printf("4. Delete Song.\n");
        printf("5. Display all songs.\n");
        printf("6. Display Count.\n");
        printf("7. Exit");
        scanf("%d", choice);
    }
}