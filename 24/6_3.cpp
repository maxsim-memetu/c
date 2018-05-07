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
	vector<string> v1 {"a", "c", "e"};
	vector<string> v2 {"b", "d", "f"};

	vector<string> v3;
	v3.reserve(v1.size() + v2.size() + 1);

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter<vector<string>>(v3));
	for(vector<string>::iterator itr = v3.begin(); itr != v3.end(); itr++ ) {
		cout<<*itr<<endl;
	}
	cout<<"2nd:"<<endl;

	random_shuffle(v3.begin(), v3.end());

	sort(v3.begin(), v3.begin() + v3.size()/2);
	sort(v3.begin()+v3.size()/2, v3.end());

	inplace_merge(v3.begin(), v3.begin() + 3, v3.end());
	for(vector<string>::iterator itr = v3.begin(); itr != v3.end(); itr++ ) {
		cout<<*itr<<endl;
	}

	list<string> lstStr1, lstStr2;
	lstStr1.push_back("Frank");
	lstStr1.push_back("Rizzo");
	lstStr1.push_back("Bill");
	lstStr1.push_back("Cheetoh");

	lstStr2.push_back("Allie");
	lstStr2.push_back("McBeal");
	lstStr2.push_back("Slick");
	lstStr2.push_back("Willie");

	lstStr1.sort();//list.sort is different from std::sort which is applied to random access sequence.
	lstStr2.sort();
	lstStr1.merge(lstStr2);//like merge sort, so if the sequences are not both already sorted, then the merged sequence will not be globally sorted.
	for(list<string>::iterator itr = lstStr1.begin(); itr!=lstStr1.end(); itr++) {
		cout<<*itr<<endl;
	}

}