#include <iostream>
#include <cassert>

using namespace std;

template<typename T>
class MyArray
{
private:
	T* _data;
	int _length;
public:
	MyArray()
	{
		_data = nullptr;
		_length = 0;
	}
	MyArray(int length) : _length(length)
	{
		_data = new T[length];
	}
	void reset()
	{
		delete[] _data;
		_data = nullptr;
		_length = 0;
	}

	~MyArray()
	{
		reset();
	}
	
	

	T& operator[](int index)
	{
		assert(index >=0 && index<_length);
		return _data[index];
	}
	int getLength()
	{
		return _length;
	}

	void print()
	{
		for (int i = 0; i < _length; i++)
		{
			cout << _data[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	MyArray<char> arr(10);
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i+ 65;
	}
	arr.print();
}