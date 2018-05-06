#include <iostream>
#include <stdexcept>

using namespace std;
class Device {
public:
	Device(int dev_no) {
		if(dev_no==2)
			throw runtime_error("dev is 2");
	}
};
class Broker {
public:
	Broker(int dev1, int dev2)
	try: dev1_(Device(dev1)), dev2_(Device(dev2)) {}//when using try-catch in init-list, have use member(Constr(param)) style
	catch (...) {throw;}
private:
	Device dev1_;
	Device dev2_;
};

int main() {
	// cout<<"throwing error"<<endl;
	// throw runtime_error("problem!");
	// exit(0);

	try{
		Broker b {1,2};
	} catch(exception& e) {
		cout<<"eXcetption:"<<e.what()<<endl;
	}
}