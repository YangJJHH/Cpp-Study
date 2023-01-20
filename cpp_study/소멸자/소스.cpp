#include <iostream>

using namespace std;
class Simple
{
private:
	int _id;
public:
	Simple(const int& id) : _id(id)
	{
		cout << "생성자 입니다. id: " << _id << endl;
	}

	~Simple() {
		cout << "소멸자 입니다 id: ." <<_id<< endl;
	}
};
class ArrayClass
{
private:
	int _len;
	int* arr;
public:
	ArrayClass(const int& len) : _len(len)
	{
		arr = new int[_len];
	}
	~ArrayClass() {
		delete[] arr; //소멸자가 실행되면서 알아서 메모리 해제, 소멸자에 delete이 없으면 -> 메모리 누수
	}

};
int main()
{
	//Simple s1(1);
	//Simple* s3 = new Simple(3);
	//Simple s2(2);
	//delete s3;

	while (true)
	{
		ArrayClass arr(1000); // 소멸자 실행 -> delete 메모리 해제
	}
	return 0;
}