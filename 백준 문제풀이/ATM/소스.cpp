#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
//±×¸®µð
using namespace std;
int N;
int arr[1001];
int main()
{
	fastio;
	freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	
	sort(arr, arr+N);
	int sum = arr[0];
	for (int i = 1; i < N; i++)
	{
		arr[i] = arr[i] + arr[i - 1];
		sum += arr[i];
	}
	cout << sum;
	return 0;
}