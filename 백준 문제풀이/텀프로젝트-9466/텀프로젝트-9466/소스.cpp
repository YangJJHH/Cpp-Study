#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define FILL(arr,val) memset(arr, val, sizeof(arr));
using namespace std;
const int NOT_VISITED = 0;
const int VISITED = 1;
const int CYCLE = 2;
const int NOT_CYCLE = 3;
int T,N;
int arr[1000002];
int state[1000002];
void Run(int x)
{
	int cur = x;
	while (true)
	{
		state[cur] = VISITED;
		cur = arr[cur];
		// 진행하다가 이미 싸이클을 이룬 그롭을 만났거나, 싸이클이 아닌 그룹을 만날경우는 현재까지 방문한 그룹이 모드 싸이클이 아님
		if (state[cur] == CYCLE || state[cur] == NOT_CYCLE)
		{
			cur = x;
			while (state[cur] == VISITED)
			{
				state[cur] = NOT_CYCLE;
				cur = arr[cur];
			}
			return;
		}

		// 진행하다가 이미 방문한 그룹을 재방문했는데 그게 시작지점이 아닌경우, 재방문한 노드부터 다시 재방문할떄까지 CYCLE 표시를 남기고
		// 시작지점부터 싸이클을 이루는 지점을 만나기전까지 NOT_CYCLE 표시를 남김
		if (state[cur] == VISITED && cur != x)
		{
			while (state[cur] != CYCLE)
			{
				state[cur] = CYCLE;
				cur = arr[cur];
			}

			cur = x;
			while (state[cur] != CYCLE)
			{
				state[cur] = NOT_CYCLE;
				cur = arr[cur];
			}
			return;
		}

		// 재방문한 노드가 있는데 그게 시작지점인 경우, 처음부터 현재 재방문 노드까지 싸이클을 이룸
		if (state[cur] == VISITED && cur == x)
		{
			while (state[cur] != CYCLE)
			{
				state[cur] = CYCLE;
				cur = arr[cur];
			}
			return;
		}
	}
	
}
int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	cin >> T;

	while (T--)
	{
		int Sum = 0;
		cin >> N;
		for (int i = 1; i <= N; ++i)
		{
			cin >> arr[i];
		}
		//fill(state + 1, state + N + 1, 0);
		memset(state, 0x00, sizeof(state)); 
		for (int i = 1; i <= N; ++i)
		{
			if (state[i] == NOT_VISITED)
				Run(i);
		}

		Sum = 0;
		for (int i = 1; i <= N; ++i)
		{
			if (state[i] == NOT_CYCLE)
				Sum++;
		}

		cout << Sum << '\n';
	}


	return 0;
}