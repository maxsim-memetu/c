#include <iostream>
#include <string>
using namespace std;


class X{
private:
	int x;
	string y;
public:
	X(int k=0, string s=""):x{k},y{s} {cout<<"xis:"<<x<<"||y is:"<<y<<"\n";};
	int mf(int new_int_value)
	{
		int old_int_value = x;
		x = new_int_value;
		return old_int_value;
	};
	int get_current_int_value()
	{
		return x;
	};
};
int main()
{
	std::cout<<"hw"<<"\n";
	string hw="rtyuiknh";
	cout<<hw<<"\n";
	X xx {10,"1bajc;"};
	int old_int_value = xx.mf(11);
	cout<<"old value of object is:"<<old_int_value<<"\n";
	X* pX = &xx;
	int ya_old_value = pX->mf(12);
	cout<<"yet another int value is:"<<ya_old_value<<"\n";
	return 0;
}