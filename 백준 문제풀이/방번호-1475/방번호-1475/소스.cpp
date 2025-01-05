#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <vector>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
using namespace std;

int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	string RoomNum;
	cin >> RoomNum;

	int arr[10] = { 0 };
	int setCount = 0;
	for (auto& ele : RoomNum)
	{
		int num = ele - '0';
		if (num == 9 || num == 6)
		{
			num = arr[9] > arr[6] ? 6 : 9;
		}
		arr[num]++;

		setCount = max(setCount, arr[num]);
	}
	cout << setCount;
	return 0;
}