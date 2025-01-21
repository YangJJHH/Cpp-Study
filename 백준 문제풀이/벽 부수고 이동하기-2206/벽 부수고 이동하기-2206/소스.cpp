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
int N, M;
string arr[1000];
int dist[1000][1000][2];
int debg[1000][1000];
int dx[4] = { 0, 1, -1, 0};
int dy[4] = { 1, 0, 0, -1};
struct Data
{
	int x;
	int y;
	bool CanBreak;
	Data(int _x, int _y ,bool b)
	{
		x = _x;
		y = _y;
		CanBreak = b;
	}
};
int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	FILL(dist, -1);
	queue<Data> q;
	q.push({ 0, 0, true });
	dist[0][0][1] = 1;
	int answer = N*M +1;
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		if (cur.x == N - 1 && cur.y == M - 1)
		{
			cout << dist[cur.x][cur.y][cur.CanBreak];
			return 0;
		}
			
		for (int i = 0; i < 4; ++i)
		{
			int X = cur.x + dx[i];
			int Y = cur.y + dy[i];
			if( X < 0 || X >= N || Y < 0 || Y>=M ) continue;
			int distance = dist[X][Y][0];
			if (arr[X][Y] == '1' && distance == -1)
			{
				if (cur.CanBreak)
				{
					dist[X][Y][0] = dist[cur.x][cur.y][cur.CanBreak] + 1;
					debg[X][Y] = dist[X][Y][0];
					q.push({ X,Y,false });
				}
			}
			if (arr[X][Y] == '0' && dist[X][Y][cur.CanBreak] == -1)
			{
				dist[X][Y][cur.CanBreak] = dist[cur.x][cur.y][cur.CanBreak] + 1;
				debg[X][Y] = dist[X][Y][cur.CanBreak];
				q.push({ X,Y,cur.CanBreak });
			}
		}
	}

	cout << -1;


	return 0;
}