#include <iostream>

using namespace std;

void Ex1() {
	int value = 5;
	//int *conts ptr = &value;
	int& ref = value;

	// 둘이 같은 값이 나옴
	cout << &ref << '\t' << &value << endl;
	cout << ref << '\t' << value << endl;
	ref = 10; // *ptr = 10;

	cout << ref << '\t' << value << endl;
}
void DoSomething(int &n)
{
	n = 10;
	cout << "IN DOSomething " << n <<'\t' <<&n<< endl;
}
int main()
{
	int  n = 5;
	DoSomething(n);
	cout << "In Main " << n << '\t' << &n << endl;
	return 0;
}