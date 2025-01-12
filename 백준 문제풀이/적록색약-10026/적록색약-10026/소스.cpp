#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <queue>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
using namespace std;
string arr[102]; 
bool visit[102][102];
int N;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
#define X first
#define Y second

void BFS(queue<pair<int, int>>& q, string color)
{
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int k = 0; k < 4; ++k)
		{
			int x = cur.X + dx[k];
			int y = cur.Y + dy[k];

			if (x >= 0 && x < N && y >= 0 && y < N && visit[x][y] == false )
			{
				if (color.length() == 0)
				{
					if (arr[x][y] == color[0])
					{
						visit[x][y] = true;
						q.push({ x,y });
					}
				}
				else
				{
					if (arr[x][y] == color[0] || arr[x][y] == color[1])
					{
						visit[x][y] = true;
						q.push({ x,y });
					}
				}
				
			}
		}
	}
}
int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	int ired,iblue,igreen;
	ired = iblue = igreen = 0;
	queue<pair<int, int>> red;
	queue<pair<int, int>> blue;
	queue<pair<int, int>> green;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if(visit[i][j]) continue;
			char color = arr[i][j];
			switch (color)
			{
			case 'R':
			{
				red.push({ i,j });
				visit[i][j] = true;
				ired++;
			}
			break;
			case 'G':
			{
				green.push({ i,j });
				visit[i][j] = true;
				igreen++;
			}
			break;
			case 'B':
			{
				blue.push({ i,j });
				visit[i][j] = true;
				iblue++;
			}
			break;
			default:
				break;
			}

			BFS(red,"R");
			BFS(green,"G");
			BFS(blue,"B");
		}
	}

	cout << ired + igreen + iblue<< ' ';
	memset(visit, false, sizeof(visit));
	ired = iblue = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (visit[i][j]) continue;
			char color = arr[i][j];
			switch (color)
			{
			case 'R':
			case 'G':
			{
				red.push({ i,j });
				visit[i][j] = true;
				ired++;
			}
			break;
			case 'B':
			{
				blue.push({ i,j });
				visit[i][j] = true;
				iblue++;
			}
			break;
			default:
				break;
			}

			BFS(red, "RG");
			BFS(blue, "B");
		}
	}

	cout << ired + iblue;
	return 0;
}