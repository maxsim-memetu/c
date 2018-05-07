#include <iostream>
#include <string>
#include <chrono>
#include <vector>
using namespace std;

int main()
{
	string s0;
	string s1 {"so_to_speak?"};
	string s2 {s1};
	string s3 {9, 'a'};

	cout<<s0<<endl;
	cout<<s1<<endl;
	cout<<s2<<endl;
	cout<<s3<<endl;
	cout<<s0.max_size()<<endl;
	cout<<s0.capacity()<<endl;
	s0.reserve(s0.capacity() + 1);
	cout<<s0.capacity()<<endl;//added 9, why?
	vector<char> z = {'a', 'b', 'c', 'd'};
	for (auto p:z)
	{
		s0.push_back(p);
	}
	cout<<s0<<endl;
	string contains_int {"a12acd3"};
	int k;
	try {
		k = stoi(contains_int);
	} catch(exception& e) {
		cout<<"error"<<e.what()<<endl;
	}
	cout<<k<<endl;
	// for(auto p = s0.begin();p<s0.end();p++)
	// {
	// 	cout<<p<<endl;
	// }
	cout<<s0.find("c")<<endl;
	cout<<s0.substr(0,2)<<endl;
	cout<<s0[1]<<endl;
	cout<<islower(s0[1])<<endl;

	string s6 {9,'x'};
	cout<<"before empty:"<<s6<<"|after empty:"<<s6.empty()<<endl;

	string s7 = s1.substr(3,100);
	cout<<"s7 is initialized from s1 substr, its contents are:"<<s7<<endl;
}