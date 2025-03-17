#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define FILL(arr,val) fill(begin(arr), end(arr), val);
#define CHECK_CONDITION_CONTINUE(condition) if(condition) continue;
#define CHECK_CONDITION_BREAK(condition) if(condition) break;
#define CHECK_CONDITION_RETURN_VOID(condition) if(condition) return;
using namespace std;
const int MAX = 14;
int arr[MAX];
int Combination[MAX];
void solve(int k)
{
	for (int i = 0; i < k; ++i)
	{
		if (i <= 5)
			Combination[i] = 0;
		else
			Combination[i] = 1;
	}
	for (int i = 0; i < k; ++i)
	{
		cin >> arr[i];
	}
	do
	{
		for (int i = 0; i < k; ++i)
		{
			if(Combination[i] == 0)
				cout << arr[i] <<' ';
		}
		cout << '\n';
	} while (std::next_permutation(Combination, Combination + k));
	cout << '\n';
}

int main()
{
	fastio;
#ifndef BOJ
	freopen("input.txt", "r", stdin);
#endif // _TEST

	int k;
	while (true)
	{
		cin >> k;
		CHECK_CONDITION_BREAK(k == 0);
		solve(k);
	}
	return 0;
}