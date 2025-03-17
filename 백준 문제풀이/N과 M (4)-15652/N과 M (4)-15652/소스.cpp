#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <vector>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define FILL(arr,val) fill(begin(arr), end(arr), val);
#define CHECK_CONDITION_CONTINUE(condition) if(condition) continue;
#define CHECK_CONDITION_BREAK(condition) if(condition) break;
#define CHECK_CONDITION_RETURN_VOID(condition) if(condition) return;
using namespace std;

const int MAX = 9;
int arr[MAX];
int N, M;

void solve(int k)
{
	if (k == M)
	{
		for (int i = 0; i < M; ++i)
		{
			cout << arr[i] + 1 << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		if (k > 0 && arr[k - 1] > i) continue;

		arr[k] = i;
		solve(k + 1);
	}
}

int main()
{
	fastio;
#ifndef BOJ
	freopen("input.txt", "r", stdin);
#endif // _TEST
	cin >> N >> M;
	solve(0);

	return 0;
}