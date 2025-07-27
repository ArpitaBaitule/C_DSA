#include <stdio.h>

int linear(int arr[], int size, int element)
{
      for (int i = 0; i < size; i++)
      {
            if (arr[i] == element)
            {
                  return i;
            }
      }

      return -1;
}

int binary(int arr[], int size, int element)
{
      int low=0, high=size-1, mid;
      while (low <= high)
      {
            mid = (low + high) / 2;
            if (arr[mid] == element)
            {
                  return mid;
            }
            else if (arr[mid] < element)
            {
                  low = mid + 1;
            }
            else if (arr[mid] > element)
            {
                  high = mid - 1;
            }
            else
            {
                  printf("The element is not found");
            }
      }
      return -1;
}

int main()
{      //linear search
      // int arr[] = {1, 22, 3, 4, 44, 5, 66, 7, 88};
      // int size = sizeof(arr) / sizeof(int);
      // int element = 66;
      // int searchIndex = linear(arr, size, element);
      // printf("The element %d was found at index %d \n", element, searchIndex);

      //binary search
      int arr[] = {10,20,25,26,33,41,46,58,62,71,79};
       int size = sizeof(arr) / sizeof(int);
       printf("The size of array is %d",size);
       int element = 26;
      int searchIndex2 = binary(arr, size, element);
      printf("\nThe element %d was found at index %d \n", element, searchIndex2);
      return 0;
}