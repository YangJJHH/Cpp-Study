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
enum
{
	MINUS_ONE = 0,
	ZERO,
	ONE,
	MAX,
};
int arr[MAX];
int N;
int paper[2200][2200];

void Count(int r, int c)
{
	int value = paper[r][c];
	switch (value)
	{
	case 0: arr[ZERO]++; break;
	case 1: arr[ONE]++;	break;
	case -1: arr[MINUS_ONE]++; break;
	
	default:
		break;
	}
}

void solve(int n, int r, int c)
{
	if (n == 1)
	{
		Count(r, c);
		return;
	}

	int start = paper[r][c];
	bool same = true;
	for (int i = r; i < n+r; ++i)
	{
		for (int j = c; j < n+c; ++j)
		{
			int cur = paper[i][j];
			same = (cur == start);
			if (!same)
				break;
		}
		if (!same)
			break;
	}

	if (same)
	{
		Count(r, c);
		return;
	}

	int newN = n / 3;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			solve(newN, r + i*newN, c + j*newN);
		}
	}
		
}

int main()
{
	fastio;
#ifndef BOJ
	freopen("input.txt", "r", stdin);
#endif // _TEST
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			cin >> paper[i][j];
	}

	solve(N,0,0);
	for (auto &ele : arr)
	{
		cout << ele << '\n';
	}
	return 0;
}