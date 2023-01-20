#include <iostream>

using namespace std;

class Fraction
{
private:
	int _numerator;
	int _denominator;
public:
	Fraction()
	{
		_numerator = 1;
		_denominator = 1;
	}
	Fraction(const int& num, const int& num2)
	{
		_numerator = num;
		_denominator = num2;
	}
	void print()
	{
		cout << _numerator << " / " << _denominator << endl;
	}
};

int main()
{
	Fraction frac(1, 2);
	Fraction ffrac;
	frac.print();
	return 0;
}