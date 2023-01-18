#include <iostream>
using namespace std;
void PrintArray(int arr[]) // int arr[] == int *arr 같은 의미
{
	cout << sizeof(arr) << endl; // arr이 내부적으로는 포인터이기 때문에 8나옴
}
int main()
{
	int array[5] = { 9,3,5,3,1 };
	int* ptr = array;
	cout << array << endl;
	cout << *ptr  << endl;

	cout << sizeof(array) << endl; // 20
	PrintArray(array); // 8
	/*char name[] = "JaeHyeock";
	cout << *name << endl;*/
}