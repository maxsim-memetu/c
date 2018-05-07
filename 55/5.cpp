#include <iostream>
#include <string>
using namespace std;
// practice of static member

class X{
private:
	static int x;
	// string y;
public:
	// int kk;
	// X(string yy):y{yy}{};
	// void inc_x();
	static void print_values(){cout<<"x is:"<<x<<"\n";};
	static void set_x(int xx){x = xx;};
};
// void X::inc_x()
// {
// 	x+=1;
// }
// void X::print_values()
// {
// 	cout<<"x is:"<<X::x<<"\n";
// }
// void X::set_x(int xx)
// {
// 	X::x = xx;
// }
int main()
{
	// X x1{"hello"};
	// X x3{"world"};
	// X x1;
	// x1.print_values();
	X::set_x(0);
	X::print_values();
	// x1.inc_x();
	// x3.print_values();
}
