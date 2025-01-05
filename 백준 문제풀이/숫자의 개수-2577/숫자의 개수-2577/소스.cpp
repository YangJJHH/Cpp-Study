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
	int A, B, C;
	cin >> A >> B >> C;
	int result = A * B * C;
	string strNum = to_string(result);
	vector<int> vec(10,0);

	for (int i = 0; i<strNum.length(); ++i)
	{
		int idx = strNum[i] - '0';
		vec[idx]++;
	}

	for (auto& ele : vec)
	{
		cout << ele << "\n";
	}

	return 0;
}