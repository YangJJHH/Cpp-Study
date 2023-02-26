#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
using namespace std;

long long arr[100] = { 1,1,1,2,2,3,4,5,7,9 };

void func(int n)
{
	for (int i = 10; i < n; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 5];
	}
	cout << arr[n - 1] << "\n";
}
int main()
{
	fastio;
	freopen("input.txt", "r", stdin);
	int T, N;
	cin >> T;
	for (int i=0; i<T; i++)
	{
		cin >> N;
		if (N < 10)
		{
			cout << arr[N-1] << "\n";
		}
		else
		{
			func(N);
		}
	}
	return 0;
}
