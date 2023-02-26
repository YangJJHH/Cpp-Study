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
	vector<int> max_sum;
	max_sum.push_back(arr_sum);
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
		max_sum.push_back(arr_sum);
	}
	cout << *max_element(max_sum.begin(), max_sum.end());
	return 0;
}