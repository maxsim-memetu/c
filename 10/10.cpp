#include <iostream>
#include <exception>
#include <string>
using namespace std;
class base_class
{
public:
	base_class(string bc_param):base_class_string{bc_param}{cout<<"done init base with:"<<base_class_string<<"\n";};
private:
	string base_class_string;
};
class dev_class:public base_class
{
public:
	dev_class(string dev_string):dev_c_string{dev_string},base_class("ha"){cout<<"done init dev class with"<<dev_c_string<<"\n";};// we can invoke base class constructor in init list.
private:
	string dev_c_string;
};

int main()
{
	base_class bclass_obj {"base class string"};
	dev_class dev_class {"derivative class string"};
}