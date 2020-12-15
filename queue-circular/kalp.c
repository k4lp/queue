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
}
