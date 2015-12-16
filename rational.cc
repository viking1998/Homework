#include<iostream>
using namespace std;
class Rational {
	long denominator_;
	long numerator_;
	
	public:
	
	Rational(long n, long d) {
		numerator_ = n;
		denominator_ = d;
	}
	
	void plus(Rational other)
	{
		numerator_ = denominator_*other.numerator_ + other.denominator_*numerator_;
		denominator_ *= other.denominator_;
	}
	
	void print() {
		cout << numerator_ << "/" << denominator_ << endl;
	}
};

int main()
{
	Rational r1(1, 3);
	Rational r2(2, 3);
	r1.plus(r2);
	r1.print();
	Rational r3(3, 5);
	r2.plus(r3);
	r2.print();
	return 0;
}

