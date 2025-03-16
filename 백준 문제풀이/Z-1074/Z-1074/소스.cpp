#define _CRT_SECURE_NO_DEPRECATE
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
int N, R, C;
int Target;
int solve(int n, int r, int c)
{
	if (n == 0) return 0;
	int half = 1 << (n - 1);

	if (r < half && c < half) return solve(n - 1, r, c);
	if (r < half && c >= half) return half * half + solve(n - 1, r, c - half);
	if (r >= half && c < half) return 2 * half * half + solve(n - 1, r - half, c);
	return 3 * half * half + solve(n - 1, r - half, c - half);
}
int main()
{
	fastio;
#ifndef BOJ
	freopen("input.txt", "r", stdin);
#endif // _TEST



	cin >> N >> R >> C;
	cout << solve(N, R, C);
	return 0;
}