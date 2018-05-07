#include <complex>
#include <iostream>

using namespace std;


template<class T>
struct BasicPolar {
public:
	typedef BasicPolar self;
	//contructor
	BasicPolar():m(){}
	BasicPolar(const self& x):m(x.m){}
	BasicPolar(const T& rho, const T& theta):m(polar(rho, theta)){}

	//assignment operator
	self operator-() { return Polar(-m); } //this object will be passed to operator by default? so that this need not appear in parameter list? maybe not, it's the return type.
	self& operator+=(const self& x) { m += x.m; return *this; }
	self& operator-=(const self& x) { m -= x.m; return *this; }
	self& operator*=(const self& x) { m *= x.m; return *this; }
	self& operator/=(const self& x) { m /= x.m; return *this; }

	// public member functions
	T rho() const { return abs(m); }
	T theta() const { return arg(m); }

	// binary operations
	friend self operator+(self& x, const self& y) { return x += y; } // y is added to x's space, then return this x
	friend self operator-(self& x, const self& y) { return x -= y; }
	friend self operator*(self& x, const self& y) { return x *= y; }
	friend self operator/(self& x, const self& y) { return x /= y; }

	// comparision operators
	friend bool operator<(const self& x, const self& y) { return x.rho() < y.rho(); }
	friend bool operator>(const self& x, const self& y) { return x.rho() > y.rho(); }
	friend bool operator==(const self& x, const self& y) { return x.m == y.m; }
	friend bool operator!=(const self& x, const self& y) { return x.m != y.m; }
	private:
		complex<T> m;
};

typedef BasicPolar<double> Polar;

int main() {

	double rho = 3.0; //magnitude
	double theta = 3.1415926/2; //angle
	Polar coord(rho, theta);
	cout<<"R:"<<coord.rho()<<"| THETA:"<<coord.theta()<<endl;
	Polar d(4.0, 0.0);
	coord += d;
	cout<<"AFTER ADDITION, R:"<<coord.rho()<<"| THETA:"<<coord.theta()<<endl;
	system("pause");
}