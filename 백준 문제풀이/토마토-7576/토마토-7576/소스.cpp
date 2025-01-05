#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <iostream>
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <string>
#include <vector>
#include <queue>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define MX 1002
#define X first
#define Y second
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int dist[MX][MX];
int box[MX][MX];
int N, M;
int MinDay = INT_MAX;
int tomato_0 = 0;
int tomato_1 = 0;
queue<pair<int, int>> q;

int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	memset(dist, -1, sizeof(dist));
	cin >> M >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> box[i][j];
			if (box[i][j] == 0) 
				tomato_0++;
			if (box[i][j] == 1)
			{
				q.push({ i,j });
				dist[i][j] = 0;
			}
		}
	}
		
	if (tomato_0 == 0)
	{
		MinDay = 0;
	}
	else
	{
		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();
			

			for (int k = 0; k < 4; ++k)
			{
				int nx = cur.X + dx[k];
				int ny = cur.Y + dy[k];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				if (box[nx][ny] == -1 || dist[nx][ny] != -1) continue;

				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				q.push({ nx,ny });
				tomato_1++;

				if (tomato_0 == tomato_1) // complete
				{
					MinDay = min(MinDay, dist[nx][ny]);
					break;
				}
			}
		}

	
		
	}
	
	MinDay = MinDay == INT_MAX ? -1 : MinDay;
	cout << MinDay;
	return 0;
}