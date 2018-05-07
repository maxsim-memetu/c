#ifndef STRIDE_ITER_HPP
#define STRIDE_ITER_HPP



#include <iterator>
#include <cassert>

template<class Iter_T>
class stride_iter {
public:
	typedef typename std::iterator_traits<Iter_T>::value_type value_type;
	typedef typename std::iterator_traits<Iter_T>::reference reference;
	typedef typename std::iterator_traits<Iter_T>::difference_type difference_type;

	typedef typename std::iterator_traits<Iter_T>::pointer pointer;
	typedef typename std::random_access_iterator_tag iterator_category;
	typedef stride_iter self;

	//contructor
	stride_iter():m(NULL), step(0){};
	stride_iter(const self& x):m(x.m),step(x.step){};
	stride_iter(Iter_T t, difference_type d):m(t), step(d){};

	//operator
	self& operator++( ) {m+=step;return *this;}
	self operator++(int) {self tmp = *this; m+=step; return tmp;}
	self& operator+=(difference_type x) {m = m + x*step; return *this;}
	self& operator--( ) {m-=step; return *this;}
	self operator--(int) {self tmp = *this; m-=step; return tmp;}
	self& operator-=(difference_type x) {m = m - step*x; return *this;}

	reference operator[](difference_type n) {return m[n*step];}
	reference operator*( ) {return *m;}

	//friend operators
	friend bool operator==(const self& x, const self& y) {
		assert(x.step == y.step);
		return x.m == y.m;
	}
	friend bool operator!=(const self& x, const self& y) {
		assert(x.step == y.step);
		return x.m != y.m;
	}
	friend bool operator<(const self& x, const self& y) {
		assert(x.step == y.step);
		return x.m < y.m;
	}
	friend difference_type operator-(const self& x, const self& y) {
		assert(x.step == y.step);
		return (x.m - y.m)/x.step;
	}
	friend self operator+(difference_type x, const self& y) {
		assert(x.step == y.step);
		return y += x*y.step;
	}
	friend self operator+(const self& x, difference_type y) {
		assert(x.step == y.step);
		return x+= y*x.step;
	}
private:
	Iter_T m;
	difference_type step;
};
#endif