#include<iostream>
#include<string>

using namespace std;

double mypow(int base,int exponent) {
	int result = 1;
	while(exponent >= 1) {
		result = result * base;
		exponent --;
	}
	return result;
}

int main() {
	string firstname , lastname ;
	cout<<"Enter the first name :- "<<endl;
	getline(cin,firstname);
	cout<<"Enter the last name :-"<<endl;
	getline(cin,lastname);
	string name = firstname + " " + lastname + ".";
	cout<<"So your name is "<<name<<endl;

	cout<<"Your name length is :- " << name.length()<<endl;
	return 0;
}

