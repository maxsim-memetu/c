#include <iostream>
#include <string>

using namespace std;
//various contructor and destructor
//default constructor, copy constructor
// every initialization must have a corresponding constructor,
// CN VNAME {}
// CN VNAME = {}
// CN VNAME = CN()
// CN VNAME
// if you want default constructor togather with parameterized constructor
// then you can define them all in one class definition.	
// default value can be partially used: like you have a constructor with 3 members need to be initialized,
// and caller only feed 2 values to constructor, and this is ok if the left-over variable has a default value.
class A
{
public:
	A(string str1, string str2, int ii):s1{str1},s2{str2},i1{ii}{};
	A(){};
	void output_val();
private:
	string s1 = "default_s1";
	string s2 = "default_s2";
	int i1 = 101;
};
void A::output_val()
{
	cout<<"s1 = "<<s1<<"| s2 = "<<s2<<"| i1 = "<<i1<<"\n";
}
class B:public A
{
private:
	A member_a {"inner", "A", 902};
	string xtr;
public:
	B(){xtr = "default_xtr";};
	B(string s):xtr{s}{};
	void output_value();
};
void B::output_value()
{
	member_a.output_val();
	cout<<" extra b's string is:"<<xtr<<"\n";
}

int main()
{
	A a0 {"hello ", "world ", 1234};
	a0.output_val();

	A a1;
	a1.output_val();

	A a2 {};
	a2.output_val();

	A a3 = {};
	a3.output_val();

	A a4 = a0;
	a4.output_val();

	A a5 {a0};
	a5.output_val();

	B b1;
	b1.output_value();

}