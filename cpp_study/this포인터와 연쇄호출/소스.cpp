#include <iostream>

using namespace std;

class Calc
{
private:
	int _value;
public:
	Calc(int value) : _value(value)
	{};

	/*void add(int value) { _value += value; }
	void sub(int value) { _value -= value; }
	void mult(int value) { _value *= value; }*/


	Calc& add(int value) { _value += value;  return *this; }
	Calc& sub(int value) { _value -= value; return *this; }
	Calc& mult(int value) { _value *= value; return *this; }
	void print() { cout << _value << endl; };
};

int main()
{
	Calc c(10);
	c.add(10).mult(2).sub(9).print();
	Calc& t = c.add(9);
	return 0;
}