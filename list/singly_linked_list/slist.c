#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

void initSlist(slinkedList *L)
{
	//L = (slinkedList *) malloc (sizeof(slinkedList));
	L->cur = NULL;
	L->head = NULL;
	L->tail = NULL;
	L->size = 0;
}
int size(slinkedList *L)
{
	return L->size;	
}

BOOL isEmpty(slinkedList *L)
{
	if(L->size != 0)
		return FALSE;
	return TRUE;
}

TYPE addfirst(slinkedList *L, TYPE element)
{
	Node* node;
	node = (Node *) malloc (sizeof(Node));
	node->element = element;
	node->next = NULL;
	if(isEmpty(L)) //if list is empty
		L->head = L->tail = node;
	else
	{
		node->next = L->head;
		L->head = node;
	}

	L->size++;

	return element;
}
void printElements(slinkedList *L)
{
	int i;
	Node* p = L->head;

	for(i=0;i<L->size;i++)
	{
		printf("%d ", p->element);
		p=p->next;
	}

}

TYPE addlast(slinkedList *L, TYPE element)
{
	Node* node;
	node = (Node *) malloc (sizeof(Node));

	node->element = element;
	node->next = NULL;

	if(isEmpty(L))
		L->head = L->tail = node;
	else
	{
		L->tail->next = node;
		L->tail=node;
	}

	L->cur = node;
	L->size++;

	return element;
}


void removeFirst(slinkedList *L, TYPE *ret)
{
	Node* temp;
	TYPE element;

	if(isEmpty(L))
	{
		printf("Empty List\n");
		return;
	}

	temp = L->head;
	element = temp->element;

	L->head = L->head->next;

	*ret = element;
	free(temp);

	L->size--;
}

void removeLast(slinkedList *L, TYPE *ret)
{
	Node* cursor;
	int i;
	if(isEmpty(L))
	{
		printf("Empty List\n");
		return;
	}

	cursor = L->head;
	for(i=0; i < L->size-2; i++)
	{
		cursor = cursor->next;
	}

	*ret = cursor->next->element;
	L->tail = cursor;
	free(cursor->next);
	L->size--;
}

void removeByIndex(slinkedList *L, TYPE *ret, int index)
{
	Node* cursor;
	int i;
	if(isEmpty(L))
	{
		printf("Empty List\n");
		return;
	}

	cursor = L->head;
	for(i=0; i < index-1; i++)
	{
		cursor = cursor->next;
	}

	cursor->next = cursor->next->next;
	*ret = cursor->next->element;

	free(cursor->next);
	L->size--;
}