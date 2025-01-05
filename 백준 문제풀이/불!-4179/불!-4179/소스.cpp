#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define MX 1000
#define X first
#define Y second
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
string board[MX];
int dist[MX][MX];
int R, C;
bool bSuccess = false;
int answer;
queue<pair<int, int>> q;
bool SuccessMiro(int nx, int ny)
{
	return (nx == 0 || nx == R - 1 || ny == 0 || ny == C - 1);
}
int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	cin >> R >> C;
	queue<pair<int, int>> fire;
	for (int i = 0; i < R; ++i)
	{
		cin >> board[i];
		for (int j = 0; j < C; ++j)
		{
			if (board[i][j] == 'J')
				q.push({ i,j });
			if (board[i][j] == 'F')
				fire.push({ i,j });
		}
		
	}
	while (!fire.empty()) // 지훈이 먼저 출발하기 위해
	{
		auto ele = fire.front();
		fire.pop();
		q.push(ele);
	}

	while (!q.empty() && !bSuccess)
	{
		auto& ele = q.front();
		q.pop();

		if (board[ele.X][ele.Y] == 'J')
		{
			if (SuccessMiro(ele.X, ele.Y))
			{
				answer = dist[ele.X][ele.Y] + 1;
				bSuccess = true;
				break;
			}

			for (int i = 0; i < 4; ++i)
			{
				int nx = ele.X + dx[i];
				int ny = ele.Y + dy[i];

				if( nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
				if (board[nx][ny] == 'J') continue;
				if (board[nx][ny] == 'P') continue;
				if( board[nx][ny] == '#') continue;
				if (board[nx][ny] == 'F') continue;

				board[nx][ny] = 'J';
				board[ele.X][ele.Y] = 'P';
				dist[nx][ny] = dist[ele.X][ele.Y] + 1;
				q.push({ nx,ny });
			}
			if (bSuccess)
				break;
		}
		else if (board[ele.X][ele.Y] == 'F')
		{

			for (int i = 0; i < 4; ++i)
			{
				int nx = ele.X + dx[i];
				int ny = ele.Y + dy[i];

				if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
				if (board[nx][ny] == '#') continue;
				if (board[nx][ny] == 'F') continue;
				board[nx][ny] = 'F';
				q.push({ nx,ny });
			}
		}
	}

	if (bSuccess)
		cout << answer;
	else
		cout << "IMPOSSIBLE";
	return 0;
}