#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#define fastio cin.tie(NULL)->sync_with_stdio(false);

using namespace std;
int N,M;
vector<int> arr;
int answer[8]{ 0 };
int visited[8]{ 0 };
void DFS(int cnt)
{
	if (cnt == M)
	{
		for(int i=0; i<M; i++)
		{
			cout << answer[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (!visited[i])
		{
			answer[cnt] = arr[i];
			visited[i] = 1;
			DFS(cnt + 1);
			visited[i] = 0;
		}
		
	}
}
int main()
{
	fastio;
	freopen("input.txt", "r", stdin);
	cin >> N >> M;
	int  t;
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		arr.push_back(t);
	}
	sort(arr.begin(), arr.end());
	DFS(0);
	return 0;
}