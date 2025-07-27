#include<stdio.h>

void printArray(int * A,int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Array is :%d \n",A[i]);
    }
    
}

void bubbleSort(int * A,int n)
{
int temp;
int isSorted =0;
for (int i = 0; i < n-1; i++) //for passes
{
    printf("Working on pass number %d\n",i+1);
    isSorted =1;
    for (int j = 0; j < n-1-i; j++) //for comparison
    {
        if(A[j]>A[j+1])
        {
            temp=A[j];
            A[j]=A[j+1];
            A[j+1]=temp;
             isSorted =0;
        }
    }
    if(isSorted)
    {
        return;
    }
    
}

}

int main()
{
    int A[]={12,54,65,7,23,9};
    int n=6;
    printArray(A,n);
    bubbleSort(A,n);
    printf("Array After BubbleSorting :\n");
    printArray(A,n);
    return 0;
}