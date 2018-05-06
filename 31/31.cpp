#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <iterator>
#include <list>
using namespace std;

int main() {
	list<string> lstr {"1", "a", "j", "h", "b", "d", "e", "e", "k", "j"};
	list<string> rstr {"1", "a", "b", "j", "n", "m", "c"};
	set<string> s1;
	set<string> s2;
	for(list<string>::iterator i=lstr.begin(); i!=lstr.end(); i++) {
		s1.insert(*i);
	}
	for(list<string>::iterator i=rstr.begin(); i!=rstr.end(); i++) {
		s2.insert(*i);
	}
	s1.insert("a");
	s1.insert("b");
	cout<<"set 1 is:"<<endl;
	for(set<string>::iterator itr=s1.begin(); itr!=s1.end(); itr++) {
		cout<<*itr<<" ";
	}
	cout<<endl<<"set 2 is:"<<endl;
	for(set<string>::iterator itr=s2.begin(); itr!=s2.end(); itr++) {
		cout<<*itr<<" ";
	}
	cout<<endl;
	set<string> unionSet;
	set<string> diffSet;
	set<string> interSet;

	set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(unionSet, unionSet.begin()));
	set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(diffSet, diffSet.begin()));
	set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(interSet, interSet.begin()));

	cout<<"UNION:"<<endl;
	for(set<string>::iterator i=unionSet.begin(); i!=unionSet.end(); i++) {
		cout<<*i<<" ";
	}
	cout<<endl;
	cout<<"INTERSECTION:"<<endl;
	for(set<string>::iterator i=interSet.begin(); i!=interSet.end(); i++) {
		cout<<*i<<" ";
	}
	cout<<endl;
	cout<<"DIFFERENCE:"<<endl;
	for(set<string>::iterator i=diffSet.begin(); i!=diffSet.end(); i++) {
		cout<<*i<<" ";
	}
	cout<<endl;
}