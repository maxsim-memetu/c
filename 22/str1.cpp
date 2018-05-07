#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void write(string &str) {
	reverse(str.begin(), str.end());
	cout<<str<<endl;
}
int main() {
	vector<string> orig {"a1", "a2", "a3"};
	vector<string> vs;
	vector<string>::iterator itr;
	for(itr=orig.begin();itr<orig.end();itr++){
		vs.push_back(*itr);
	}
	vector<string>::iterator new_itr;
	for(new_itr=vs.begin();new_itr<vs.end();new_itr++) {
		cout<<*new_itr<<endl;
	}

	list<string> string_list;
	string_list.push_back("so");
	string_list.push_back("to");
	string_list.push_front("that's");
	string_list.push_back("speak!");

	for(auto p=string_list.begin(); p!=string_list.end();p++) {
		write(*p);
	}
}