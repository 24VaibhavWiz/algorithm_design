#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
	struct node *prev;
    int n;
    struct node *next;
    struct node *link;
};
struct node *head = NULL, *x, *y, *z,*h,*temp,*temp1,*temp2,*temp4;
 
void insert1();
void insert2();
void insert3();
void traversebeg();
void traverseend(int);
void sort1();
void search1();
void update1();
void delete();
 
int count = 0;

void create();
void ins_at_beg();
void ins_at_pos();
void del_at_beg();
void del_at_pos();
void traverse();
void search();
void sort();
void update();
void rev_traverse(struct node *p);

main()
{
	char choice;
	printf("Please enter your choice for SINGLE LINKED LIST(s) OR DOUBLY LINKED LIST(d)\n");
	scanf(" %c",&choice);
	if (choice == 's')
	{
		int ch;
		printf("\n                       SINGLE LINKED LIST                          \n");
		printf("--------------------------------MENU-----------------------------------");
		printf("\n 1.Creation \n 2.Insertion at beginning \n 3.Insertion at remaining");
		printf("\n 4.Deletion at beginning \n 5.Deletion at remaining \n 6.Traverse");
		printf("\n 7.Search\n 8.Sort\n 9.Update\n 10.Reaverse\n 11.Exit\n");
		printf("-----------------------------------------------------------------------");
		while (1)
		{
			printf("\n Please enter  your choice:");
			scanf("%d", &ch);
			switch(ch)
			{
			case 1:
				create(); 
				break;
			case 2:
				ins_at_beg(); 
				break;
			case 3:
				ins_at_pos(); 
				break;
			case 4:
				del_at_beg(); 
				break;
			case 5:
				del_at_pos();
				break;
			case 6:
				traverse(); 
				break;
			case 7:
				search();
				break;
			case 8:
				sort();
				break;
			case 9:
				update();
				break;
			case 10:
				rev_traverse(head);
				break;
			case 11:
				exit(0);
			default:
				printf("Sorry wrong input\n");
			}
		}
	}
	else if (choice == 'd')
	{
		int ch1;
 
		h = NULL;
		temp = temp1 = NULL;
		printf("\n                       DOUBLY LINKED LIST                          \n");
		printf("--------------------------------MENU-----------------------------------");
		printf("\n 1.Insert at beginning \n 2.Insert at end\n 3.Insert at remaining");	
		printf("\n 4.Delete at remaining\n 5.Display from beginning\n 6.Display from end");
		printf("\n 7.Search for element\n 8.Sort the list\n 9.Update an element");
		printf("\n 10.Exit\n");
		printf("-----------------------------------------------------------------------");
		while (1)
		{
			printf("\n Please enter choice : ");
			scanf("%d", &ch1);
			switch (ch1)
			{
			case 1:
				insert1();
				break;
			case 2:
				insert2();
				break;
			case 3:
				insert3();
				break;
			case 4:
				delete();
				break;
			case 5:
				traversebeg();
				break;
			case 6:
				temp2 = h;
				if (temp2 == NULL)
					printf("\n Error : List empty to display ");
				else
				{
					printf("\n Reverse order of linked list is : ");
					traverseend(temp2->n);
				}
				break;
			case 7:
				search1();
				break;
			case 8:
				sort1();
				break;
			case 9:
				update1();
				break;
			case 10:
				exit(0);
			default:
				printf("\n Wrong choice menu");
			}
		}
	}
}	
  
/* TO create an empty node in double linked list*/

void create1()
{
    int data;
 
    temp =(struct node *)malloc(1*sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\n Enter value to node : ");
    scanf("%d", &data);
    temp->n = data;
    count++;
}
 
/*  TO insert at beginning */

void insert1()
{
    if (h == NULL)
    {
        create1();
        h = temp;
        temp1 = h;
    }
    else
    {
        create1();
        temp->next = h;
        h->prev = temp;
        h = temp;
    }
}
 
/* To insert at end */

void insert2()
{
    if (h == NULL)
    {
        create1();
        h = temp;
        temp1 = h;
    }
    else
    {
        create1();
        temp1->next = temp;
        temp->prev = temp1;
        temp1 = temp;
    }
}
 
/* To insert at any position */

void insert3()
{
    int pos, i = 2;
 
    printf("\n Enter position to be inserted : ");
    scanf("%d", &pos);
    temp2 = h;
 
    if ((pos < 1) || (pos >= count + 1))
    {
        printf("\n Position out of range to insert");
        return;
    }
    if ((h == NULL) && (pos != 1))
    {
        printf("\n Empty list cannot insert other than 1st position");
        return;
    }
    if ((h == NULL) && (pos == 1))
    {
        create1();
        h = temp;
        temp1 = h;
        return;
    }
    else
    {
        while (i < pos)
        {
            temp2 = temp2->next;
            i++;
        }
        create1();
        temp->prev = temp2;
        temp->next = temp2->next;
        temp2->next->prev = temp;
        temp2->next = temp;
    }
}
 
/* To delete an element */

void delete()
{
    int i = 1, pos;
 
    printf("\n Enter position to be deleted : ");
    scanf("%d", &pos);
    temp2 = h;
 
    if ((pos < 1) || (pos >= count + 1))
    {
        printf("\n Error : Position out of range to delete");
        return;
    }
    if (h == NULL)
    {
        printf("\n Error : Empty list no elements to delete");
        return;
    }
    else
    {
        while (i < pos)
        {
            temp2 = temp2->next;
            i++;
        }
        if (i == 1)
        {
            if (temp2->next == NULL)
            {
                printf("\n Node deleted from list");
                free(temp2);
                temp2 = h = NULL;
                return;
            }
        }
        if (temp2->next == NULL)
        {
            temp2->prev->next = NULL;
            free(temp2);
            printf("\n Node deleted from list");
            return;
        }
        temp2->next->prev = temp2->prev;
        if (i != 1)
            temp2->prev->next = temp2->next;    /* Might not need this statement if i == 1 check */
        if (i == 1)
            h = temp2->next;
        printf("\n Node deleted");
        free(temp2);
    }
    count--;
}
 
/* Traverse from beginning */

void traversebeg()
{
    temp2 = h;
 
    if (temp2 == NULL)
    {
        printf(" List empty to display \n");
        return;
    }
    printf("\n Linked list elements from begining : ");
 
    while (temp2->next != NULL)
    {
        printf(" %d ", temp2->n);
        temp2 = temp2->next;
    }
    printf(" %d ", temp2->n);
}
 
/* To traverse from end recursively */

void traverseend(int i)
{
    if (temp2 != NULL)
    {
        i = temp2->n;
        temp2 = temp2->next;
        traverseend(i);
        printf(" %d ", i);
    }
}
 
/* To search for an element in the list */

void search1()
{
    int data, count = 0;
    temp2 = h;
 
    if (temp2 == NULL)
    {
        printf("\n Error : List empty to search for data");
        return;
    }
    printf("\n Enter value to search : ");
    scanf("%d", &data);
    while (temp2 != NULL)
    {
        if (temp2->n == data)
        {
            printf("\n Data found in %d position",count + 1);
            return;
        }
        else
             temp2 = temp2->next;
            count++;
    }
    printf("\n Error : %d not found in list", data);
}
 
/* To update a node value in the list */

void update1()
{
    int data, data1;
 
    printf("\n Enter node data to be updated : ");
    scanf("%d", &data);
    printf("\n Enter new data : ");
    scanf("%d", &data1);
    temp2 = h;
    if (temp2 == NULL)
    {
        printf("\n Error : List empty no node to update");
        return;
    }
    while (temp2 != NULL)
    {
        if (temp2->n == data)
        {
 
            temp2->n = data1;
            traversebeg();
            return;
        }
        else
            temp2 = temp2->next;
    }
 
    printf("\n Error : %d not found in list to update", data);
}
 
/* To sort the linked list */

void sort1()
{
    int i, j, x;
 
    temp2 = h;
    temp4 = h;
 
    if (temp2 == NULL)
    {
        printf("\n List empty to sort");
        return;
    }
 
    for (temp2 = h; temp2 != NULL; temp2 = temp2->next)
    {
        for (temp4 = temp2->next; temp4 != NULL; temp4 = temp4->next)
        {
            if (temp2->n > temp4->n)
            {
                x = temp2->n;
                temp2->n = temp4->n;
                temp4->n = x;
            }
        }
    }
    traversebeg();
} 
/*Function to create a new single linked list*/

void create()
{
    char c;
    x = (struct node*)malloc(sizeof(struct node));
    printf("\n Enter the data:");
    scanf("%d", &x->data);
    x->link = x;
    head = x;
    printf("\n If you wish to continue press y otherwise n:");
    scanf(" %c", &c);
    while (c != 'n')
    {
        y = (struct node*)malloc(sizeof(struct node));
        printf("\n Enter the data:");
        scanf("%d", &y->data);
        x->link = y;
        y->link = head;
        x = y;
        printf("\n If you wish to continue press y otherwise n:");
        scanf(" %c", &c); 
    }
}
 
/*Function to insert an element at the begining of the list*/
 
void ins_at_beg()
{
    x = head;
    y = (struct node*)malloc(sizeof(struct node));
    printf("\n Enter the data:");
    scanf("%d", &y->data);
    while (x->link != head)
    {
        x = x->link;
    }
    x->link = y;
    y->link = head;
    head = y;
}
 
/*Function to insert an element at any position the list*/
 
void ins_at_pos()
{
    struct node *ptr;
    int c = 1, pos, count = 1;
 
    y = (struct node*)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("\n Cannot enter an element at this place");
    }
    printf("\n Enter the data:");
    scanf("%d", &y->data);
    printf("\n Enter the position to be inserted:");
    scanf("%d", &pos);
    x = head;
    ptr = head;
    while (ptr->link != head)
    {
        count++;
        ptr = ptr->link;
    }
    count++;
    if (pos > count)
    {
        printf("\n OUT OF BOUND");
        return;
    }
    while (c < pos)
    {
        z = x;
        x = x->link;
        c++;
    }
    y->link = x;
    z->link = y;
}
 
/*Function to delete an element at any begining of the list*/
 
void del_at_beg()
{
    if (head == NULL) 
        printf("\n List is empty");
    else
    {
        x = head;
        y = head;
        while (x->link !=  head)
        {
            x = x->link;
        }
        head = y->link;
        x->link = head;
        free(y);
    }
}
 
/*Function to delete an element at any position the list*/
 
void del_at_pos()
{
    if (head == NULL)
        printf("\n List is empty");
    else
    {
        int c = 1, pos;
        printf("\n Enter the position to be deleted:");
        scanf("%d", &pos);
        x = head;
        while (c < pos)
        {
            y = x;
            x = x->link;
            c++;
        }
        y->link = x->link;
        free(x);
    }
}
 
/*Function to display the elements in the list*/
 
void traverse()
{
    if (head == NULL)
        printf("\n List is empty");
    else
    {
        x = head;
        while (x->link !=  head)
        { 
            printf("%d->", x->data);
            x = x->link;
        }
        printf("%d", x->data);
    }
}
 
/*Function to search an element in the list*/
 
void search()
{
    int search_val, count = 0, flag = 0;
    printf("\n Enter the element to search\n");
    scanf("%d", &search_val);
    if (head == NULL)
        printf("\n List is empty nothing to search");
    else
    {
        x = head;
        while (x->link !=  head)
        {
            if (x->data == search_val)
            {
                printf("\n The element is found at %d", count);
                flag = 1;
                break;
            }
            count++;
            x = x->link;
        }
        if (flag == 0)
        {
            printf("\n Element not found");
        }
 
    }
}
 
/*Function to sort the list in ascending order*/
 
void sort()
{
    struct node *ptr, *nxt;
    int temp;
 
    if (head == NULL)
    {
        printf("\n Empty linkedlist");
    }
    else
    {
        ptr = head;
        while (ptr->link !=  head)
        {
            nxt = ptr->link;
            while (nxt !=  head)
            {
                if (nxt !=  head)
                {
                    if (ptr->data > nxt->data)
                    {
                        temp = ptr->data;
                        ptr->data = nxt->data;
                        nxt->data = temp;
                    }
                }
                else
                {
                    break;
                }
                nxt = nxt->link;
            }
            ptr = ptr->link;
        }
    }
}
 
/*Function to update an element at any position the list*/

void update()
{
    struct node *ptr;
    int search_val;
    int replace_val;
    int flag = 0;
 
    if (head == NULL)
    {
        printf("\n Empty list");
    }
    else
    {
        printf("\n Enter the value to be edited\n");
        scanf("%d", &search_val);
        fflush(stdin);
        printf("\n Enter the value to be replace\n");
        scanf("%d", &replace_val);
        ptr = head;
        while (ptr->link !=  head)
        {
            if (ptr->data == search_val)
            {
                ptr->data = replace_val;
                flag = 1;
                break;
            }
            ptr = ptr->link;
        }
        if (ptr->data == search_val)
        {
            ptr->data = replace_val;
            flag = 1;
        }
        if (flag == 1)
        {
            printf("\n UPdate sucessful");
        }
        else
        {
            printf("\n Update not successful");
        }
    }
}
 
/*Function to display the elements of the list in reverse order*/
 
void rev_traverse(struct node *p)
{
    int i = 0;
 
    if (head == NULL)
    {
        printf(" Empty linked list\n");
    }
    else
    {
        if (p->link !=  head)
        {
            i = p->data;
            rev_traverse(p->link);
            printf(" %d", i);
        }
        if (p->link == head)
        {
            printf(" %d", p->data);
        }
    }
}