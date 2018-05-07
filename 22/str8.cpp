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

bool is_end_of_word(char character) {
	return character==' ' || character == '?' || character == '.' || character == '!' || character == ',';
}
int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	unordered_map<string, int> word_cnt;
	char c;
	string cur_word;
	while(in.get(c)) {
		if(is_end_of_word(c)) {
			if(word_cnt.count(cur_word) > 0) {
				word_cnt[cur_word]++;
			} else {
				word_cnt.insert({cur_word, 1});
			}
			cur_word.erase(0);
		} else {
			cur_word.push_back(c);
		}
	}
	for(auto k:word_cnt) {
		cout<<k.first<<":"<<k.second<<endl;
	}
}
