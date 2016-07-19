#ifndef _SLIST_H_
#define _SLIST_H_

#include <stdio.h>
#include <stdlib.h>
/*
#define TRUE 1
#define FALSE 0
*/
typedef int TYPE;
//typedef int BOOL;

typedef enum { FALSE, TRUE} BOOL;

typedef struct __list {
	struct __node *cur;
	struct __node *head;
	struct __node *tail;
	int size;
} slinkedList;

typedef struct __node {
	TYPE element;
	struct __node *next;
} Node;

void printElements(slinkedList *L);
void initSlist(slinkedList *L);
TYPE size(slinkedList *L);
BOOL isEmpty(slinkedList *L);
TYPE addfirst(slinkedList *L, TYPE element);
TYPE addlast(slinkedList *L, TYPE element);
void removeFirst(slinkedList *L, TYPE *ret);
void removeLast(slinkedList *L, TYPE *ret);
void removeByIndex(slinkedList *L, TYPE *ret, int index);

#endif //_SLIST_H_
