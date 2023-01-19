#include <iostream>

using namespace std;

void Ex1() {
	//다중포인터
	int* ptr = nullptr;
	int** ptrptr = nullptr;
	int value = 10;
	ptr = &value;
	ptrptr = &ptr;

	cout << **ptrptr;
}

int main()
{
	const int row = 3;
	const int col = 5;
	const int s2da[row][col] =
	{
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15}
	};
	//다차원배열
	int** matrix = new int* [col];
	for (int r = 0; r < 3; r++) {
		matrix[r] = new int[col];
	}
	//initial
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 5; c++) {
			matrix[r][c] = s2da[r][c];
		}
		
	}
	//print
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 5; c++) {
			cout << matrix[r][c] << " ";
		}
		cout << endl;
	}
	//delete
	for (int r = 0; r < 3; r++) {
		delete [] matrix[r];
	}
	delete[] matrix;
	return 0;
}