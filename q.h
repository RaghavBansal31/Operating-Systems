#include <stdlib.h>

#include "TCB.h"



struct TCB_t *NewItem();

void InitQueue(struct TCB_t **newHead);

void AddQueue(struct TCB_t **head, struct TCB_t *item);

struct TCB_t *DelQueue(struct TCB_t **head);

void RotateQ(struct TCB_t **head);



int count;

struct TCB_t *first, *last;



TCB_t *NewItem() {

	TCB_t *q;

	q = (TCB_t *)malloc(sizeof(TCB_t ));

	return q;

}



void InitQueue(struct TCB_t **newHead) {

	first = *newHead;

	count = 0;

}



void AddQueue(struct TCB_t **head, struct TCB_t *item)

{

	if(count == 0) {

	*head = item;



	(*head)->prev = *head;

	last = (*head)->prev;



	(*head)->next = *head;

	first = *head;

	}

	else {

	last->next = item;

	item->prev = last;

        last = item;

	}



	first->prev = last;

	last->next = first;

	count++;

}



struct TCB_t *DelQueue(struct TCB_t **head)

{

	struct TCB_t *temp;

	temp = *head;

	*head = (*head)->next;

	first = *head;

	first->prev = last;

	last->next = first;



	count--;

	return temp;

}



void RotateQ(struct TCB_t **head)

{

	AddQueue(head, DelQueue(head));

}
