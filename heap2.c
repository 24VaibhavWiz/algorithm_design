#include"stdio.h"
void swap(int x,int y)
{
	int temp;
	temp=x;
	x=y;
	y=temp;
}
void heapify(int arr[], int n, int i)
{
    int largest = i;  
    int l = 2*i + 1;  
    int r = 2*i + 2; 
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        heapify(arr, n, largest);
    }
}
 
void heapSort(int arr[], int n)
{
	int i;
   
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void printArray(int arr[], int n)
{
    int i;
    for (i=0; i<n; ++i)
        printf("%d",arr[i]);
    printf("\n");
}

int main()
{
    int arr[20]; 
    int n;
    int i;
    printf("Please enter the length of array\n");
    scanf("%d",&n);
    printf("Please enter the array\n");
    for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
    printf("Unsorted array is \n");
    printArray(arr, n);
    heapSort(arr, n);
    printf("Sorted array is \n");
    printArray(arr, n);
}
