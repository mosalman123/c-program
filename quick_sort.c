#include<stdio.h>
int partion(int a[],int lb,int ub){
      int pivot=a[lb],swap;
      int start=lb;
      int end=ub;
      while (start<end)
      {
        while(a[start]<=pivot){
            start++;
        }
        while (a[end]>pivot)
        {
            end--;
        }
        if(start<end){
            swap=a[start];
            a[start]=a[end];
            a[end]=swap;
        }
      }
      swap=a[end];
      a[end]=a[lb];
      a[lb]=swap;
      return end;
}
void quick_sort(int a[],int lb,int ub){
    int loc;
    if(lb<ub){
        loc=partion(a,lb,ub);
        quick_sort(a,0,loc-1);
        quick_sort(a,loc+1,ub);
    }
}
int main(){
    int a[20];
    int i,n;
    printf("Enter the no of array element:");
    scanf("%d",&n);
    printf("Enter the array element:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    quick_sort(a,0,n-1);
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}