#include <iostream>

using namespace std;
template<typename T>
T getMax(T a, T b)
{
	return (a > b) ? a : b;
}
int main() 
{
	
	cout << getMax(1, 2) << endl;
	cout << getMax(1.0, 2.0) << endl;
	cout << getMax('a', 'b') << endl;

	return 0;
}