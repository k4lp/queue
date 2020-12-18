#include<iostream>
#include <bits/stdc++.h>
using namespace std;

//83-kalp-307

class MM {
private :
	int *a,size;
public :
	MM(int length) {
		size = length;
		a = new int[size];
	}
	~MM() {
		cout<<"Destructor invoked."<<endl;
		delete[] a;
	}
	//83-kalp-307
	float getmean() {
		float mean = 0;
		int i = 0;
		for( ; i < size ; i ++) {
			mean = mean + a[i];
		}
		mean = mean /(float) size;
		return mean;
	}
	void sortarr() {
		sort(a,a+(size));
	}
	float getmedian() {
		float median = 0;
		if(size%2 == 0) {
			median = (float)(a[size/2] + a[(size/2) + 1])/2;
		}
		else {
			median = a[size/2];
		}
		return median;
	}

	//83-kalp-307
	void getinput() {
		cout<<"Enter "<<size<<" elements :- "<<endl;
		int i = 0;
		for( ; i < size;i ++) {
			cin>> a[i];
		}
	}
};


//83-kalp-307
int main() {
	cout<<"Enter the number of elements you want to have in an array :- "<<endl;
	int number = 0;
	cin>>number;
	MM m(number);
	m.getinput();

	//83-kalp-307
	cout<<"Mean :- "<<m.getmean()<<endl;
	m.sortarr();
	cout<<"Median :- "<<m.getmedian()<<endl;
	return 0;
}
