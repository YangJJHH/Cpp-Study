#include <iostream>
#include <typeinfo>
using namespace std;
void ex1()
{
	// 포인터 예제
	int x = 5;
	cout << x << endl;
	cout << &x << endl;
	cout << (int)&x << endl; // & : address - of operator

	//de - reference operator(*) 직접 그 주소의 값을 들여다 보는
	// 포인터는 메모리의 주소를 담는 변수

	cout << *(&x) << endl;
}
void ex2()
{
	int x = 5;
	double d = 1.45;
	//typedef int* pint; 이런식으로 타입으로 만들어서 사용가능
	int* ptr_x = &x;
	double* ptr_d = &d;
	cout << ptr_x << endl;
	cout << *ptr_x << endl;
	cout << *ptr_d << endl;
	cout << typeid(ptr_x).name() << endl;

}
int main()
{
	ex2();
	return 0;
}

