#include<stdio.h>
void Toh(int n,char x,char y,char z)
{
    if(n>0)
    {
        Toh(n-1,x,z,y);
        printf("%c->%c\n",x,y);
        Toh(n-1,y,x,z);
    }
}
int main()
{
    int n;
    printf("How many disks?");
    scanf("%d",&n);
    Toh(n,'a','b','c');
    return 0;

}