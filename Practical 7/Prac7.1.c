#include <stdio.h>
#include <string.h>
#define MAX 100
int queue[MAX];
int front=-1,rear=-1;
void join(int token,int n)
{
    if(rear==n-1)
    {
        printf("Queue Full\n"); // ahiya jagya nathi
        return;
    }if(front==-1)
        front=0;
    rear++;
    queue[rear]=token;
    printf("Joined: %d\n",token);
    printf("Front: %d\n",queue[front]);
}
void serve()
{
    if(front==-1 || front>rear){
        printf("Queue Empty\n"); // ahiya koi nathi
        return;
    }
    printf("Served: %d\n",queue[front]);
    front++;
    if(front>rear){
        front=-1;
        rear=-1;
    }else
        printf("Front: %d\n",queue[front]);
}
int main()
{
    int n,op,token;
    char choice[20];
    printf("Enter queue size: ");
    scanf("%d",&n);
    printf("Enter number of operations: ");
    scanf("%d",&op);
    for(int i=0;i<op;i++)
    {
        scanf("%s",choice);
        if(strcmp(choice,"JOIN")==0)
        {
            scanf("%d",&token);
            join(token,n);
        }else if(strcmp(choice,"SERVE")==0)
            serve();
    }
    return 0;
}