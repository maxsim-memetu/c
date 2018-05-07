#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

class Record
{
	string record_name;
	string record_type;
	int reference_count;
public:
	Record(string name, string type, int cnt):record_name{name},record_type{type},reference_count{cnt}{};
	void print_value();
};
void Record::print_value()
{
	cout<<"rec name:"<<record_name<<"| rec type:"<<record_type<<"| ref cnt:"<<reference_count<<endl;
}

int main()
{
	unordered_map<string,Record> m {
		{
			"abc", Record("history", "document", 1)
		},
		{
			"bcd", Record("geometry", "maths", 101)
		},
		{
			"def", Record("German", "language", 20390)
		}
	};
	for(auto p:m)
	{
		p.second.print_value();
	}
}