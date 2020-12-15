#include<stdio.h>
#include<stdlib.h>

typedef struct _node {
	int data;
	struct _node *next,*prev;
} node;

node *tail= NULL, *head = NULL;

void create() {
	if(head == NULL) {
		node *tmp = (node *)malloc(sizeof(node));
		printf("\nEnter the element :- ");
		scanf(" %d",&tmp->data);
		tmp->prev = NULL;
		tmp->next = NULL;
		head = tmp;
		tail = head;
	}
	else {
		node *ptr=head;
		while(ptr->next!= NULL)
			ptr=ptr->next;
		node *tmp = (node *)malloc(sizeof(node));
		printf("\nEnter the element :- ");
		scanf(" %d",&tmp->data);
		ptr->next = tmp;
		tmp->next = NULL;
		tmp->prev = tmp;
		tail = tmp;
	}
}

int isempty() {
	return head == NULL;
}

void addfirst() {
	if(isempty())
		create();
	else {
		node *tmp = (node *)malloc(sizeof(node));
		printf("\nEnteer the element :- ");
		scanf(" %d",&tmp->data);
		tmp->next = head;
		tmp->prev = NULL;
		head = tmp;
	}
}
