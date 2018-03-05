#include<stdio.h>
#include<math.h>
int prod(int,int);
int no_OfDigit(int,int);
void main()
{
 	int m,n;
 	printf("Enter number1: \n");
 	scanf("%d",&m);
 	printf("Enter number2:\n");
 	scanf("%d",&n);
 	printf("multiplication of %d and %d is %d\n",m,n,prod(m,n));
}
int prod(int u,int v)
{
 	int x,y,w,z;
	int n,m,p,q,r;
 	n=no_OfDigit(u,v);
 	if(u==0 || v==0)
 	{
 	 return 0;
 	}
 	else if(n<=2)
 	{
 	 return (u*v);
 	}
 	else
 	{
 	 m=floor(n/2);
  	 w=u/pow(10,m);
  	 x=u%(int)pow(10,m);
  	 y=v/pow(10,m);
  	 z=v%(int)pow(10,m);
  	 p=prod(w,y);
  	 q=prod(x,z);
  	 r=prod(w+x,y+z);
  	 return p * pow(10,2*m) + (r-p-q) * pow(10,m) + q;
 	}
}
int no_OfDigit(int m,int n)
{
 	int max;
 	int b=0;
 	if(m>=n)
 	 max=m;
 	else
 	 max=n;
 	while(max>0)
	{
 	 max=max/10;
  	 b++;
 	}
 	return b;
}
