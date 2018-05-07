#include <iostream>
#include <string>
#include <chrono>
#include <vector>
using namespace std;

//using operator overloading
// template<class T, class R>class A
// {
// private:
// 	T t;
// 	R r;
// public:
// 	A(T init_t, R init_r):t{init_t},r{init_r}{};
// 	R& operator+(R r1){return t1 + r1;};
// };

struct Employee {
	string first_name, family_name;
	char middle_initial;
	// time_point hiring_date;
	short department;
public:
	void print() const;
	string full_name() const{return first_name + ' ' + family_name;};
};

struct Manager:public Employee {
	vector<Employee*> group;
	short level;
public:
	void print() const;
};
void Manager::print() const
{
	cout<<full_name()<<"\n";//because Manager has no member full_name, so will invoke the base class member.
}

int main()
{
	int k=1;
	double j = 2.9;
	cout<<"int plus double is:"<<k+j<<"\n";

	Employee emp_0;
	emp_0.first_name = "joe";
	emp_0.family_name = "jojo";
	Manager man_0;
	man_0.first_name = "summon";
	man_0.family_name = "soso";

	man_0.group.push_back(&emp_0);
	man_0.group.push_back(&man_0);

	man_0.print();
}