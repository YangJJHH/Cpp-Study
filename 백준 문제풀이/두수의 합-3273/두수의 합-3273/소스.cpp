#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <vector>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
using namespace std;
int N;
int arr[100002];
int X;
int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	cin >> N;

	vector<int> vec(N,0);
	int val;
	for (int i = 0; i < N; ++i)
	{
		cin >> vec[i];
	}

	cin >> X;

	int answer = 0;
	for (auto& ele : vec)
	{
		int val = X - ele;
		if (val >= 0 )
		{
			if( arr[val] )
				answer++;
			arr[ele] = 1;
		}
	}
	cout << answer;
	return 0;
}