/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int gcd(int a,int b)
{
    if(b==0)
    return a;
    else
    return gcd(b,a%b);
}
void leftRotate(int arr[],int d,int n)
{
    d=d%n;
    int i,j,k,temp;
    int g_c_d=gcd(d,n);
    for(i=0;i<g_c_d;i++)
    {
        j=i;
        temp=arr[i];
        while(1)
        {
            k=j+d;
            if(k>=n)
            k=k-n;
            if(k==i)
            break;
            arr[j]=arr[k];
            j=k;
        }
        arr[j]=temp;
    }
}
void rightRotate(int arr[],int d,int n)
{
    d=d%n;
    reversal(arr,0,n-1);
    reversal(arr,0,d-1);
    reversal(arr,d,n-1);
}
void reversal(int arr[],int start,int end)
{
    while(start<end)
    {
        swap(&arr[start],&arr[end]);
        start++;
        end--;
    }
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
int SearchElement(int arr[],int l,int h,int k)
{
    int mid=(l+h)/2;
    if(l>h)
        return -1;

    if(arr[mid]==k)
    {
        printf("found it at %d",mid);
        return mid;
    }
    if(arr[l]<=arr[mid])
    {
        if(k>=arr[l]&&k<=arr[mid])
            return SearchElement(arr,l,mid-1,k);
        return SearchElement(arr,mid+1,h,k);

    }
    if(k>=arr[mid]&&k<=arr[h])
        return SearchElement(arr,mid+1,h,k);
    return SearchElement(arr,l,mid-1,k);
}
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    leftRotate(arr, 3, 7);
    printArray(arr, 7);
    rightRotate(arr,3,7);
    printf("\n");
    printArray(arr,7);
    int i=SearchElement(arr,0,7,5);
    if(i==0)
        printf("found");
    getchar();
    return 0;
}
