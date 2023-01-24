#include <iostream>
using namespace std;

class Cents
{
private:
	int _cents;
public:
	Cents(int cents = 0) : _cents(cents) {}
	int getCents() const { return _cents; }
	//방법 1. friend
	/*friend Cents operator +(const Cents& c1, const Cents& c2)
	{
		return Cents(c1.getCents() + c2.getCents());
	}*/
	//방법 2. 멤버 함수로 this->
	Cents operator +(const Cents& c2)
	{
		return Cents(this->_cents + c2._cents);
	}
};


int main()
{
	Cents c1(6);
	Cents c2(8);
	Cents sum;
	sum =c1 + c2;
	cout << sum.getCents();
	return 0;
}