#include<stdio.h>
#include<math.h>
struct point
{
	double x;
        double y;
};
int main()
{
	struct point a[10];
	struct point a1;
	struct point b1;
	double distance1 , closest ;
        int i = 0,j = 0;
	printf("enter your co-ordiantes x and y respectively for 10 points\n");
	for(i=0;i<10;i++)
	{
		printf("Enter for point %d \n",i+1);
		scanf("%lf%lf",&a[i].x,&a[i].y);
        }
	a1.x=a[0].x;
	a1.y=a[0].y;
        b1.x=a[1].x;
	b1.y=a[1].y;
	closest = 100000000.0;
	for(i=0;i<9;i++)
	{
		for(j=i+1; j<10;j++)
		{
			distance1 = sqrt(pow((a[i].x-a[j].x),2)+pow((a[i].y-a[j].y),2)); 
                        if(closest>distance1)
			{
				closest = distance1;
				a1.x=a[i].x;
				a1.y=a[i].y;
				b1.x=a[j].x;
				b1.y=a[j].y;
			}
		}
	}
	printf("The closest distance is : %lf \n",closest);
	printf("The corresponding points is : Point 1 : %.2lf , %.2lf \n",a1.x,a1.y);
	printf("The corresponding points is : Point 2 : %.2lf , %.2lf \n",b1.x,b1.y);
}
