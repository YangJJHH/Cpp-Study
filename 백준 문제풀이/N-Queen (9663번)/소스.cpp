#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
//백트레킹
int N;
int rst = 0;
int board[15];
int check(int idx)
{
	for (int i=0; i<idx; i++)
	{
		if (board[idx] == board[i] || abs(idx - i) == abs(board[idx] - board[i]))
		{
			return 0;
		}
	}
	return 1;
}
void DFS(int cnt)
{
	if (cnt == N)
	{
		rst++;
		return;
	}
	for (int i = 0; i < N; i++)
	{
		board[cnt] = i;
		if (check(cnt))
		{
			DFS(cnt + 1);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	DFS(0);
	cout << rst;
	return 0;
}