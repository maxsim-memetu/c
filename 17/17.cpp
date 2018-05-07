#include <iostream>
#include <string>
#include <chrono>
#include <vector>
using namespace std;

//abstract class.
template<typename T>
class X
{
public:
	int m1;
	T* m2;
	X(T* x):m2{x}{};
	void get();
};
template<typename T>
void X<T>::get()
{
	cout<<m2<<"\n";
}

template<typename C>
class Y
{
public:
	using value_type = C;
	// using iterator = Vector_iter<C>;
	static int m1;
	void get_m1();
};
template<typename C> int Y<C>::m1 = 7;
template<typename C>
void Y<C>::get_m1()
{
	cout<<m1<<"\n";
}

template<typename U>
class complex
{
	U re, im;
public:
	complex():re{}, im{}{}
	template<typename N>
	complex(N rr, N ii=0):re{rr},im{ii}{}
	// template<typename N>
	// complex(const complex&)=default;
};
template<typename T>
void srot(vector<T> as){
	for(int k=0; k<as.size(); k++)
	{
		cout<<as[k]<<"\n";
	}


}

int main()
{
	int so = 8;
	X<int> a {&so};
	a.get();

	Y<string> y;
	y.get_m1();

	vector<string> s = {"a", "b", "c"};
	srot(s);
}