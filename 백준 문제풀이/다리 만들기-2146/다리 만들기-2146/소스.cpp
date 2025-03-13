#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define FILL(arr,val) memset(arr, val, sizeof(arr));
#define CHECK_CONDITION_CONTINUE(condition) if(condition) continue;
#define CHECK_CONDITION_BREAK(condition) if(condition) break;
using namespace std;

int N;
int arr[102][102];
bool visit[102][102];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
struct SInfo
{
	int x;
	int y;
	int region;
	int dist;

	SInfo(int _x, int _y, int _region, int _dist)
		: x(_x), y(_y), region(_region), dist(_dist)
	{ }
};
int main()
{
	fastio;
#ifndef BOJ
	freopen("input.txt", "r", stdin);
#endif
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> arr[i][j];
		}
	}

	int region = 2;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			CHECK_CONDITION_CONTINUE(arr[i][j] != 1);
			arr[i][j] = region;
			queue<SInfo> q;
			q.push({ i,j,region++,0 });
			visit[i][j] = true;

 			while (!q.empty())
			{
				auto cur = q.front();
				q.pop();

				for (int k = 0; k < 4; ++k)
				{
					int x = dx[k] + cur.x;
					int y = dy[k] + cur.y;
					CHECK_CONDITION_CONTINUE( x < 0 || x >=N || y < 0 || y >= N);
					CHECK_CONDITION_CONTINUE(visit[x][y]);
					CHECK_CONDITION_CONTINUE(arr[x][y] != 1);

					arr[x][y] = cur.region;
					visit[x][y] = true;
					q.push({ x,y,cur.region,0 });
				}
			}

		}
	}
	int MinDist = 300;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			CHECK_CONDITION_CONTINUE(arr[i][j] == 0);
			FILL(visit, false);
			queue<SInfo> q;
			q.push({ i,j,arr[i][j],0});
			visit[i][j] = true;

			bool FindRegion = false;
			while (!q.empty() && !FindRegion)
			{
				auto cur = q.front();
				q.pop();

				for (int k = 0; k < 4; ++k)
				{
					int x = dx[k] + cur.x;
					int y = dy[k] + cur.y;
					CHECK_CONDITION_CONTINUE(x < 0 || x >= N || y < 0 || y >= N);
					CHECK_CONDITION_CONTINUE(visit[x][y]);
					CHECK_CONDITION_CONTINUE(arr[x][y] == cur.region);

					if (arr[x][y]!= 0 && arr[x][y] != cur.region)
					{
						MinDist = min(cur.dist, MinDist);
						FindRegion = true;
						break;
					}
					else
					{
						visit[x][y] = true;
						q.push({ x,y,cur.region, cur.dist+1 });
					}

				}
			}

		}
	}
	cout << MinDist;
	return 0;
} 