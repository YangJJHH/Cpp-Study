#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <vector>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
using namespace std;
long long A, B, C;

long long solve(long long a, long long b, long long c)
{
	if (b == 1) return a%c;

	long long val = solve(a, b / 2, c);
	val = val * val % c;
	if (b % 2 == 0)
	{
		return val;
	}
	else
	{
		return a * val % c;
	}
}
int main() 
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	cin >> A >> B >> C;

	cout << solve(A, B, C);
	return 0;
}