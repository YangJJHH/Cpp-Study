#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define _TEST
using namespace std;

int board[500][500] = {};
bool visit[500][500] = {};
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int N, M;
int MaxSize = 0;
int isize;
int icount = 0;

bool BFS(int i, int j)
{
	if (visit[i][j]) return false;
	if (board[i][j] == false) return false;

	isize = 0;
	queue<pair<int, int>> que;
	que.push({ i,j });
	visit[i][j] = 1;
	while (!que.empty())
	{
		auto cur = que.front();
		que.pop();
		if (board[cur.first][cur.second])
		{
			isize++;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = dx[i] + cur.first;
			int ny = dy[i] + cur.second;

			if (nx >= N || nx < 0 || ny >= M || ny < 0 || visit[nx][ny] || board[nx][ny] == false) continue;

			visit[nx][ny] = 1;
			que.push({ nx,ny });
		}

	}
	MaxSize = max(isize, MaxSize);
	return true;
}
int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	
	cin >> N >> M;
	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >>board[i][j];
		}
	}


	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (BFS(i, j))
				icount++;
		}
	}

	cout << icount << '\n' << MaxSize;
	return 0;
}