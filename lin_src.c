#include"stdio.h"
int main()
{
	int n;
	int array[n];
	int i,keynum,search=0,found=0;
	printf("Please enter the size of the array\n");
	scanf("%d",&n);
	printf("Please enter the array\n");
	for(i=0;i<=n;i++)
	{
		scanf("%d",&array[i]);
	}
	printf("The entered array is\n");
	for(i=0;i<=n;i++)
	{
		printf("%d\n" ,array[i]);
	}
	printf("Please enter the value to be searched\n");
	scanf("%d",&keynum);
	for(i=0;i<=n;i++)
	{
		if(keynum == array[i])
		{
			search =1;
			found=array[i];
			break;
		}
	}
	if (found==1)
	{
		printf("searched element found %d \n",found);
	}
	else
	{
		printf("searched element not found\n");
	}
}