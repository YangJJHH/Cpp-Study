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
using namespace std;
int arr[302][302];
int M, N;
queue<pair<int,int>> q;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool check(queue<pair<int, int>>& q)
{
	if (q.empty()) return false;

	int size = q.size();
	auto cur = q.front();
	bool visit[302][302];
	FILL(visit, false);

	queue<pair<int, int>> tmp;
	tmp.push(cur);
	int Sum = 1;
	visit[cur.first][cur.second] = true;
	while (!tmp.empty())
	{
		cur = tmp.front();
		tmp.pop();
		
		for (int i = 0; i < 4; ++i)
		{
			int x = dx[i] + cur.first;
			int y = dy[i] + cur.second;

			if( x < 0 || x >= M || y < 0 || y>=N) continue;
			if(visit[x][y]) continue;
			if(arr[x][y] <= 0) continue;

			visit[x][y] = true;
			Sum++;
			tmp.push({ x,y });
		}

	}

	return Sum == size;
}
int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	cin >> M >> N;
	int year = 0;

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> arr[i][j];
			if (arr[i][j])
				q.push({ i,j });
		}
	}
	int sum = 0;
	while (check(q))
	{
		sum++;
		bool visit[302][302];
		FILL(visit, false);

		queue<pair<int, int>> next;
		auto cur = q.front();

		queue<pair<int, int>> cal;
		cal.push(cur);
		visit[cur.first][cur.second] = true;
		while (!cal.empty())
		{
			cur = cal.front();
			cal.pop();

			for (int i = 0; i < 4; ++i)
			{
				int x = dx[i] + cur.first;
				int y = dy[i] + cur.second;

				if (x < 0 || x >= M || y < 0 || y >= N) continue;
				if (visit[x][y]) continue;
				if (arr[x][y] <= 0)
				{
					arr[cur.first][cur.second]--;
					continue;
				}
					

				visit[x][y] = true;
				cal.push({ x,y });
			}
			if (arr[cur.first][cur.second] > 0)
				next.push(cur);

		}

		q = next;
		if (q.empty())
			sum = 0;
	}
	cout << sum;

	return 0;
}