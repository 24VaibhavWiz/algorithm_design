#include"stdio.h"
#include"string.h"
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
       char name[50];
       struct student s[100];
       double total=0;
       int i=0,no;
       printf("Please enter the total number of students\n");
       scanf("%d",&no);
       double avg,avg1,avg2,avg3,avg4;    
       for(i=0;i<no;i++)
       {
	    printf("Enter the student name\n");
            scanf("%s",&name);
            printf("Enter Marks in Five Subjects = \n");
            scanf("%lf%lf%lf%lf%lf",& s[i].sub1,&s[i].sub2,&s[i].sub3,&s[i].sub4,&s[i].sub5);
            total=s[i].sub1+s[i].sub2+s[i].sub3+s[i].sub4+s[i].sub5;
	    avg=avg+s[i].sub1;
	    avg1=avg1+s[i].sub2;
	    avg2=avg2+s[i].sub3;
	    avg3=avg3+s[i].sub4;
	    avg4=avg4+s[i].sub5;
	    printf("%s \n",(name));
            printf("\nTotal marks of the Student = %.lf\n",total);
        }  
	printf("The avg of sub1 is %f\n",avg/no);     
	printf("The avg of sub2 is %f\n",avg1/no); 
	printf("The avg of sub3 is %f\n",avg2/no);
	printf("The avg of sub4 is %f\n",avg3/no);
	printf("The avg of sub5 is %f\n",avg4/no);   
}
