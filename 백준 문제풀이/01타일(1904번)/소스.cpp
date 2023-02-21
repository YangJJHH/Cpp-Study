#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
using namespace std;
int N;
long long arr[1000000]{ 0,1,2 };
int main()
{
	fastio;
	cin >> N;
	long long tmp;
	for (int i = 3; i <= N; i++)
	{
		tmp = arr[i - 1] + arr[i - 2];
		arr[i] = tmp % 15746;
	}
	cout << arr[N] % 15746;
	return 0;
}