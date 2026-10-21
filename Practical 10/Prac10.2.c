#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
struct Node{
    int data;
    struct Node *next;
};
struct Node *table[SIZE];
void insert(int value){
    int index=value%10;
    struct Node *newnode,*temp;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->next=NULL;
    if(table[index]==NULL)
        table[index]=newnode;
    else{
        temp=table[index];
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
    }
}
int main(){
    int n,value;
    for(int i=0;i<SIZE;i++)
        table[i]=NULL;
    printf("Enter number of books: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        insert(value);
    }
    printf("Hash Table:\n");
    for(int i=0;i<SIZE;i++){
        struct Node *temp=table[i];
        printf("%d : ",i);
        while(temp!=NULL){
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
    return 0;
}