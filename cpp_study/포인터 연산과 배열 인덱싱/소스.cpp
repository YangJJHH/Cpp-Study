#include <iostream>
using namespace std;

void Ex1()
{
	int array[] = { 9,7,5,3,1 };
	int* ptr = array;
	for (int i = 0; i < 5; i++)
	{
		cout << *(ptr + i) << '\t' << uintptr_t(ptr + i) << endl;

	}
}

int main()
{
	char name[] = "jackjack";
	const int len = sizeof(name) / sizeof(name[0]);
	char* ptr = name;
	for (int i = 0; i < len; i++)
	{
		cout << *(ptr + i) << endl;
	}
	
}