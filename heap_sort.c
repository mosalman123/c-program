#include<stdio.h>
void heapify(int a[],int n,int i){
    int swap;
    int largerst=i;
    int l=(2*i+1);
    int r=(2*i+2);
    while (l<n&&a[l]>a[largerst])
    {
        largerst=l;
    }
    while (r<n&&a[r]>a[largerst])
    {
        largerst=r;
    }
    if(largerst!=i)
    {
        swap=a[largerst];
        a[largerst]=a[i];
        a[i]=swap;
        heapify(a,n,largerst);

    }
    
}
void heap_sort(int a[],int n){
    int i,swap;
    for(i=n/2-1;i>=0;i--){
        heapify(a,n,i);

    }
    for(i=n-1;i>=0;i--){
        swap=a[0];
        a[0]=a[i];
        a[i]=swap;
        heapify(a,i,0);
    }
}
int main(){
    int n,k,a[10];
    printf("Enter no of array element:");
    scanf("%d",&n);
    printf("Enter the array element:");
    for(k=0;k<n;k++){
        scanf("%d",&a[k]);
    }
    heap_sort(a,n);
    printf("Enter the array element:");
    for(k=0;k<n;k++){
    printf("%d ",a[k]);
    }
    return 0;

}
