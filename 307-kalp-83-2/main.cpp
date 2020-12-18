#include<iostream>
#include<iomanip>;

using namespace std;

//83-kalp-307

class Surgical{
	private:
		char disposable[10];
	public:
		void setData(){
			cout<<"Disposable or not(yes/no)\n";
			cin>>disposable;
		}
		void getData(){
			cout<<setw(15)<<"Disposable:"<<setiosflags(ios::left)<<disposable<<endl;
		}
};

//83-kalp-307
class N95{
	private:
		char layers[20];
	public:
		void setData(){
			cout<<"How many layers(sigle/two/multilayer)\n";
			cin>>layers;
		}
		void getData(){
			cout<<setw(15)<<"Layers:"<<setiosflags(ios::left)<<layers<<endl;
		}
};

class Fashion{
	private:
		char material[20];
		char valve[5];
	public:
		void setData(){
			cout<<"Material Used in mask\n";
			cin>>material;
			cout<<"Valve (yes/no)\n";
			cin>>valve;
		}
		void getData(){
			cout<<setw(15)<<"Material:"<<setiosflags(ios::left)<<material<<endl;
			cout<<setw(15)<<"valve:"<<setiosflags(ios::left)<<valve<<endl;
		}
};

//83-kalp-307
class MyMask:public Surgical,public N95,public Fashion{
	private:
		char color[10];
	public:
		void setData(){
			cout<<"Answer the following::: \n";
			Surgical::setData();
			N95::setData();
			Fashion::setData();
			cout<<"Enter color of the mask\n";
			cin>>color;
		}
		void getData(){
			cout<<"\n\nData of mask:::\n";
			Surgical::getData();
			N95::getData();
			Fashion::getData();
			cout<<setw(15)<<"Color:"<<setiosflags(ios::left)<<color;
		}
};

int main(){
	MyMask mymask;
	mymask.setData();
	mymask.getData();
	return 0;
}
