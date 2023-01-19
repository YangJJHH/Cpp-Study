#include <iostream>

using namespace std;
int main()
{
	int length;
	cin >> length;
	int* array = new int[length]();
	for (int i = 0; i < length; i++)
	{
		array[i] = i;
		cout << array[i] << endl;
	}
	delete [] array;
	return 0;
}