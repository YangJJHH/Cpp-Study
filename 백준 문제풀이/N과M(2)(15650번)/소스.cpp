#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
using namespace std;
int N, M;
vector<int> visited;
vector<int> arr;

void DFS(int idx)
{
	if (arr.size() == M)
	{
		for (auto& ele : arr)
		{
			cout << ele << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = idx; i < N + 1; i++)
	{
		if (!visited[i])
		{
			arr.push_back(i);
			visited[i] = 1;
			DFS(i+1);
			visited[i] = 0;
			arr.pop_back();
		}
	}
}
int main()
{
	fastio;
	freopen("input.txt", "r", stdin);
	cin >> N >> M;
	visited.resize(N+1,0);
	DFS(1);
	return 0;


}