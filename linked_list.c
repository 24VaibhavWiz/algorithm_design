#include"stdio.h"
#include"stdlib.h"
struct node
{
	int data;
	struct node *next;
}
*start=NULL;
void create()
{
	char ch;
	 while(ch!='n')
 	 {
  		struct node *new_node,*current;
  		new_node=(struct node *)malloc(sizeof(struct node));
         	printf("Enter the data : \n");
 	        scanf("%d",&new_node->data);
  		new_node->next=NULL;
  		if(start==NULL)
  		{
		  start=new_node;
		  current=new_node;
 	        }
 		else
  		{
 		  current->next=new_node;
 		  current=new_node;
 		}
 		printf("\nDo you want to creat another : ");
 		scanf(" %c",&ch);
 	}
	
}
void display()
{
	struct node *new_node;
 	printf("The Linked List : \n");
 	new_node=start;
 	while(new_node!=NULL)
   	{
  		 printf("%d ",new_node->data);
  		 new_node=new_node->next;
   	}
  	printf("NULL");
}
void main()
{
	create();
	display();
}
