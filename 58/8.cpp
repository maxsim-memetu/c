#include <iostream>
#include <string>
#include <exception>
using namespace std;
// define handler/pointer in class, and intialize this handler/pointer
// in constructor. so, generally, we define a pointer to resource in class,
// this resource can be file, memory, array/vector/map data structures like that.

class myexception: public exception
{
  virtual const char* what() const throw()
  {
    return "My exception happened";
  }
} myex;

class A
{
	int sz;
	int* elem;
public:
	A(int s);
	void set_elem(int offset, int val);
	void print_val();
};
A::A(int s)
{
	if(s<0)
	{
		throw myex;
	}
	else 
	{
		elem = new int[s];// element created by new is not initialized to 0!
		sz=s;
	}
}

void A::set_elem(int offset, int val)
{
	if(offset < sz && offset >= 0)
	{
		*(elem+offset) = val;
	}
}
void A::print_val()
{
	for(int i=0; i<sz; i++)
	{
		cout<<*(elem+i)<<"\n";
	}
}
int main()
{
	A oa {10};
	oa.set_elem(0,11);
	oa.set_elem(1,12);
	oa.print_val();
}