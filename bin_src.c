#include"stdio.h"
int main()
{
	int i,last,first,middle,n,search,array[100];
	printf("Please enter the number of elements \n");
	scanf("%d",&n);
	printf("Please enter the array\n");
	for(i=0;i<=n;i++)
  	{
      		scanf("%d",&array[i]);
    	}
    	printf("The entered array is\n");
   	for(i=0;i<=n;i++)
    	{
        	printf("%d \n",array[i]);
   	}
  	printf("Please enter the value to be searched\n");
	scanf("%d",&search);
	first=0;
	last=n-1;
	while(first<=last)
	{
		middle=(last+first)/2;
		if (array[middle]<search)
			first=middle+1;
		else if(array[middle]==search)
		{
			printf("searched element found at location %d %d \n",search,middle+1);
			break;
		}
		else
		{
			last=middle-1;
			middle=(first+last)/2;
		}
         }
		if (first>last)
		{
			printf("oops!!! %d searched element not found\n",search);
	        }		
}