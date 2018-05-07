#include <iostream>
#include <exception>
#include <string>

using namespace std;
class A
{
public:
	A(int int_a):a{int_a}{};
	void all_print();
	const static int ss = 3131;// if initialized inside a class, it must be const, otherwise, initialize it outside of this class.
private:
	int a;

};
void A::all_print()
{
	cout<<"a is:"<<a<<"| static member is:"<<ss<<"\n";
}
	// int A::ss = 33;
int main()
{
	A a1 {3};
	A a2 {9};
	// int A::ss = 33; cannot initilize a static member here because we cannot redefine a static member inside another function,
	// namely, main function here.
	a1.all_print();
	a2.all_print();
}