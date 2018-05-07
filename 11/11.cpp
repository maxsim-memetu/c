#include <iostream>
#include <exception>
#include <string>
using namespace std;
//class without a constructor.so a default constructor will be assigned. and we can use a initializer to initialize
// an object of this class.
class A
{
public:
	int a;
	int b;//initialized by default constructor.
	void print_value()
	{
		cout<<a<<"\n"<<b<<"\n";
	}
};

class B
{
private:
	int a;
	int b;
public:
	B(int ia=1):a{ia}{};//constructor has parameter, and this parameter has a default value, so this is default construnctor.
	void print_value();
};
void B::print_value()
{
	cout<<"in B.a is:"<<a<<"|"<<"B.b is:"<<b<<"\n";
}
int main()
{
	A a {100};//initialize with an initializer.
	a.print_value();
	B b {2};// even though member B.a has a default value 1, this {} initializer still init B.a as 2, and B.b as a random int value.
	b.print_value();
}