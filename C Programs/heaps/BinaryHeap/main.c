/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
void swap(int *,int *);
void heapify(int arr[],int n,int i);
void heapSort(int arr[],int n);
void PrintArray(int arr[],int n);
int main()
{
    int arr[]={5,6,11,14,67,12,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    heapSort(arr,n);
    printf("Sorted Array is: ");
    PrintArray(arr,n);
    return 0;
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int arr[],int n,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n&&arr[left]<arr[largest])
    {
        largest=left;
    }
    if(right<n&&arr[right]<arr[largest])
    largest=right;
    if(largest!=i)
    {
    swap(&arr[i],&arr[largest]);
    heapify(arr,n,largest);
    }
}
void heapSort(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--)
    {
        swap(&arr[i],&arr[0]);
        heapify(arr,i,0);
    }
}
void PrintArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
