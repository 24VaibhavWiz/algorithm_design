#include"stdio.h"
void merge(int a[],int low,int mid,int high)
{
	int i=low;
	int j=mid+1;
	int k=low;
	int b[10];
	int l,count=0;
	while(i<=mid-k+1 && j<=high-mid)
	{
		if (a[i]<a[j])
		{
			b[k]=a[i];
			i++;j++;

		}
		else
		{
			b[k]=a[j];
			j++;i++;
			count+=1;
		}
		k++;
		printf("%d\n",count);
	}

	if (j>low)
	{
		for(l=i;l<=mid;l++)
		{
			b[k]=a[l];
			k++;
		}
	}
	else
	{
		for(l=j;l<=high;l++)
		{
			b[k]=a[l];
			k++;
		}
	}
}
merge_sort(int a[], int low, int high)
{
	int mid;
	if (low<high)
	{
		mid=(low+high)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
void main()
{
	int a[10],l,low,mid,high,b[10],k;
	int n,i,count;
	printf("enter the number of elements\n");
	scanf("%d",&n); 
	printf("enter the array elements\n");
	for(l=1;l<=n;l++)
	{
		scanf("%d", &a[l]);
	}
	merge_sort(a,low,high);
	{
		if (low<high)
		{
			mid=(low+high)/2;
			merge_sort(a,low,mid);
			merge_sort(a,mid+1,high);
			merge(a,low,mid,high);
		}
	}
	printf("the sorted elements are \n");
	for(i=1;i<=10;i++)
	{
		printf("%d",b[k]);
	}
}	

