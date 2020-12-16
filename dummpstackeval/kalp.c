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

int isempty(){
	return pu->top == -1;
}

int isfull() {
	return pu->top == SIZE -1;
}

void push(int x) {
	if(isfull())
		return;
	else {
		pu->data[++pu->top] = x;
	}
}

int pop() {
	if(isempty())
		return -1;
	else {
		return pu->data[pu->top--];
	}
}

int peek() {
	if(isfull())
		return -1;
	else {
		return pu->data[pu->top];
	}
}

int isoperand(char x) {
	if( x == '+' || x == '-' || x == '*' || x == '/')
		return 0;
	else return 1;
}

int eval(const char *exp) {
	int i = 0,x2,x1,result;
	initialize();
	for(;exp[i]!='\0';i++){
		if(isoperand(exp[i])) {
			push(exp[i] - '0');
		}
		else {
			x2 = pop(); x1 = pop();
			switch(exp[i]) {
			case '+' : result = x1+x2;break;
			case '-' : result = x1 - x2; break;
			case '*' : result = x1 * x2; break;
			case '/' : result = x1/x2; break;
			}
			push(result);
		}
	}
	return pop();
}

int main() {
	char *exp = "234/-233*/+3-";
	printf("\n %s = %d",exp,eval(exp));
	return 0;
}
