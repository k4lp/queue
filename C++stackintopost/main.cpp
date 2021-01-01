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
	int isoperand(char x) {
		if(x == '+' || x == '-' || x == '*' || x == '/')
			return 1;
		else return 0;
	}
public :
	post() {
		delete[] data;
		data = new int[SIZE];
		top = -1;
	}
	~post() {
		delete[] data;
		cout<<"Stack memory is deleted"<<endl;
	}
	void posteval(const char *exp, int &answer) {
		int result = 0, i=0,x1 =0,x2 =0;
		for(;exp[i]!='\0';i++) {
			if(!isoperand(exp[i]))
				push(exp[i] - '0');
			else {
				x1 = pop();
				x2 = pop();
				cout<<endl<<"x1 , x2 = "<<x1<< "--"<<x2<<endl;
				switch(exp[i]) {
				case '+' :
					result = x2 + x1;
					break;
				case '-' :
					result = x2-x1;
					break;
				case '*' :
					result = x2 * x1;
					break;
				case '/' :
					result = x2 / x1;
					break;
				}
				push(result);
			}
		}
		answer = pop();
	}
};

int main() {
	post post1;
	char * exp = "35*62/+4-";
	int result = 9;
	post1.posteval(exp,result);
	cout<<result<<endl;
	return 0;
}
