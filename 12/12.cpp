#include <iostream>
#include <exception>
#include <string>
using namespace std;


//delegate constructor

class A
{
private:
	int k;
public:
	A(int s):k{s}{};
	A():A(13){};
	void printK();

};
void A::printK()
	{
		cout<<"k is: "<<k<<"\n";
	}

int main()
{
	A a;
	a.printK();

	A aa {10};
	aa.printK();
}