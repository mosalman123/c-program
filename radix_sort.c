#include<stdio.h>
int max(int a[],int n){
    int m=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>m){
        m=a[i];
    }
    }
    return m;
}
void countsort(int a[],int n,int e){
    int output[n];
    int count[10]={0};
    for(int i=0;i<n;i++){
        count[(a[i]/e)%10]++;
    }
    for(int i=1;i<10;i++){
        count[i]=count[i]+count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        output[count[(a[i]/e)%10]-1]=a[i];
        count[(a[i]/e)%10]--;
    }
    for(int i=0;i<n;i++){
        a[i]=output[i];
    }
}
void radixsort(int a[],int n){
    int m=max(a,n);
    for(int e=1;m/e;e*=10){
        countsort(a,n,e);
    }
}
int main(){
    int i,n,a[20];
    printf("Enter the no of array element :");
    scanf("%d",&n);
    printf("Enter the array element:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    radixsort(a,n);
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}