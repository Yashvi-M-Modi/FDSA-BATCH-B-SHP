#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *left,*right;
};
//Similar to previous 8.1
struct Node* createNode(int value){
    struct Node *newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct Node* insert(struct Node *root,int value){
    if(root==NULL)
        return createNode(value);
    //If the value is less than root then it goes to the left according to BST
    if(value<root->data)
        root->left=insert(root->left,value);
    //If the value is greater than root then it goes to the right according to BST
    else if(value>root->data)
        root->right=insert(root->right,value);
    //Return root to terminate
    return root;
}
void inorder(struct Node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int main(){
    struct Node *root=NULL;
    int n,value;
    printf("Enter number of values: ");
    scanf("%d",&n);
    printf("Enter values:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        root=insert(root,value);
    }
    printf("Inorder: ");
    inorder(root);
    return 0;
}