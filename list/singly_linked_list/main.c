#include <stdio.h>
#include "slist.h"
#include <stdlib.h>

int main()
{
	TYPE ret;
	slinkedList L;

	initSlist(&L);

	addfirst(&L, 3);

	addfirst(&L, 2);

	addfirst(&L, 1);

	addlast(&L,4);

	addlast(&L,5);

	printElements(&L);
	printf("\n");
	removeByIndex(&L, &ret, 2);
	printElements(&L);
	
	return 0;
}
