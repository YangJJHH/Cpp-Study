#include <iostream>

using namespace std;

int Foo() {
	return 10;
}

int Goo()
{
	return 5;
}

int main()
{
	int(*fcnptr)() = Foo;

	cout << fcnptr() << endl;
	fcnptr = Goo;
	cout << fcnptr() << endl;

	return 0;
}