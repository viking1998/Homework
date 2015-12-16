#include<iostream>
using namespace std;

class Point
{
	double x_;
	double y_;
	
	public:
		void set_x(double x)
		{
			x_ = x;
		}
		void set_y(double y)
		{
			y_ = y;
		}
};

int main()
{
	Point p1;
	p1.set_x( 1.0 );
	p1.set_y( 2.0 );
	
	return 0;
}
