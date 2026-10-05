#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    char name[50];
    struct Node *next;
};
struct Node *front=NULL,*rear=NULL;
void arrive(char name[])
{
    struct Node *newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    strcpy(newnode->name,name);
    newnode->next=NULL;
    if(front==NULL){
        front=newnode;
        rear=newnode;
    }else{
        rear->next=newnode;
        rear=newnode;
    }
    printf("Arrived: %s\n",name);
    printf("Front: %s\n",front->name);
}
void attend()
{
    struct Node *temp;
    if(front==NULL)
    {
        printf("Queue Empty\n"); // patient koi nathi
        return;
    }
    temp=front;
    printf("Attended: %s\n",front->name);
    front=front->next;
    if(front==NULL)
        rear=NULL;
    free(temp);
    if(front!=NULL)
        printf("Front: %s\n",front->name);
}
int main()
{
    int op;
    char choice[20],name[50];
    printf("Enter number of operations: ");
    scanf("%d",&op);
    for(int i=0;i<op;i++)
    {
        scanf("%s",choice);
        if(strcmp(choice,"ARRIVE")==0)
        {
            scanf("%s",name);
            arrive(name);
        }else if(strcmp(choice,"ATTEND")==0)
            attend();
    }
    return 0;
}