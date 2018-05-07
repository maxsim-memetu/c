#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <list>
#include <algorithm>
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace boost;


vector<string> ysplit(string ss, char sperator) {
	vector<string> temp;
	string::iterator sp = ss.begin();
	string::iterator bp = ss.begin();
	for(;bp<ss.end();bp++){
		if(*bp == sperator) {
			temp.push_back(ss.substr(sp-ss.begin(), bp-sp));
			sp = bp+1;
		}
	}
	temp.push_back(ss.substr(sp-ss.begin(), bp-sp));
	cout<<&temp<<endl;
	return temp;
}
int main() {
	string s = "abc|123|xyz";
	vector<string> vs = ysplit(s, '|');
	for(vector<string>::iterator p = vs.begin(); p<vs.end(); p++) {
		cout<<*p<<endl;
	}
	cout<<&vs<<endl;

	list<string> ls;
	split(ls, s, is_any_of("|"));
	list<string>::iterator list_itr;
	for(list_itr=ls.begin(); list_itr != ls.end(); list_itr++) {
		cout<<*list_itr<<endl;
	}

}