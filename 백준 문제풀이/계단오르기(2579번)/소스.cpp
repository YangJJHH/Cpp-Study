#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
using namespace std;

int N;


int main()
{
	fastio;
	freopen("input.txt", "r", stdin);
	cin >> N;
	int step[301];
	int DP[301];

	for (int i =1; i <= N; i++)
	{
		cin >> step[i];
	}
	DP[1] = step[1];
	DP[2] = step[1] + step[2];
	DP[3] = max(step[1]+step[3],step[2] + step[3]);
	for (int i=4; i<=N; i++)
	{
		DP[i] = max(DP[i-2]+step[i], step[i] + step[i-1] + DP[i-3]);
	}
	cout << DP[N];
	return 0;
}