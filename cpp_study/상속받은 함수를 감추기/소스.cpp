#include <iostream>
#include <string>

using namespace std;
class Base
{
protected:
	int m_i;
public:
	Base(int val = 0) : m_i(val)
	{}

	void print()
	{
		cout <<"I'm base" << m_i << endl;
	}
};

class Derived : public Base
{
private:
	double m_d;
public:
	Derived(int i, double d) : Base(i), m_d(d)
	{}

	using Base::m_i; // main에서 사용가능 (public 처럼)


private:
	using Base::print; //main에서 사용불가능 (private 처럼)
};
int main()
{

	Derived d(1,3.0);
	d.m_i = 1; // using Base::m_i 가 없다면 사용 불가능
	//d.print(); // using Base::print 때문에 불가능
	return 0;
}
