#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define MX 100001
#define X first
#define Y second
using namespace std;
int dx[2] = { 1,-1 };

int dist[MX];
int N, K;
int answer;
queue<int> q;

int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	cin >> N >> K;
	memset(dist, -1, sizeof(dist));

	dist[N] = 0;
	q.push(N);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == K)
		{
			answer = dist[cur];
			break;
		}
		
		for (int i = 0; i < 3; ++i)
		{
			int nx;
			if (i == 2)
				nx = cur * 2;
			else
				nx = dx[i] + cur;

			if( nx < 0 || nx > MX) continue;
			if(dist[nx] != -1) continue;

			dist[nx] = dist[cur] + 1;
			q.push(nx);
		}

	}
	cout << answer;
	return 0;
}