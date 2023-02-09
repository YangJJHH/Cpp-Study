#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <string>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
//DP
using namespace std;
int N, J;
int sum[100000];
int arr[100000];
int main()
{
	fastio;
	freopen("input.txt", "r", stdin);
	cin >> N >> J;
	int tmp = 0;
	for (int i = 0; i < N; i++)
	{
		//누적 합을 저장   sum[0] : 0~0까지 합, sum[1] : 0~1까지 합 ...
		cin >> arr[i];
		tmp += arr[i];
		sum[i] =tmp;
	}
	int a, b;
	for (int i = 0; i < J; i++)
	{
		cin >> a >> b;
		cout <<(sum[b-1] - sum[a-1] + arr[a-1]) << "\n";
	}
	
	return 0;
}