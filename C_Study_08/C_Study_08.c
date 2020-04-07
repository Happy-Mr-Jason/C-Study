/*
	#Linked lists
	
	Linked lists have a few advantages over arrays:
	1. Items can be added or removed from the middle of the list
	2. There is no need to define an initial size

	However, linked lists also have a few disadvantages:

    1. There is no "random" access 
		- it is impossible to reach the nth item in the array without first iterating over all items up until that item. 
		  This means we have to start from the beginning of the list and count how many times we advance in the list 
		  until we get to the desired item.
	2. Dynamic memory allocation and pointers are required, 
	   which complicates the code and increases the risk of memory leaks and segment faults.
	3. Linked lists have a much larger overhead over arrays, 
	   since linked list items are dynamically allocated (which is less efficient in memory usage) 
	   and each item in the list also must store an additional pointer.

	# type
	1. Single Linked lists : it can be searching from start to end. only 1 direction(head -> next -> next....)
	2. Double Linked lists : it can be searching from start to end and from end to start. two direction (head -> next -> next... prev -> prev -> head)
*/

#include <stdio.h>
#include <malloc.h>

//define node
typedef struct node {
	int number;
	struct node* p_next;
}NODE;

void AddNumber1(NODE** pp_head, int data);
void AddNumber2(NODE** pp_head, NODE ** pp_tail, int data);

int main(int argc, char* arg[]) {
	NODE* p_head = NULL;  //header pointer for saving first node address 
	//add nodes
	p_head = (NODE*)malloc(sizeof(NODE));
	p_head->number = 12;
	p_head->p_next = NULL;
	p_head->p_next = (NODE*)malloc(sizeof(NODE));
	p_head->p_next->number = 15;
	p_head->p_next->p_next = NULL;

	//searching list up to final node, move pointer to last position
	NODE* p = p_head;
	while (NULL != p->p_next) {
		p = p->p_next;
	}

	//make function method
	NODE* p_head2 = NULL;
	NODE* p_tail = NULL;
	AddNumber1(&p_head2, 11); //without tail pointer
	AddNumber2(&p_head2,&p_tail, 11); //without tail pointer

	//remove list
	NODE* p2 = p_head2, * p_save_next;
	while (NULL != p2) {
		p_save_next = p2->p_next;
		free(p2);
		p2 = p_save_next;
	}
	p_head2 = p_tail = NULL;
}

void AddNumber1(NODE** pp_head, int data) {
	NODE* p;
	if (NULL != *pp_head) {
		p = *pp_head;
		while (NULL != p->p_next) {
			p = p->p_next;
		}
		p->p_next = (NODE*)malloc(sizeof(NODE));
		p = p->p_next;
	}
	else {
		*pp_head = (NODE*)malloc(sizeof(NODE));
		p = *pp_head;
	}
	p->number = data;
	p->p_next = NULL;
}

void AddNumber2(NODE** pp_head,NODE **pp_tail, int data) {
	if (NULL != *pp_head) {
		(*pp_tail)->p_next = (NODE*)malloc(sizeof(NODE));
		*pp_tail = (*pp_tail)->p_next;
	}
	else {
		*pp_head = (NODE*)malloc(sizeof(NODE));
		*pp_tail = *pp_head;
	}
	(*pp_tail)->number = data;
	(*pp_tail)->p_next = NULL;
}