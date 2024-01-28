#include<stdio.h>
#include<stdlib.h>
void create();
void print();
struct node
{
	int data;
	struct node *pre,*next;
};
struct node *head,*newnode,*temp;
int choice;
int main()
{
    create();
    print();
    return 0;
}
void create()
{   choice=1;
    head=0;
while(choice)
{
newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter the data:");
	scanf("%d",&newnode->data);
    newnode->pre=0;
	newnode->next=0;
	if(head==0)
	{
		head=temp=newnode;
		}
		else
		{
			temp->next=newnode;
            newnode->pre=temp;
			temp=newnode;
			}
		printf("do you want to continue(0 or 1):");
		scanf("%d",&choice);
		}
}
void print(){
        temp=head;
		while(temp!=0)
		{
			printf("%d ",temp->data);
			temp=temp->next;

			}
}
