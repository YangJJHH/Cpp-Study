#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <queue>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define FILL(arr,val) memset(arr, val, sizeof(arr));
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
#define X first
#define Y second
using namespace std;
int T;
int w, h;
string board[1000];
int dist[1000][1000];
int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	cin >> T;

	while (T--)
	{
		cin >> w >> h;
		queue<pair<int, int>> q;
		vector<pair<int, int>> fire;
		for (int i = 0; i < h; ++i)
		{
			cin >> board[i];
			for (int j = 0; j < w; ++j)
			{
				if (board[i][j] == '*')
					fire.push_back({ i,j });
				if (board[i][j] == '@')
					q.push({ i,j });
			}
		}

		for (auto& ele : fire)
			q.push(ele);

		int answer = -1;
		FILL(dist, 0);
		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();
			if (board[cur.X][cur.Y] == '@')
			{
				if (cur.X == h - 1 || cur.X == 0 || cur.Y == w - 1 || cur.Y == 0)
				{
					answer = dist[cur.X][cur.Y] + 1;
					break;
				}

				for (int i = 0; i < 4; ++i)
				{
					int x = dx[i] + cur.X;
					int y = dy[i] + cur.Y;
					if (x < 0 || x >= h || y < 0 || y >= w) continue;
					if (board[x][y] != '.') continue;

					dist[x][y] = dist[cur.X][cur.Y] + 1;
					board[x][y] = '@';
					q.push({ x,y });
				}
			}
			else if (board[cur.X][cur.Y] == '*')
			{
				for (int i = 0; i < 4; ++i)
				{
					int x = dx[i] + cur.X;
					int y = dy[i] + cur.Y;
					if (x < 0 || x >= h || y < 0 || y >= w || board[x][y] == '#') continue;
					if (board[x][y] == '#') continue;
					if (board[x][y] == '*') continue;

					board[x][y] = '*';
					q.push({ x,y });
				}
			}
		}
		if (answer < 0)
			cout << "IMPOSSIBLE" << '\n';
		else
			cout << answer << '\n';
	}

	return 0;
}