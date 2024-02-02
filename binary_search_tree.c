#include<stdio.h>
#include<stdlib.h>
struct  node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=0;
struct node *newNode(int key){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->left=temp->right=NULL;
    temp->data=key;
    return temp;
    
}
struct node *insert(struct node *node,int key){
    if(node==0){
        return newNode(key);
    }
    if(key<node->data){
        node->left=insert(node->left,key);
    }
    else if(key>node->data){
        node->right=insert(node->right,key);
    }
    return node;
}
void print(struct node *root){
    if(root==0){
        return;
    }
    print(root->left);
    printf("%d ",root->data);
    print(root->right);
}


//for searching an element 
int search(struct node *node, int value){
    
    if(value==node->data){
        printf("%d data is found \n",node->data);
    }
    else{
        if(node->left==NULL||node->right==NULL){
            printf("data is not found\n");
            return 0;
        }   
        else if(value>node->data){
            search(node->right,value);
        }
        else if(value<node->data){
            search(node->left,value);
        }
    }
}


struct node *minNode(struct node *node){
    while(node->left!=NULL){
        node=node->left;
    }
    return node;
}
//Delete a node from the binary search tree
struct node *deleteNode(struct node *node,int key){
    if(node==NULL){
        return root;
    }
    if(key<node->data){
        node->left=deleteNode(node->left,key);
    }
    else if(key>node->data){
        node->right=deleteNode(node->right,key);
    }
    else{
        if(node->left==NULL){
            struct node *temp=node->right;
            free(node);
            return temp;  
        }
        if(node->right==NULL){
            struct node *temp=node->left;
            free(node);
            return temp;
        }
        struct node *temp=minNode(node->right);
        node->data=temp->data;

        //delete the root
        deleteNode(node->right,temp->data);
    }
    return node;
}
int main(){
    int d,choice=1;
     while (choice)
     {
        printf("Enter the data:");
        scanf("%d",&d);
        if(root==0){
                root=insert(root,d);
        }
        else{
        insert(root,d);
        }
        printf("Enter the choice (0 or 1)=>");
        scanf("%d",&choice);
     }
     search(root,50);
     root=deleteNode(root,60);
    print(root);
    return 0;
}
