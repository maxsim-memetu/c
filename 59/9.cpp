#include <iostream>
#include <string>
#include <exception>

using namespace std;

// define handler/pointer in class, and intialize this handler/pointer
// in constructor. so, generally, we define a pointer to resource in class,
// this resource can be file, memory, array/vector/map data structures like that.
class my_exception:public exception
{
	virtual const char* what() const throw()
	{
		return "my exception occurs";
	}
} myex;

class A
{
public:
	int get_elements(int offset);
	void print_all_elem();
	int put_element(int offset, int value);
	A(int size);
	~A();
private:
	int sz;
	int *elem;
};
A::A(int size)
{
	if(size < 0)
	{
		throw myex;
	}
	sz = size;
	elem = new int[sz];
}
A::~A()
{
	sz=0;
	delete elem;
	cout<<"done deleting!!!\n";
}
int A::get_elements(int offset)
{
	if(offset < 0 || offset >= sz)
	{
		throw myex;
		return 0;
	}
	return *(elem+offset);
}
int A::put_element(int offset, int value)
{
	if(offset < 0 || offset >= sz)
	{
		throw myex;
		return -1;
	}
	*(elem+offset) = value;
	return 0;
}
void A::print_all_elem()
{
	for(int i=0;i<sz;i++)
	{
		cout<<"the "<<i<<"th element is"<<this->get_elements(i)<<"\n";
	}
}

int main()
{
	A a0 {10};
	a0.print_all_elem();
	for(int k=0; k<10; k++)
	{
		int tmp = a0.put_element(k, k*10+4);
		if(tmp != 0)
			cout<<"fail to put one element!\n";
	}
	a0.print_all_elem();
	cout<<"now we are close to the end of main~~~~\n";//~A() will be called after the last line of code and before the closing bracklet?

}