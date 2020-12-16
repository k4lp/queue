#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

typedef struct _node {
	char data[SIZE];
	int top;
} node;

node *pu;

void initialize(){
	if(pu!=NULL)
		free(pu);
	pu = (node *)malloc(sizeof(node));
	pu->top = -1;
}

int isempty() {
	return (pu->top == -1);
}

int isfull() {
	return pu->top == SIZE -1;
}

void push(char x) {
	if(isfull())
		return;
	else {
		pu->data[++pu->top] = x;
	}
}

char pop() {
	if(isempty())
		return -1;
	else {
		return pu->data[pu->top--];
	}
}

char peek() {
	if(isempty())
		return -1;
	else {
		return pu->data[pu->top];
	}
}
