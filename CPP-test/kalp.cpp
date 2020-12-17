#include<iostream>
using namespace std;

int main() {
	char *s;
	s = new char[20];
	cin.get(s,20);
	cout<<"Hello"<<endl<<s<<endl;
	return 0;
}
