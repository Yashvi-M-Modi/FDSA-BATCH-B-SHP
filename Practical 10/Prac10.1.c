#include <stdio.h>
#define SIZE 10
int main(){
    int table[SIZE];
    int n,value,index;
    for(int i=0;i<SIZE;i++)
        table[i]=-1;
    printf("Enter number of vehicles: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        index=value%10;
        while(table[index]!=-1)
            index=(index+1)%SIZE; // ahiya next slot check thase
        table[index]=value;
    }
    printf("Hash Table:\n");
    for(int i=0;i<SIZE;i++){
        if(table[i]==-1)
            printf("%d : EMPTY\n",i);
        else
            printf("%d : %d\n",i,table[i]);
    }
    return 0;
}