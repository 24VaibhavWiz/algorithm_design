#include<stdio.h>
struct student
{
    double sub1;
    double sub2;
    double sub3;
    double sub4;
    double sub5;
};
main()
{
       struct student s[10];
       double total=0;
       int i=0;
       char name;
       for(i=0;i<=4;i++)
       {
	    printf("Enter the student name\n");
            scanf(" %c",&name);
            printf("\nEnter Marks in Five Subjects = ");
            scanf("%d%d%d%d%d",& s[i].sub1,&s[i].sub2,&s[i].sub3,&s[i].sub4,&s[i].sub5);
            total=s[i].sub1 + s[i].sub2 + s[i].sub3 + s[i].sub4 + s[i].sub5;
            printf("\nTotal marks of s[%d] Student= %.lf\n",i,total);
        }           
}
