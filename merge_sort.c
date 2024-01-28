#include<stdio.h>
void merge(int a[],int lb,int mid,int ub){
    int b[20];
    int i=lb;
    int j=mid+1;
    int k=lb;
    while (i<=mid&&j<=ub)
    {
        if(a[i]<=a[j]){
            b[k]=a[i];
            i++;
        }
        else{
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while (j<=ub){
            b[k]=a[j];
            k++;
            j++;
        }
    }
    else{
        while (i<=mid)
        {
            b[k]=a[i];
            k++;
            i++;
        }
        
    }
    for(i=0;i<=ub;i++){
        a[i]=b[i];
    }
    
}
void merge_sort(int a[],int lb,int ub){
    int mid;
    if(lb<ub){
        mid=(lb+ub)/2;
        merge_sort(a,lb,mid);
        merge_sort(a,mid+1,ub);
        merge(a,lb,mid,ub);
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
    merge_sort(a,0,n-1);
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}