#include <vector>
#include <iostream>
#include <stack>
using namespace std;
class YouKnow
{
public:
	string get_value(){
		return std::to_string(self_value);
	}
	YouKnow(int v):self_value{v}{};
private:
	int self_value;
};

int main()
{
	vector<YouKnow> s {YouKnow(1),YouKnow(2)};

	cout<<"hello world\n";
	for (auto k:s)
	{
		cout<<k.get_value()<<"\n";
	}
	s.push_back(YouKnow(3));
	for(auto i:s)
	{
		cout<<i.get_value()<<"\n";
	}
	stack ss;
	ss.push(YouKnow(9));
	ss.push(YouKnow(100));
	cout<<"now we have a look at ss\n";
	for(auto i:ss)
	{
		cout<<i.get_value()<<"\n";
	}
	ss.pop();
	for(auto i:ss)
	{
		cout<<i.get_value()<<"\n";
	}
}