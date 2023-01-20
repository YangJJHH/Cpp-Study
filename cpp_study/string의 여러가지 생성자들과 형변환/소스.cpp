#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string str("my string");
	//example ..
	//string str2(str,3);
	//string str2(str,3,5);
	//string str2(10,'a');
	vector<char> vec;
	for (auto e : "Today is a good day")
	{
		vec.push_back(e);
	}
	string vec_str(vec.begin(), vec.end());
	string vec_str2(vec.begin(),find(vec.begin(),vec.end(),'o'));
	cout << vec_str2 << endl;
	return 0;
}