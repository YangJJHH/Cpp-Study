#include <iostream> //cout, cin, endl, ...
#include <cstdio> // printf
using namespace std; //using namespace std 사용시 std:: 생략가능

int main()
{
	//cout
	int x = 1024;
	double pi = 3.1213592;

	cout << "output" << endl; 
	cout << x << endl;
	cout << pi << endl;
	cout << "output" <<"\t" << "abc" << endl;
	cout << "outpu" << "\t" << "abc" << endl;

	// cin
	int i;
	cin >> i;

	cout << "Your input is " << i << endl;

	return 0;
}