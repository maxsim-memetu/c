#include <iostream>
#include <string>
using namespace std;


class X{
private:
	int x;
	string y;
public:
	int kk;
	X(int k=0, string s="", int kkk=1):x{k},y{s},kk{kkk} {cout<<"xis:"<<x<<"||y is:"<<y<<"|| kk is:"<<kk<<"\n";};
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

	X x2 {100, "bacde", 400};
	cout<<"now we try to access public member:"<<x2.kk<<"\n";
	//cout<<x2.x;
	X x3 = x2;
	cout<<"x2's addr is:"<<&x2<<"\n";
	cout<<"x3's addr is:"<<&x3<<"\n";
	cout<<"x3's kk is:"<<x3.kk<<"\n";
	x3.kk = 22;
	cout<<"x2's kk after modifying x3:"<<x2.kk<<"\n";
	return 0;
}
