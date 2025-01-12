#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <queue>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define X first
#define Y second
using namespace std;
int T;
int arr[52][52];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST

	cin >> T;
	int m, n, k;
	int answer;
	while (T--)
	{
		answer = 0;
		queue<pair<int,int>> q;
		cin >> m >> n >> k;
		memset(arr, 0x00, sizeof(arr));
		for (int i = 0; i < k; ++i)
		{
			int row, col;
			cin >> row >> col;

			arr[row][col] = 1;
		}

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (arr[i][j] == 1)
				{
					answer++;
					q.push({ i,j });

					auto ele = q.front();
					arr[i][j] = -1;

					while (!q.empty())
					{
						ele = q.front();
						q.pop();

						for (int i = 0; i < 4; i++)
						{
							int x = ele.X + dx[i];
							int y = ele.Y + dy[i];

							if (x >= 0 && x < m && y >= 0 && y < n && arr[x][y] == 1)
							{
								arr[x][y] = -1;
								q.push({ x,y });
							}
						}
					}
				}
			}
		}

		cout << answer << '\n';
	}
	return 0;
}