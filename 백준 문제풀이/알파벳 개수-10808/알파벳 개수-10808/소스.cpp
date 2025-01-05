#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define _TEST
using namespace std;

int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST

	const int len = 'z' - 'a'+1;
	int arr[len] = {};
	string input;
	cin >> input;
	for (int i = 0; i < input.size(); ++i)
	{
		int idx = input[i] -'a';
		arr[idx]++;
	}
	for (int i = 0; i < len; ++i)
	{
		cout << arr[i] << " ";
	}
	
	return 0;
}