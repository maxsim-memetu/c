#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

int main()
{
	stringstream ss;
	ss<<"there are "<<9<<"items in my cart";
	cout<<"the stream is :"<<ss.str()<<endl;

	ss.str("");
	ss<<showbase<<hex<<16;
	cout<<"another stream:"<<ss.str()<<endl;

	ss.str("");
	ss<<3.15;
	cout<<"3rd stream:"<<ss<<endl;
}