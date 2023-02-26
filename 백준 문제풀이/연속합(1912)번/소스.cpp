#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
using namespace std;
int N;
int main()
{
	freopen("input.txt", "r", stdin);
	fastio;
	cin >> N;
	int arr_sum;
	cin >> arr_sum;
	int n;
	for (int i = 1; i < N; i++)
	{
		cin >> n;
		if (n + arr_sum < n)
		{
			arr_sum = n;
		}
		else
		{
			arr_sum += n;
		}
	}
	cout << arr_sum;
	return 0;
}