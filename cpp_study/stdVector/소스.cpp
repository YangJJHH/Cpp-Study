#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> arr = { 1,2,3,4,5 };
	cout << arr.size() << endl;
	
	for (auto& itr : arr)
	{
		cout << itr << " ";
	}
	
	
	return 0;
}