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
	if(pu==NULL){
		printf("\nYou need to initialize the queue first.");
		return '$';
	}
	return pu->front == pu->rear;
}

int isfull() {
	if(pu == NULL) {
		printf("\nYou need to initialize the queue first.");
		return '$';
	}
	return ( (pu->rear +1 ) % pu->size == pu->front);
}

int dequeue() {
	if(isempty()){
		printf("\nQueue is empty. Enqueue some elements first.");
		return '$';
	}
	else
		return pu->q[pu->front = (pu->front +1)% pu->size];
}

void enqueue(int x) {
	if(isfull()) {
		printf("\nQueue is full. Try dequeuing some elements.\n");
		return ;
	}
	else {
		pu->q[pu->rear = (pu->rear +1) % pu->size] = x;
	}
}

void display() {
	if(isempty()) {
		printf("\nQueue is empty.\n");
		return;
	}
	else {
		int i =0;
		for( i = pu->front +1 ; i != (pu->rear + 1)%pu->size ; i = ( i + 1) % pu->size)
			printf("\n %d",pu->q[i]);
	}
}

int main() {
	int choice = 0;
	do {
		printf("\n1.Enqueue.\n2.Dequeue\n3.Display\n4.Initialize.\n5.Exit \nEnter your choice :- ");
		scanf(" %d",&choice);
		switch(choice) {
		case 1 :
			printf("\nEnter the number to add :- ");
			int x = 0;
			scanf(" %d",&x);
			enqueue(x);
			break;
		case 2 :
			if(isempty()) {
				printf("\nQueue is empty.\n");
				break;
			}
			x = dequeue();
			printf("\n %d is removed from the queue.\n",x);
			break;
		case 3 :
			display();
			break;
		case 4 :
			initialize();
			break;
		case 5 :
			printf("\nExiting...");
			break;
		default :
			printf("\nWrong choice.");
			break;
		}
	} while(choice != 5);
	return 0;
}
