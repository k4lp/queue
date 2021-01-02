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
	void display() {
		if(isempty()) {
			cout<<"Queue is empty."<<endl;
			return;
		}
		else {
			int i = front +1;
			for(;i!=((rear+1)%size) ; i = (i+1)%size)
				cout<<q[i]<<endl;
		}
	}
public :
	Queue() {
		cout<<"Enter the size of the queue :- "<<endl;
		size = 0;
		cin>>size;
		q = new int[size + 1];
		front = 0;
		rear = 0;
	}
	~Queue() {
		delete[] q;
		cout<<"Queue has been deleted and program has been exited."<<endl;
	}
	void run() {
		int choice = 9;
		while(choice != 8){
			cout<<"1. Enqueue"<<endl;
			cout<<"2. Dequeue"<<endl;
			cout<<"3. Is full?"<<endl;
			cout<<"4. Is empty?"<<endl;
			cout<<"5. Display Queue."<<endl;
			cout<<"8. Exit"<<endl;
			cout<<"Enter your choice :- "<<endl;
			cin>>choice;
			switch(choice) {
			case 1 :
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				isfull() ? cout<<"Queue is Full."<<endl : cout<<"Queue is not full."<<endl;
				break;
			case 4:
				cout<<isempty()<<endl;
				break;
			case 5:
				display();
				break;
			case 8:
				break;
			default :
				cout<<"Enter valid choice."<<endl;
				break;

			}
		}
	}
};


int main(){
	Queue queue;
	queue.run();
	return 0;
}
