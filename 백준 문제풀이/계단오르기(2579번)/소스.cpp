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
	vector<int> step(N);
	for (int i = N-1; i >= 0; i++)
	{
		cin >> step[i];
	}
	return 0;
}