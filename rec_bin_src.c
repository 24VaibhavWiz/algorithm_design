#include "stdio.h"
int binarySearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
        if (arr[mid] == x)  
            return mid;
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid-1, x);
        return binarySearch(arr, mid+1, r, x);
   }
   return -1;
}                                            
int main(void)
{
	int x;
  	int arr[] = {11,22,33,44,55,66,77,88,99};
   	int n = sizeof(arr)/ sizeof(arr[0]);
   	printf("Please enter the value to be searched\n");
   	scanf("%d",&x);
   	int result = binarySearch(arr, 0, n-1, x);
   	(result == -1)?.0printf("Element is not present in array\n"):printf("Element found and is present at index %d\n", 	  result); 
}