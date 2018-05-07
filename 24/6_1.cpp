#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <list>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <istream>
#include <ostream>
#include <unordered_map>
#include <fstream>
using namespace std;
using namespace boost;

int main()
{
	vector<string> vec(100);
	cout<<vec.size()<<endl;
	for(int i=0;i<101;i++){
		vec.push_back("l");//push size+1 elements into vec.
	}
	cout<<vec.size()<<endl;//now size become 2*100+1
	vec.reserve(200);
	cout<<vec.size()<<endl;

	unordered_map<string, int> um;
	um["a"]=1;
	um["b"]=2;
	um["c"]=3;
	for(unordered_map<string, int>::iterator p=um.begin();p!=um.end();p++) {
		cout<<p->first<<":"<<p->second<<endl;
	}
}