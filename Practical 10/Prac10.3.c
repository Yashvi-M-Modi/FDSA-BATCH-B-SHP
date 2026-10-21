#include <stdio.h>
#define SIZE 10
int main(){
    int table[SIZE];
    int n,value,h1,h2,index,i;
    for(int j=0;j<SIZE;j++)
        table[j]=-1;
    printf("Enter number of student IDs: ");
    scanf("%d",&n);
    for(int j=0;j<n;j++){
        scanf("%d",&value);
        h1=value%10;
        h2=7-(value%7);
        i=0;
        while(i<SIZE){
            index=(h1+i*h2)%SIZE;
            if(table[index]==-1){
                table[index]=value;
                break;
            }
            i++;
        }
        if(i==SIZE)
            printf("Hash Table Full\n");
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