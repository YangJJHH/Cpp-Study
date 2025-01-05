#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define _TEST
#define MX 502
#define X first
#define Y second
using namespace std;
int N, M;
int board[MX][MX];
bool visit[MX][MX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int answer = 0;
int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	cin >> N >> M;
	string number;
	for (int i = 0; i < N; ++i)
	{
		cin >> number;
		for (int j = 0; j < M; ++j)
		{
			board[i][j] = number[j] - '0';
		}
	}

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visit[0][0] = 1;
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		if (cur.X == N - 1 && cur.Y == M - 1)
		{
			answer = board[cur.X][cur.Y];
			break;
		}
		for (int i = 0; i < 4; ++i)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if(nx >= N || nx < 0 || ny >= M || ny < 0) continue;
			if(visit[nx][ny] || board[nx][ny] == 0) continue;

			board[nx][ny] = board[cur.X][cur.Y] + 1;
			q.push({ nx,ny });
			visit[nx][ny] = 1;
		}

	}

	cout << answer;
	return 0;
}