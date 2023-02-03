#include <iostream>

using namespace std;
template<typename T>
T getMax(T a, T b)
{
	return (a > b) ? a : b;
}

//특수한 자료형에서만 처리 ex: char
//템플릿은 컴파일 타임에 정해지기 때문에 if문으로 사용 불가
template<>
char getMax(char a, char b)
{
	cout << "Warning : comparing chars.." << endl;
	return (a > b) ? a : b;
}

int main()
{

	cout << getMax('a', 'b') << endl;
	//cout << getMax(1.0, 2.0) << endl;
	//cout << getMax('a', 'b') << endl;

	return 0;
}