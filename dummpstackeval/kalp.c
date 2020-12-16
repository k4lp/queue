#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define SIZE 100

typedef struct _node {
	int data[SIZE];
	int top;
} node;

node *pu;

void initialize() {
	if(pu != NULL)
		free(pu);
	pu = (node *)malloc(sizeof(node));
	pu->top = -1;
}
