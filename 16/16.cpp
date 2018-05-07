#include <iostream>
#include <string>
#include <chrono>
#include <vector>
using namespace std;

class Base
{
public:
	int a;
	virtual void p(){
		cout<<"base's a:"<<a<<"\n";
	};
};

class Derived:public Base
{
public:
	int b;
	virtual void p(){
		cout<<"derived's b:"<<b<<"\n";
	}
};


int main()
{
	Base b1;
	b1.p();

	Derived d1;
	d1.p();

	Base* pb1 = new Base();
	pb1->p();

	Base* pb2 = new Derived();
	pb2->p(); //find an appropriate method from derived up to the base, initialized with a Derived slot, so a derived virtual table 
	//contains a p() method, this method is encountered first, and is applied therefore.

	Derived* pd1 = new Base();//cannot use a base contructor to init an derived object. Compiler thinks there may be some information 
	//that base constructor cannot provide.
	pd1->p();

	Derived* pd2 = new Derived();
	pd2->p();
}