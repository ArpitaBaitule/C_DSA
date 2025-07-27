#include<stdio.h>

void display(int arr[],int n)    //display function
{    //Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}
void indDeletion(int arr[],int size,int capacity,int index)
{
    if(index>=capacity)
    {
        printf("cannot perform deletion");
    }
    for (int i =index ; i < size-1; i++) //   i=3 ; i<4
    {
        arr[i]=arr[i+1];                 //   arr[3]=arr[4]  means {11,32,4,5}
    }
    
}

int main()
{               // 0 ,1, 2, 3,4
     int arr[100]={11,32,4,14,5};
     int size=5,index=3;
     display(arr,size);

     indDeletion(arr,size,100,index); //method
     size-=1;
     display(arr,size);

     return 0;
}