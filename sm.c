#include"stdio.h"
main()
{
	int a,b,sm=0;
	printf("Please enter the two numbers\n");
	scanf("%d%d",&a,&b);
	if((a<0)||(b<0))
	{
		if(a<0)
		{	while(a!=0)
			{
				sm+=b;
				a++;
			}	
		}
		else
		{
			while(b!=0)
			{
				sm+=a;
				b++;
			}
		}
		printf("The answer is %d\n",(-1*sm));	
	}
	else
	{
		while(a!=0)
		{
			sm+=b;
			a--;
		}
		printf("The answer is %d\n",sm);
	}
}