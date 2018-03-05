#include<stdio.h>
#include<string.h>
struct student
{
	char name[100];
        int roll;
	float marks;
};
int main()
{
	struct student a;
        printf("Enter your name and number\n");
	scanf("%s",a.name);
	scanf("%d",&a.roll);
        scanf("%f",&a.marks);
        printf("%s\n",a.name);
        printf("%d\n",a.roll);
        printf("%f\n",a.marks);

} 
