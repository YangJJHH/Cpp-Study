#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <queue>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define FILL(arr,val) memset(arr, val, sizeof(arr));
using namespace std;
int T,L;
int board[302][302];
bool visit[302][302];
int dx[8] = { -2, -1, 1, 2,  2,  1, -1, -2};
int dy[8] = {  1,  2, 2, 1, -1, -2, -2, -1};
#define X first
#define Y second

int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	cin >> T;

	while (T--)
	{
		FILL(visit, false);
		FILL(board, 0);
		cin >> L;
		int x, y;
		cin >> x >> y;
		queue<pair<int, int>> q;
		q.push({ x,y });
		visit[x][y] = true;

		pair<int, int> target;
		cin >> x >> y;
		target.X = x;
		target.Y = y;

		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();
			if (cur.X == target.X && cur.Y == target.Y)
			{
				cout << board[cur.X][cur.Y] << '\n';
				break;
			}

			for (int i = 0; i < 8; ++i)
			{
				int curX = cur.X + dx[i];
				int curY = cur.Y + dy[i];

				if (curX >= 0 && curX < L && curY >= 0 && curY < L && visit[curX][curY] == false)
				{
					board[curX][curY] = board[cur.X][cur.Y] + 1;
					visit[curX][curY] = true;
					q.push({ curX,curY });
				}
			}
		}
	}
	

	return 0;
}