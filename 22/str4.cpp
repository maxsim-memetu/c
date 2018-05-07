#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace boost;

int main() {
	string ss = "qwertyuioplmnbvfde4567890-p;.\"{}<>??////\\";//unexpected output
	cout<<ss<<endl;

	cout<<"find:"<<ss.find("0")<<endl;
	cout<<"rfind:"<<ss.rfind("/")<<endl;
	cout<<"find_first_of:"<<ss.find_first_of("s")<<endl;

	set<char> sc;
	pair<set<char>::iterator,bool> p,p1;
	p = sc.insert('y');
	cout<<":"<<p.second<<endl;
	p1 = sc.insert('y');
	cout<<sc.size()<<":"<<p1.second<<endl;
}