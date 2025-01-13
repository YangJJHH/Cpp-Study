#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <queue>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int dz[2] = { 1,-1};
#define X first
#define Y second

int M, N, H;
int arr[102][102][102];
bool visit[102][102][102];
int totalTomato;
int Tomato1;
int Tomato0;
int countTomato;
int MaxDay;
int NoneTomato;
bool bAlready;
struct Pos
{
	int x;
	int y;
	int z;
	Pos(int _r, int _c, int _h)
	{
		x = _r;
		y = _c;
		z = _h;
	}
};
bool checkPos(int x, int y, int z)
{
	return (x >= 0 && x < N && y >= 0 && y < M && z >= 0 && z < H&& visit[z][x][y] == false && arr[z][x][y] == 0);
}
int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	cin >> M >> N >> H;
	queue<Pos> q;
	for (int i = 0; i < H; ++i)
		for (int j = 0; j < N; ++j)
			for (int k = 0; k < M; ++k)
			{
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1)
				{
					Tomato1++;
					q.push({ j,k,i });
				}
				if (arr[i][j][k] == 0)
				{
					Tomato0++;
				}
				if (arr[i][j][k] == -1)
				{
					NoneTomato++;
				}
			}
	totalTomato = Tomato0 + Tomato1;
	if (Tomato1 + NoneTomato == H * M * N)
		bAlready = true;

	
	if (!q.empty())
	{
		auto cur = q.front();
		visit[cur.z][cur.x][cur.y] = true;
	}
	
	while (!q.empty() && !bAlready)
	{
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int x = cur.x + dx[i];
			int y = cur.y + dy[i];
			int z = cur.z;

			if(checkPos(x, y, z) == false) continue;
			countTomato++;
			visit[z][x][y] = true;
			arr[z][x][y] = arr[cur.z][cur.x][cur.y] + 1;
			MaxDay = max(arr[z][x][y], MaxDay);
			q.push({ x,y,z });
		}

		for (int i = 0; i < 2; ++i)
		{
			int x = cur.x;
			int y = cur.y;
			int z = cur.z + dz[i];

			if (checkPos(x, y, z) == false) continue;
			countTomato++;
			visit[z][x][y] = true;
			arr[z][x][y] = arr[cur.z][cur.x][cur.y] + 1;
			MaxDay = max(arr[z][x][y], MaxDay);
			q.push({ x,y,z });
		}
	}
	if (bAlready)
		cout << 0;
	else
	{
		if (countTomato == Tomato0)
			cout << MaxDay -1;
		else
			cout << -1;
	}

	return 0;
}