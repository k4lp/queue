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

void addlast() {
	if(isempty())
		create();
	else {
		node *tmp = (node *)malloc(sizeof(node));
		printf("\nEnter the element :- ");
		scanf(" %d",&tmp->data);
		node *ptr = head;
		tail->next = tmp;
		tmp->next = NULL;
		tmp->prev = tail;
		tail = tmp;
	}
}

void addpos() {
	if(isempty()) {
		printf("\nLinked list is empty. Proceeding you to enter the first element.");
		create();
		return;
	}
	else {
		printf("\nEnter the position :- ");
		int pos = 0;
		scanf(" %d",&pos);
		if(pos == 1){
			addfirst();
			return;
		}
		node *ptr = head;
		pos --;
		while((pos > 1) && (ptr->next != NULL)) {
			ptr->next;
			pos--;
		}
		if(pos > 2) {
			printf("\nPosition number is out of bound.\nEntering as a last element.");
			addlast();
			return;
		}
		else if(pos > 1) {
			addlast();
			return;
		}
		node *ptr1 = ptr->next;
		node *tmp = (node *)malloc(sizeof(node));
		printf("\nEnter the element :- ");
		scanf(" %d",&tmp->data);
		tmp->prev = ptr;
		tmp->next = ptr1;
		ptr->next = tmp;
		ptr1->prev = tmp;
	}
}

void delfirst() {
	if(isempty()) {
		printf("\nList is empty.");
		return;
	}
	else {
		head = head ->next;
		free(head->prev);
		head->prev = NULL;
	}
}

void dellast() {
	if(isempty()) {
		printf("\nList is empty.");
		return;
	}
	else {
		tail = tail->prev;
		free(tail->next);
		tail->next = NULL;
	}
}
