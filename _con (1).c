#include <iostream>
#include <stdlib.h>
int main ()
{
	char *  itoa ( int value, char * str, int base );
    int i;
    char buffer [33];
    cout<< "Enter a number: ";
    scanf ("%d",&i);
    itoa (i,buffer,10);
    cout<< "decimal: %s\n",buffer;
    itoa (i,buffer,16);
    cout<< ("hexadecimal: %s\n",buffer);
    itoa (i,buffer,2);
    cout<< "binary: %s\n",buffer;
}
