#include<iostream>
using namespace std;

class myroom {
private :
	int height;
	int width;
	int doors;
public :
	void getdata(int hei,int wid){
		height = hei;
		width = wid;
	}
	int area(){
		return height*width;
	}
};

int main() {
	char *s;
	s = new char[20];
	cin.get(s,20);
	cout<<"Hello"<<endl<<s<<endl;


	myroom r1;
	r1.getdata(12,12);
	cout<<r1.area()<<endl;
	return 0;
}
