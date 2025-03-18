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
const int MAX = 16;
int L, C;
char arr[MAX];
char answer[MAX];

inline bool isVowel(const char &ch)
{
	return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

void solve(int start, int k, int m, int z) // m : 모음, j : 자음 갯수
{
	if (k == L && m >= 1 && z >= 2)
	{
		for (int i = 0; i < k; ++i)
		{
			cout << answer[i];
		}
		cout << '\n';
		return;
	}

	for (int i = start; i < C; ++i)
	{
		int newM, newZ;
		newM = m;
		newZ = z;
		if (isVowel(arr[i]))
			++newM;
		else
			++newZ;

		answer[k] = arr[i];
		solve(i + 1, k + 1, newM, newZ);
	}

}
int main()
{
	fastio;
#ifndef BOJ
	freopen("input.txt", "r", stdin);
#endif // _TEST
	cin >> L >> C;

	for (int i = 0; i < C; ++i)
	{
		cin >> arr[i];
	}
	sort(arr, arr + C);

	solve(0, 0, 0, 0);
	return 0;
}