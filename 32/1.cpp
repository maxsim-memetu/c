#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	cout<<right<<setfill('.')
	<<setw(10)<<"a"
	<<setw(10)<<"b"
	<<setw(10)<<"c"
	<<endl;

	double pi=1234567.1234567891234563;
	cout<<"pi:"<<setprecision(15)
	<<pi<<endl;

	cout<<"fixed:"<<setprecision(15)<<pi<<endl;

	cout<<scientific<<pi<<endl;
}