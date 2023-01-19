#include <iostream>
#include <array>
#include <algorithm> //sort
using namespace std;
void printArray(const array<int,5> &arr) { //array는 함수로 전달되도 포인터로 변환되지 않는다.
										   // 불필요한 복사가 일어나지 않도록 참조로 받기
	for (auto i : arr) {
		cout << i << " ";
	}
}
void SortingArr(array<int,5> &arr) {
	sort(arr.begin(), arr.end());
}
int main()
{
	int arr1[] = {1,2,3,4,5};
	array<int, 5> arr2 = {11, 2, 23, 4, 45};

	cout << arr2[0] << endl;
	cout << arr2.at(0) << endl;
	SortingArr(arr2);
	printArray(arr2);
	return 0;
}