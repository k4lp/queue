#include<stdio.h>
#include<stdlib.h>

typedef struct _node {
	int size,rear,front,*q;
} node;

node *pu;

void initialize() {
	if(pu!=NULL)
		free(pu);
	pu = (node *)malloc(sizeof(node));
	printf("\nEnter the size of the queue :- ");
	scanf(" %d", &pu->size);
	pu->q = (int *)malloc(sizeof(int) * pu->size);
	pu->front = pu->rear = 0;
}

int isempty() {
	return pu->front == pu->rear;
}

int isfull() {
	return ( (pu->rear +1 ) % pu->size == pu->front);
}

int dequeue() {
	if(isempty())
		return '$';
	else
		return pu->q[pu->front = (pu->front +1)% pu->size];
}
