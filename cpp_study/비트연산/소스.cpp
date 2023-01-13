#include <iostream>
#include <bitset>


int main()
{
	using namespace std;

	unsigned int a = 1;
	//Left Shift
	cout << bitset<8>(a) << " " << a << endl;

	a = a << 1;
	cout << bitset<8>(a) << " " << a << endl;

	//Right Shift
	unsigned int b = 1024;
	cout << bitset<16>(b) << " " << b << endl;

	b = b >> 3;
	cout << bitset<16>(b) << " " << b << endl;

	//not
	a = ~a;
	cout << bitset<8>(a) << " " << a << endl;

	//and, or , xor

	unsigned c = 0b1100;
	unsigned d = 0b0110;

	cout << bitset<4>(c | d) << endl;
	cout << bitset<4>(c & d) << endl;
	cout << bitset<4>(c ^ d) << endl;
}