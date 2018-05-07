#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>
#include <vector>
#include <list>
#include <algorithm>
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace boost;

//3ways to iterate a cpp string:
// std::string::iterator, string.begin(), string.end()
// char pointer, not recommended char*
// use integer offset, string[0], string[1], string[2].... and string.length()

string join_str(vector<string> vs, char join_char) {
	string ret;
	vector<string>::iterator vi;
	if(vs.size() == 1) {
		return vs[0];
	}
	for(vi=vs.begin();vi<vs.end()-1;vi++) {
		ret+= *vi;
		ret+=join_char;
	}
	ret+=*vi;
	return ret;
}

int main() {
	vector<string> str {"abc", "xyz", "ojn"};
	vector<string> another_str {"jfoei"};
	string combined = join_str(str, '|');
	cout<<"combined string is:"<<combined<<endl;
	string another_combined = join_str(another_str, '/');
	cout<<"combined another string is:"<<another_combined<<endl;

	string long_str ="abcedefejiejfong;alekjfoina;dfje";
	cout<<long_str.length()<<endl;

	char* p = &long_str[0];
	list<char> lstchar;
	for(;*p!='\0';p++){//we can use char pointer to iterate a string because string is terminated with \0( why????:O).

		cout<<*p<<endl;
		lstchar.push_back(*p);
	}
	// cout<<*p<<endl;
	cout<<lstchar.size()<<endl;//vector and list both use size(), not length().
}