#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Y
{
public:
	Y(int arg_y):y{arg_y}{};
	void print_value();
	int y;
};
void Y::print_value()
{
	cout<<"y's value is:"<<y<<"at a location:"<<this<<endl;
}

int main()
{
	Y y1 {1};
	Y y2 {2};
	Y y3 {3};
	Y y4 {4};
	// vector<Y> vec_y {
	// 	Y(1),
	// 	Y(2),
	// 	Y(3),
	// 	Y(4)
	// };
	cout<<&y1<<endl<<&y2<<endl<<&y3<<endl<<&y4<<endl;
	vector<Y> vec_y {y1,y2,y3,y4};
	for(auto k:vec_y)
	{
		k.print_value();
	}
	for_each(vec_y.begin(),vec_y.end(),[](Y& x){++x.y;});
	for(auto k:vec_y){k.print_value();}
	vector<int> v {1,2,3,4,5,6,7};
	auto p = find(v.begin(), v.end(), 7);
	// p == v.end() ? cout<<"Y" : cout<<"N";
	cout<<*p<<endl;
	cout<<*(v.end()-1)<<endl;//p do not equal v.end() if no elem is found. v.end() points to end+1 position.
}
