#include<stdio.h>
#define n 10
int a[n],top=0;
void push();
void pop();
void peek();
void display();
int main(){
    int m=0;
    
    while (m!=5)
    {
        printf("For push enter 1___:\n");
        printf("For pop enter 2____:\n");
        printf("For peek enter 3___:\n");
        printf("For display enter 4:\n");
        printf("For exiting 5______:\n");
        printf("Enter your choice ");
        scanf("%d",&m);
        switch (m)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting.......");
            break;
        default:
           printf("Invalid number Please enter right number:\n");
            break;
        }

    }
    
    return 0;

}
void push(){
    int num;
    printf("Enter the element who want to push in the stack:");
    scanf("%d",&num);
    if(top==n){
        printf("Overflow stack:\n");
    }
    else{
        top=top+1;
        a[top]=num;
    }

}
void display(){
    for(int i=top;i>0;i--){
        printf("%d at position %d\n",a[i],i);
        
    }
    printf("**********************************************\n");
}
void pop(){
    int del;
if(top==0)
{
    printf("Underflow:\n");
    printf("*********************\n");
}
else{
    del=a[top];
    top=top-1;
    printf("The deleted element is %d\n",del);
    printf("*********************\n");

}
}
void peek(){
    if(top==0){
        printf("Stack is empty:\n");
        printf("*********************\n");

    }
    else{
        printf("The top peek element in stack is %d\n",a[top]);
        printf("*********************\n");
    }
}