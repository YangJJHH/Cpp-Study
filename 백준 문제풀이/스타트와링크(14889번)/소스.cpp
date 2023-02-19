#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
using namespace std;
int N;
int team_size;
int arr[20][20]{ 0 };
int visit[20]{ 0 };
vector<int> start;
int rst = 40000;
void DFS(int idx)
{
	if (start.size() == team_size)
	{
		int start_sum=0;
		int link_sum = 0;
		for (int i = 0; i < N; i++)
		{
			if (visit[i])
			{
				for (int j = 0; j < N; j++)
				{
					if (i == j) continue;
					if (visit[j])
					{
						start_sum += arr[i][j];
					}
				}
			}
			else
			{
				for (int j = 0; j < N; j++)
				{
					if (i == j) continue;
					if (!visit[j])
					{
						link_sum += arr[i][j];
					}
				}
			}
			
		}
		rst = min(abs(start_sum - link_sum), rst);
		return;
	}
	for (int i = idx; i < N; i++)
	{
		if (!visit[i])
		{
			visit[i] = 1;
			start.push_back(i);
			DFS(i+1);
			visit[i] = 0;
			start.pop_back();
		}
	}
	
}
int main()
{
	fastio;
	freopen("input.txt", "r", stdin);
	cin >> N;
	team_size = N/ 2;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	DFS(0);
	cout << rst;
	return 0;
}