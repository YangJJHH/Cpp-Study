#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define fastio cin.tie(NULL)->sync_with_stdio(false);

using namespace std;

int main()
{
	fastio;
	int N;
	cin >> N;
	long long arr[91] = {0};
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = arr[0] + arr[1];
	for (int i = 3; i <=N; i++)
	{
		arr[i] = arr[i-1] + arr[i-2];
	}
	cout << arr[N];
}