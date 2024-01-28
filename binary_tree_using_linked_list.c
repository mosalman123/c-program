#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *left,*right;
    
};
struct node *root=0;
struct node *create()
{
    int x,data;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data(-1 for no node):");
    scanf("%d",&x);
    if(x==-1){
        return 0;
    }
    newnode->data=x;
    printf("Enter left child of %d\n",x);
    newnode->left=create();
    printf("Enter right child of %d\n",x);
    newnode->right=create();
    return newnode;
}
void print(struct node *root){
    if(root==0){
        return;
    }
    print(root->left);
    printf("%d ",root->data);
    print(root->right);;
}
int main(){
    root=create();
    print(root);
        return 0;
    
}