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
// using namespace utils;

int main() {
	// list<string> lstr {"a","b","c"};
	vector<string> v {"a","b","c","d","e","f"};
	random_shuffle(v.begin(), v.end());//not run time shuffle? run multiple times, we get the same shuffle result.
	for(vector<string>::iterator itr=v.begin();itr!=v.end();itr++) {
		cout<<*itr<<endl;
	}

	vector<string> v1,v2;
	v1.push_back("Charles");
	v1.push_back("in");
	v1.push_back("Charge");

	v2.push_back("Charles");
	v2.push_back("in");
	v2.push_back("Charge");

	if(std::equal(v1.begin(), v1.end(), v2.begin())) {
		cout<<"v1 and v2 equal"<<endl;
	} else {
		cout<<"v1 and v2 differs"<<endl;
	}

	string s1="abcdef";
	string s2="abcde";
	string s3="abcd";

	cout<<boolalpha
		<<lexicographical_compare(s1.begin(), s1.end(), s1.begin(), s1.end())<<endl;
	cout<<lexicographical_compare(s2.begin(), s2.end(), s1.begin(), s1.end())<<endl;
}