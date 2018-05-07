#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

int main() {

	vector<int> vi;
	for(int i=0;i<20;i++) {
		vi.push_back(i*i);
	}

	cout<<"max is:"<<*max_element(vi.begin(), vi.end())<<endl;
	cout<<"min is:"<<*min_element(vi.begin(), vi.end())<<endl;

	list<float> lf;
	for(int i=0; i<20; i++) {
		float k = static_cast<float>(i);
		lf.push_back((float)i);
	}
	cout<<"max in float list:"<<*max_element(lf.begin(), lf.end())<<endl;
	cout<<"min in float list:"<<*min_element(lf.begin(), lf.end())<<endl;

	unordered_map<int, string> um;
	for(int i=0;i<20;i++) {
		um[i]="this string";
	}
	for(auto p:um) {
		cout<<p.first<<":"<<p.second<<endl;
	}
	cout<<"max in unordered map:"<<(*max_element(um.begin(), um.end())).first<<endl;//max_element compares KEY field.
	cout<<"min in unordered map:"<<(*min_element(um.begin(), um.end())).first<<endl;//min_element compares KEY field.
}