#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define FILL(arr,val) fill(begin(arr), end(arr), val);
#define CHECK_CONDITION_CONTINUE(condition) if(condition) continue;
#define CHECK_CONDITION_BREAK(condition) if(condition) break;
#define CHECK_CONDITION_RETURN_VOID(condition) if(condition) return;
using namespace std;
int N;
const int maxSize = 1000002;
int arr[maxSize];

int main()
{
	fastio;
#ifndef BOJ
	freopen("input.txt", "r", stdin);
#endif // _TEST
	cin >> N;
	FILL(arr, maxSize);
	
	queue<int> q;
	q.push(N);
	arr[N] = 0;
	while (!q.empty())
	{
		auto curIdx = q.front(); 
		q.pop();

		if (curIdx == 1) break;
		auto curValue = arr[curIdx];
		auto nextValue = curValue + 1;

		// 1빼기
		{
			auto nextIdx = curIdx - 1;
			if (arr[nextIdx] > nextValue)
			{
				arr[nextIdx] = nextValue;
				q.push(nextIdx);
			}
		}

		// 3나누기
		if (curIdx % 3 == 0)
		{
			auto nextIdx = curIdx / 3;
			if (arr[nextIdx] > nextValue)
			{
				arr[nextIdx] = nextValue;
				q.push(nextIdx);
			}
		}

		// 2나누기
		if (curIdx % 2 == 0)
		{
			auto nextIdx = curIdx / 2;
			if (arr[nextIdx] > nextValue)
			{
				arr[nextIdx] = nextValue;
				q.push(nextIdx);
			}
		}
		
	}

	cout << arr[1];
	return 0;
}