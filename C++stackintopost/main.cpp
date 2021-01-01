#include<iostream>
#include<ctype.h>
using namespace std;

#define SIZE 100

class post {
private :
	int *data;
	int top;
	int isempty() {
		return (top == -1);
	}
	int isfull() {
		return (top == SIZE -1);
	}
	void push(int x) {
		if(isfull()){
			cout<<"Stack is full."<<endl;
			return;
		}
		else {
			data[++top] = x;
			return;
		}
	}
	int pop() {
		if(isempty()) {
			cout<<"Stack is empty."<<endl;
			return '$';
		}
		else {
			return data[top--];
		}
	}
	int peek() {
		if(isempty()) {
			cout<<"Stack is empty."<<endl;
			return '$';
		}
		else {
			return data[top];
		}
	}
	int out(char e) {
		if(e == '+' || e == '-')
			return 1;
		else if( e == '*' || e == '/')
			return 3;
		else if( e == '(')
			return 7;
		else if( e == ')')
			return 0;
		else return 9;
	}
	int in(char e) {
		if(e == '-' || e == '+')
			return 2;
		else if( e == '*' || e == '*')
			return 4;
		else if( e == '(')
			return 7;
		else return 9;
	}
public :
	post() {
		if(data == NULL) {
			data = new int[SIZE];
			top = -1;
		}
		else {
			delete[] data;
			data = new int[SIZE];
			top = -1;
		}
	}
	~post() {
		delete[] data;
		cout<<"Stack memory is deleted"<<endl;
	}
	void intopost(char *exp, char post) {
		int j = 0,i=0;
		for(int x : exp) {
			if(isalpha(exp[i])) {
				post[j++];
			}
			else if(isempty())
				push(exp[i]);
			else if(out(exp[i]) > in(peek()))
				push(exp[i]);
			else {
				while(!isempty() || out(exp[i]) != in(peek())) {
					post[j++] = pop();
				}
				if(exp[i] != ')')
					push(exp[i]);
				else
					pop();
			}
		}
		do {
			post[j++] = pop();
		} while(!isempty());
	}
};

int main() {
	post post1;
	char * exp = "a+b-c*d/e";
	char post[30];
	post1.intopost(exp,post);
	cout<<post<<endl;
	return 0;
}
