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


int find_ocur(int num, string src, string pattern) {
	string::iterator head, tail, pattern_itr;
	int cur_occurance = 0;
	int pattern_length = pattern.length();
	cout<<"entering for"<<endl;
	for(head = tail = src.begin(); tail != src.end() && head != src.end();) {
		cout<<"head:"<<*head<<" tail:"<<*tail<<endl;
		if(*head != pattern[0]) {
			cout<<"head proceed:"<<*head<<endl;
			head++;
		} else {//found pattern's beginning in pattern
			cout<<"head match:"<<*head<<endl;
			for(tail=head, pattern_itr = pattern.begin();;tail++, pattern_itr++) {
				cout<<"\ttail proceed:"<<*tail<<endl;
				if(tail-head==pattern_length) {//found one occurance
					cout<<"\tfound match:"<<*tail<<endl;
					if(++cur_occurance == num) {
						return head-src.begin();//found occur we want, return
					} else {
						head++;
						break;//still not reach, continue
					}
				} else if(*tail != *pattern_itr) {//mismatch occur, break
					head++;
					break;
				} else {
					cout<<"\tfound tail match:"<<*tail<<endl;
					continue;//tail still match pattern, proceed
				}
			}
		}
	}
	return -1;
}
int main() {
	string source="abcdefg";
	string pat="cde";
	int offset = find_ocur(2, source, pat);
	cout<<offset<<endl;	
}