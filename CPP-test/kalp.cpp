#include<iostream>
#include<string>

using namespace std;

template<typename T>


double mypow(int base,int exponent) {
	int result = 1;
	while(exponent >= 1) {
		result = result * base;
		exponent --;
	}
	return result;
}

void add(int x , int y, int z) {
	cout<<x+y+z<<endl;
}

void add(int x, int y) {
	cout<<x+y<<endl;
}

int main() {
	int x , y;
	cout<<"Enter X and Y :- "<<endl;
	cin>>x>>y;
	cout<<"X = " << x << " Y = "<<y<<endl;
	add(4,5);
	add(4,5,6);
	return 0;
}

