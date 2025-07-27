#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

int maximum(int A[], int n)
{
    int max=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max=A[i];
        }
        
    }
    return max;
}
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d  ", A[i]);
    }
    printf("\n");
}


void countSort(int * A,int n)
{
    int i,j;
    //find the maximum element in A
    int max =maximum(A,n);

    //Create the count array
    int * count = (int*) malloc((max+1)* sizeof(int));

  //Initialize the array element to 0
    for (int i = 0; i < max+1; i++)
    {
        count[i]=0;
    }

    //Increment the corresonding index in the count array
    for (int i = 0; i < n; i++)
    {
        count[A[i]]= count[A[i]]+1;
    }
    
    i=0; //counter for count array
    j=0; //counter for given array

    while (i<=max)
    {
        if (count[i]>0)
        {
            A[j]=i;
            count[i]--;
            j++;
        }
        else
        {
            i++;
        }
        
    }
    

}
int main()
{
    int A[] = {3, 22,0, 9, 2, 44, 8};
    int n = 7;
    printArray(A, n);
    countSort(A, n);
    printArray(A, n);
    return 0;
}