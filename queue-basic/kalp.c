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
	scanf(" %d",&pu->size);
	pu->q = (int *)malloc(sizeof(int) * pu->size);
	pu->front = pu->rear = -1;
}

int isempty() {
	return pu->front == pu->rear;
}

int isfull() {
	return pu->rear == (pu->size - 1);
}

void enqueue(int x) {
	if(isfull())
		return ;
	else {
		pu->q[++pu->rear] = x;
	}
}

int dequeue() {
	if(isempty())
		return '$';
	else {
		return pu->q[++pu->front];
	}
}

void display() {
	int i=0;
	if(isempty())
		return ;
	else {
		for( i = pu->front +1 ; i <= pu->rear;i++)
			printf("\n %d",pu->q[i]);
	}
}

int main() {
	initialize();
	enqueue(3);
	display();
	enqueue(55);
	display();
	dequeue();
	display();
}
