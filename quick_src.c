#include"stdio.h"
void quicksort(int[],int,int);
int partition(int[],int,int);
int main(){
	int i,c,n,j;
	printf("Enter the number of elements to be sorted: ");
	scanf("%d",&n);
	int A[n];
	for(i=0;i<n;i++)
	    scanf("%d",&A[i]);
	quicksort(A,0,n-1);
        printf("Sorted elements: ");
	for(i=0;i<n;i++)
	 printf("%d ",A[i]);										
}
void quicksort(int a[],int l,int r){
	int j;
	if(l<r){
		j=partition(a,l,r);
		quicksort(a,l,j-1);
		quicksort(a,j+1,r);
		}
}
int partition(int a[],int l,int r){
		int pivot,i,j,t;
		pivot=a[l];
		i=l;
		j=r+1;
		while(1)
{
	do
	      ++i;
	while(a[i]<=pivot && i<=r);
	do
		--j;
	while(a[j]>pivot)
	if(i>=j)
	break;
	else
	{
		t=a[i];
		a[i]=a[j];
		a[j]=t;
	}
	t=a[l];
	a[l]=a[j];
	a[j]=t;
	return j;
}