#include <iostream>
#include <cassert>
using namespace std;

class IntList
{
private:
	int _list[10] = {1,2,3,4,5,6,7,8,9,10};
public:

	int& operator [] (const int index)
	{
		assert(index >= 0);
		assert(index <10);
		return _list[index];
	}
	const int& operator [] (const int index) const
	{
		assert(index >= 0);
		assert(index < 10);
		return _list[index];
	}
};

int main()
{
	IntList my_list;
	my_list[3] = 10;
	cout << my_list[3];


	return 0;
}