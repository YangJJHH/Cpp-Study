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
		// �����ϴٰ� �̹� ����Ŭ�� �̷� �׷��� �����ų�, ����Ŭ�� �ƴ� �׷��� �������� ������� �湮�� �׷��� ��� ����Ŭ�� �ƴ�
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

		// �����ϴٰ� �̹� �湮�� �׷��� ��湮�ߴµ� �װ� ���������� �ƴѰ��, ��湮�� ������ �ٽ� ��湮�ҋ����� CYCLE ǥ�ø� �����
		// ������������ ����Ŭ�� �̷�� ������ ������������ NOT_CYCLE ǥ�ø� ����
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

		// ��湮�� ��尡 �ִµ� �װ� ���������� ���, ó������ ���� ��湮 ������ ����Ŭ�� �̷�
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