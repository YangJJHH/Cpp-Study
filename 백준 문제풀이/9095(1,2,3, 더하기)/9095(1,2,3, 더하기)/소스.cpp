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
int N,num;
int arr[15];
void Solve()
{
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4; i <= num; ++i)
	{
		arr[i] = arr[i - 1] + arr[i - 2]  + arr[i-3];
	}
	

	cout << arr[num] << '\n';
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
		
		cin >> num;
		Solve();
	}
	return 0;
}