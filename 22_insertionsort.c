#include<stdio.h>

void printArray(int * A,int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Array is :%d\n ",A[i]);
    }
    printf("\n");
    
}

void insertionSort(int *A,int n)
{
    int key,j;
    for (int i = 1; i <= n-1; i++) //loop for passes
    {
        // int j=i-1;
         key =A[i];
         j=i-1;

         while (j>=0 && A[j]>key)
         {
            A[j+1]=A[j];
            j--;
         }
         A[j+1] =key;
    }
    
}

int main()
{
    int A[]={3,22,10,2,44,15};
    int n=6;
    printArray(A,n);
    insertionSort(A,n);
     printArray(A,n);
    return 0;
}