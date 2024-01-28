#include<stdio.h>
#include<stdlib.h>
struct  node
{
    int data;
    struct node *left,*right;    
};
struct node *root=0,*cpt;
struct node *create()
{
    struct node *newnode;
    int x;
    
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data (-1 for exit:)");
    scanf("%d",&x);
    if (x==-1){
        return 0;
    }
    if(cpt->data<x){
    newnode->data=x;
    cpt=newnode;
    printf("Enter the left child of %d\n",x);
    newnode->left=create();
    }
    printf("Enter the right child of %d\n",x);
    newnode->right=create();
    return newnode;

}
void print(struct node *root){
    if (root==0){
        return;
    }
    print(root->left);
    printf("%d ",root->data);
    print(root->right);
}
int main(){
    root=create();
    print(root);
    return 0;
}
