#include<iostream>
using namespace std;

struct Point 
{
	double x_;
	double y_;

	double get_x()
	{
		return x_;
	}

	double get_y()
	{
		return y_;
	}
};

int main()
{
	struct Point p1; // C
	Point p2; // C++
	p1.x_ = 1.0;
	p1.y_ = 2.0;
	
	p2.x_ = 3.0;
	p2.y_ = 6.0;
	
	cout << p1.get_x() << ' ' << p1.get_y() << endl;
	
	return 0;
}
