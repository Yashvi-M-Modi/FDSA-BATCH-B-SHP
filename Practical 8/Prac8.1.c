#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *left,*right;
};
struct Node* createNode(int value){
    struct Node *newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
void inorder(struct Node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void preorder(struct Node *root){
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct Node *root){
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
void levelorder(struct Node *root){
    struct Node *queue[100];
    int front=0,rear=0;
    if(root==NULL)
        return;
    queue[rear++]=root;
    while(front<rear){
        struct Node *temp=queue[front++];
        printf("%d ",temp->data);
        if(temp->left!=NULL)
            queue[rear++]=temp->left;
        if(temp->right!=NULL)
            queue[rear++]=temp->right;
    }
}
int main(){
    struct Node *root;
    root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    /*  Binary Tree created:-
            1
           / \
          2   3
         / \
        4   5
    */
    printf("Inorder: ");
    inorder(root);
    //Inorder would be:- 4->2->5->1->3
    printf("\nPreorder: ");
    preorder(root);
    //Preorder would be:- 1->2->4->5->3
    printf("\nPostorder: ");
    postorder(root);
    //Postorder would be:- 4->5->2->3->1
    printf("\nLevel Order: ");
    levelorder(root);
    //levelorder would be:- 1->2->3->4->5
    return 0;
}