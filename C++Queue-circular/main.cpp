#include<iostream>
using namespace std;

class Queue {
private :
	int size,front,rear,*q;
	int isempty() {
		return (front == rear);
	}
	int isfull() {
		return front == (rear+1) %size;
	}
	void enqueue() {
		if(isfull()) {
			cout<<"Queue is full."<<endl;
			return;
		}
		else {
			cout<<"Enter the element :- "<<endl;
			int x =0;
			cin>>x;
			q[rear = ((rear + 1) % size )] = x;
		}
	}
	int dequeue() {
		if(isempty()) {
			cout<<"Queue is empty."<<endl;
			return -1;
		}
		else {
			return q[front = ((front + 1)%size)];
		}
	}
public :
	Queue() {
		cout<<"Enter the size of the queue :- "<<endl;
		cin>>size;
		q = new int[size];
		front = 0;
		rear = 0;
	}
	~Queue() {
		delete[] q;
		cout<<"Queue has been deleted."<<endl;
	}
	void run() {
		int choice = 9;
		while(choice != 8){
			cout<<"1. Enqueue"<<endl;
			cout<<"2. Dequeue"<<endl;
			cout<<"3. Is full?"<<endl;
			cout<<"4. Is empty?"<<endl;
			cout<<"8. Exit"<<endl;
		}
	}
};


int main(){
	Queue queue;
	return 0;
}
