#include <iostream>
#include <string>
using namespace std;


class Date{
public:
	Date():yy{1990},mm{11},dd{23}{};
	Date(int year, int month, int day):yy{year},mm{month},dd{day}{};
	void outside_func();
	void print_date()
	{
		cout<<"the year is:"<<yy<<"\n";
		cout<<"the month is:"<<mm<<"\n";
		cout<<"the day is:"<<dd<<"\n";
	}
private:
	int yy;
	int mm;
	int dd;
};

class InClassInit
{
public:
	InClassInit();
	InClassInit(int k);
	void output_values();
	InClassInit& inc_x(int incremental_x);
	InClassInit& inc_y(int incremental_y);

private:
	int x {1010101};
	int y {12};
};
void InClassInit::output_values()
{
	cout<<"x is :"<<x<<"\n";
	cout<<"y is :"<<y<<"\n";
}

InClassInit::InClassInit(int k)
{
	y=k;
}
// constructors can be defined outside of class declaration.
InClassInit::InClassInit(){}

void Date::outside_func()
{
	cout<<"here is outside defined functino:"<<yy<<"\n";
}

InClassInit& InClassInit::inc_x(int incremental_x)
{
	x+=incremental_x;
	return *this;
}
InClassInit& InClassInit::inc_y(int incremental_y)
{
	y+=incremental_y;
	return *this;
}


int main()
{
	Date d;
	d.print_date();
	Date d1{1,2,3};
	d1.print_date();
	d1.outside_func();

	InClassInit ici;
	ici.output_values();

	InClassInit ici1 {10};
	ici.output_values();

	ici.inc_x(90).inc_y(80);
	ici.output_values();
}
