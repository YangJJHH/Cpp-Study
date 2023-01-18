#include <iostream>
using namespace std;

void DoSomething(double* ptr) 
{
	if (ptr != nullptr)
	{
		//do something 
		cout << *ptr << endl;
	}
	else 
	{
		cout << "Nothing" << endl;
	}
}

void Address(double *ptr) 
{
	cout << "address of pointer varaible in fun()" << &ptr << endl;
}

int main()
{
	//double* ptr = 0; // c-style
	double* ptr = nullptr; // modern c++ -style

	DoSomething(ptr);
	DoSomething(nullptr);

	double d = 123.4;
	DoSomething(&d);
	ptr = &d;
	DoSomething(ptr);

	cout << "address of pointer varaible in main()" << &ptr << endl;
	Address(ptr);

	return 0;
}