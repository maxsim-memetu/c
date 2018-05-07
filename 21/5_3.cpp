#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <boost/format.hpp>

using namespace std;
using boost::format;
using boost::io::str;
using boost::io::format_error;

int main()
{
	try {
		format f("there are %1% ways %2% %3% %4%");

		f % 3;
		f % "to" % "do" % "this.";//like a FIFO
		cout<<f<<endl;
		f.clear();
		f.parse("those cost $%d.");
		f % 40;
		cout<<f<<endl;
		int x=1125609909;
		string strx = str(format("%x") %x);
		cout<<strx<<endl;
	} catch (format_error &e) {
		cout<<"error occurred:"<<e.what()<<endl;
	}
}