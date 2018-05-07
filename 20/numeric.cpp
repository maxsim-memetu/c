#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
#include <valarray>
#include <random>
using namespace std;
typedef void (*fun)(int);
void k(int si){cout<<"in k:"<<si+1<<endl;};
int main()
{
	cout<<sqrt(10)<<endl;
	cout<<sin(10)<<endl;
	complex<int> s {1,2};
	cout<<s.real()<<endl;

	int ar[4] = {3,4,5,6};
	// valarray<int> s1 {10, 11,10};
	valarray<int> s1 {ar, 4};
	cout<<"s1[0] is:"<<s1[0]<<endl;
	for (int i: s1)
	{
		cout<<s1[i]<<endl;
	}
	cout<<"size of va is:"<<s1.size()<<endl;

	valarray<int> s3 = s1.apply([](int a){return a+1;});
	for (int k : s3)
	{
		cout<<"after apply:"<<s3[k]<<endl;
	}
	for (int o: s1)
	{
		cout<<"orig s1:"<<s1[o]<<endl;
	}


	auto gen = bind(normal_distribution<double>{15,4.0},default_random_engine{});
	for (int i=0; i<500; ++i) cout << gen() <<endl;//generator, like in python.
	
	//fun = &k;
	//(*fun)(10);
	fun k[10];
	//vector<fun> vfp;
}
