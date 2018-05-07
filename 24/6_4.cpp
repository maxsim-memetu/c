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
// #include "utils.h"
using namespace std;
using namespace boost;

// partition a string vector

int main() {
	vector<string> vs {"a","b","c","d","e","f","g","d"};

	vector<string>::iterator itr = partition(vs.begin(), vs.end(), bind2nd(less<string>(), "d"));
	for(vector<string>::iterator p=vs.begin(); p!=vs.end();p++) {
		cout<<*p<<endl;
	}
	cout<<"return value from partition is:"<<*itr<<endl;
}