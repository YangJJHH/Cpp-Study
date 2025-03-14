#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define FILL(arr,val) fill(begin(arr), end(arr), val);
#define CHECK_CONDITION_CONTINUE(condition) if(condition) continue;
#define CHECK_CONDITION_BREAK(condition) if(condition) break;
#define CHECK_CONDITION_RETURN_VOID(condition) if(condition) return;
using namespace std;
const int MAX = 100005;
int arr[MAX];
int N;
int K;
queue<int> q;
void Teleport(int start)
{
	CHECK_CONDITION_RETURN_VOID(start == 0)

		int next = start;
	while (next < MAX && !arr[K])
	{
		if (!arr[next])
		{
			arr[next] = arr[start];
			q.push(next);
			CHECK_CONDITION_RETURN_VOID(next == K);
		}
		next = next * 2;
	}
}

int main()
{
	fastio;
#ifndef BOJ
	freopen("input.txt", "r", stdin);
#endif // _TEST

	cin >> N >> K;

	arr[N] = 1;
	q.push(N);
	Teleport(N);

	int cur;
	while (!arr[K])
	{
		int cur = q.front(); q.pop();
		vector<int> vec = { cur - 1, cur + 1 };
		for (auto& ele : vec)
		{

			CHECK_CONDITION_CONTINUE(ele < 0 || ele >= MAX);
			CHECK_CONDITION_CONTINUE(arr[ele]);
			arr[ele] = arr[cur] + 1;
			q.push(ele);
			Teleport(ele);
		}

	}

	cout << arr[K] - 1;
	return 0;
}