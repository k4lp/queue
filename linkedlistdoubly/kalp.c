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
			ptr = ptr->next;
			pos--;
		}
		if(pos > 1) {
			printf("\nPosition number is out of bound.\nEntering as a last element.");
			addlast();
			return;
		}
		else if(ptr->next == NULL) {
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
		if(head!=NULL && (head == tail)) {
			free(head);
			head=tail=NULL;
			return;
		}
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
		node *ptr = head;
		while(ptr->next!=NULL) {
			ptr=ptr->next;
		}
		ptr=ptr->prev;
		free(ptr->next);
		tail = ptr;
	}
}

void delpos() {
	if(isempty()) {
		printf("\nList is empty.");
		return;
	}
	else {
		printf("\nEnter the position :- ");
		int pos = 0;
		scanf(" %d",&pos);
		if(pos == 1) {
			delfirst();
			return;
		}
		node *ptr = head;
		while((pos > 1) && (ptr->next != NULL)) {
			pos--;
			ptr=ptr->next;
		}
		if( pos >= 1){
			printf("\nPosition out of bound. Deleting last element.");
			dellast();
			return;
		}
		node *ptr1 = ptr->prev,*ptr2 = ptr->next;
		free(ptr);
		ptr1->next = ptr2;
		ptr2->prev = ptr1;
	}
}

void display() {
	if(isempty()) {
		printf("\nList is empty.");
		return;
	}
	else {
		node *ptr = head;
		while(ptr!=NULL) {
			printf("\n %d",ptr->data);
			ptr=ptr->next;
		}
	}
}

int main() {
	int choice = 0;
	while(choice!=9) {
		printf("\n1.Create.\n2.Add first\n3.Add last.\n4.Add position\n5.Del first\n6.Del last\n7.Del Pos\n8.Display\n9.Exit\nEnteer your choice :- ");
		scanf(" %d",&choice);
		switch(choice) {
		case 1 :
			create();
			break;
		case 2: addfirst();break;
		case 3: addlast();break;
		case 4: addpos();break;
		case 5: delfirst();break;
		case 6: dellast();break;
		case 7: delpos();break;
		case 8: display();break;
		case 9:
			printf("\nExiting....");
			break;
		default :
			printf("\nWrong choice.");
			break;
		}
	}
}
