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
int N;
void Hanoi(int start, int end, int k)
{
	if (k == 1)
	{
		cout << start << " " << end << '\n';
		return;
	}

	Hanoi(start, 6 - start - end, k - 1);
	cout << start << " " << end << '\n';
	Hanoi(6 - start - end, end, k - 1);
}
int main()
{
	fastio;
#ifndef BOJ
	freopen("input.txt", "r", stdin);
#endif // _TEST
	cin >> N;

	cout << (1 << N) - 1 << '\n';
	Hanoi(1, 3, N);

	return 0;
}