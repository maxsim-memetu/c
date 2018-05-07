#include <iostream>
#include <string>

using namespace std;

//using template and pointer
template<class T> class Handle
{
public:
	T* p;
public:
	Handle(T* pp):p{pp}{}
	T& operator*(){return *p;}
	~Handle(){delete p;}
};

int main()
{
	Handle<int> handle1 {new int};
	cout<<*(handle1.p)<<"\n";
}