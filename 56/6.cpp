#include <iostream>
#include <string>
using namespace std;
// nested class definition
// how to access this inner class objects?
class A
{
public:
	void output_value();
	A(int aa,int bb):a{aa},b{bb}{};
private:
	int a;
	class B
	{
		int b;
	};
};
A::output_value()
{
	cout<<"a is:"<<a<<"|"<<"b is:"<<b;
}

int main()
{
	A a {3,4};
	a.output_value();

}