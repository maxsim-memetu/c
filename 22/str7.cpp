#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <list>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <istream>
#include <ostream>
#include <fstream>
using namespace std;
using namespace boost;

bool is_end_of_word(char character) {
	return character==' ' || character == '?' || character == '.' || character == '!';
}
int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	// char c;
	// while(in.get(c)) {
	// 	cout<<c<<endl;
	// 	if(c=='\t') {
	// 		out<<"   ";
	// 	} else {
	// 		out<<c;
	// 	}
	// }
	char c;
	int cur_length=0;
	string cur_word;
	while(in.get(c)) {
		if(!is_end_of_word(c)){
			cout<<"not end of word:"<<c<<endl;
			cur_word.push_back(c);
		} else {
			cout<<"find a word:"<<cur_word<<endl;
			if(cur_length + cur_word.length() + 1 >= 72) {
				out<<endl;
				cur_length=0;
				while(cur_word.length()+1>72){
					out<<cur_word.substr(0,72)<<endl;
					cur_word.erase(0,72);
				}
			}
			out<<cur_word<<c;
			cur_length+=(cur_word.length() + 1);
			cur_word.erase(0);
		}
	}
	out.close();

}

