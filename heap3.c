#include "stdio.h"
void main()
{
    int heap[10], no, i, j, c, root, temp;
    printf("\n Enter no of elements :");
    scanf("%d", &no);
    printf("\n Enter the elements : \n");
    for (i = 0; i < no; i++)
       scanf("%d", &heap[i]);
    printf("Unsorted array : ");
    for(i=0;i<no;i++)
	printf(" %d ",heap[i]);
    printf("\n");
    for (i = 1; i < no; i++)
    {
        c = i;
        do
        {
            root = (c - 1) / 2;             
            if (heap[root] < heap[c]) 
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;
        } while (c != 0);
    }
 
    printf("Heap array : ");
    for (i = 0; i < no; i++)
        printf(" %d ", heap[i]);
    for (j = no - 1; j >= 0; j--)
    {
        temp = heap[0];
        heap[0] = heap[j]; 
        heap[j] = temp;
        root = 0;
        do 
        {
            c = 2 * root + 1;   
            if ((heap[c] < heap[c + 1]) && c < j-1)
                c++;
            if (heap[root]<heap[c] && c<j)   
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c;
        } while (c < j);
    } 
    printf("\nThe sorted array : ");
    for (i = 0; i < no; i++)
       printf(" %d ", heap[i]);
    printf("\n");
}
