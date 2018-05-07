#include <iostream>
#include <string>
#include <chrono>
#include <vector>
using namespace std;

//abstract class.
class Shape
{
public:
	virtual void rotate(int)=0;
	virtual void draw() const = 0;
	virtual bool is_closed() const=0;
	virtual ~Shape();
};

class Point {};
class Circle:public Shape
{
public:
	void rotate(int) override {}
	void draw() const override;
	bool is_closed() const override {return true;}

	Circle(Point p, int r);
private:
	Point center;
	int radius;
};
int main()
{
	Shape s;//error: variable type 'Shape' is an abstract class
	Point p;
	Circle c = {p, 10};
}