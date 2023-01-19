#include <iostream>
using namespace std;

int main()
{
	//정적 할당 -> stack ,  동적 할당 -> heap . heap이 stack보다 더 크다
	//int var;
	int* ptr = new (nothrow)int; // nothorw : 메모리가 꽉차서 new 가 실패하더라도 ptr = null이 된다
	*ptr = 7;
	cout << *ptr;

	delete ptr; // 메모리 반납
	ptr = nullptr;

	//memory leak;
	while (true)
	{
		int* ptr = new int;
		cout << ptr << endl;
		//delete ptr;
	}

	return 0;
}