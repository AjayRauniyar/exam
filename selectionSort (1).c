#include<stdio.h>
#include<sys/time.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selectionSort(int a[],int n){
    int i,j,minIndex;
    for(i=0;i<n-1;i++){
        minIndex=i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[minIndex])
                minIndex=j;
        }
        if(minIndex!=i)
                swap(&a[minIndex],&a[i]);
    }
}
void calc(int a[],int n){
    clock_t start,end;
    double time;
    start=clock();
    selectionSort(a,n);
    end=clock();
    time=((double)(end-start)/1000000.0);
    printf("%lf\t",time);
}
void main(){
    int n=10000,i,j,k=1;
    printf("Inputs\tAscending\tRandom\tDescending\n");
    while(k<5){
        int a[n];
        printf("%d\t",n);
        for(int i=0;i<n;i++)
            a[i]=i;
        calc(a,n);
        for(int i=0;i<n;i++)
            a[i]=rand()%(n*10);
        calc(a,n);
        for(j=0, i=n;i>0;i--,j++)
            a[j]=i;
        calc(a,n);
        j++;
        n*=2;
        printf("\n");    
    }
}