#include <iostream>
#include <thread>
#include <string>
#include <chrono>
using namespace std;
// using namespace std::chrono_literals;
void func1(string str1) {
	while(true) {
		cout<<str1;
		// this_thread::sleep_for(second(1));
		// this_thread::sleep_for(1s);
		this_thread::sleep_for(std::chrono::seconds(1));
		cout<<" ending wakup func1"<<endl;
	}
}
void func2(string str2) {
	while(true) {
		cout<<str2;
		// this_thread::sleep_for(second(1));
		this_thread::sleep_for(std::chrono::seconds(1));
		cout<<"ending wakeup func2"<<endl;
	}
}


int main() {
	thread th1 {func1, "foo"};
	thread th2 {func2, "bar"};

	th1.join();
	th2.join();
}
