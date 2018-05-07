#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <list>
#include <algorithm>
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace boost;
//REMOVE SUBSTRING INPLACE FROM ORIGINAL STRING
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
						cout<<"returning success:"<<*head<<endl;
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
int remove_sub(string& src, string pat) {
	int offset = find_ocur(1, src, pat);
	if(offset == -1) { //cannot find such pattern in src string.
		return 0;
	} else {
		string::iterator itr = src.begin() + offset + pat.length();
		cout<<"removing from:"<<*itr<<endl;
		for(;itr!=src.end();itr++) {
			cout<<"moving:"<<*itr<<" to"<<src[offset]<<endl;
			src[offset++] = *itr;
		}
		for(int i=0;i<pat.length();i++)
			src.pop_back();
		return 1;
	}
}

int main() {
	string src = "abcdefghi";
	string pat = "cd";
	int r = remove_sub(src, pat);
	cout<<src<<endl;
}