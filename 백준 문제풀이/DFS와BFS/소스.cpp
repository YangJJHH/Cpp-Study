#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <queue>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
using namespace std;
int N, M, V;
vector<int> output;
void BFS(vector<int> vertex, vector<set<int>>& edge, int v)
{
	queue<int> q;
	q.push(v);
	while (!q.empty() && output.size() != N)
	{
		v = q.front();
		q.pop();
		if (vertex[v]) continue;
		output.push_back(v);
		for (auto& ele : edge[v])
		{

			vertex[v] = 1;
			q.push(ele);

		}
	}

}
void DFS(vector<int> &vertex, vector<set<int>>& edge, int v)
{
	output.push_back(v);
	vertex[v] = 1;
	for (auto& ele : edge[v])
	{
		if (!vertex[ele] && output.size() != N)
		{
			DFS(vertex, edge, ele);
		}
	}
}
void print()
{
	for (auto& ele : output)
	{
		cout << ele << " ";
	}
	cout << "\n";
	output.clear();
}
int main()
{
	fastio;
	freopen("input.txt", "r", stdin);
	cin >> N >> M >> V;
	vector<int> vertex(N + 1);
	vector<set<int>> edge(N + 1, set<int>());
	int start, end;
	for (int i = 0; i < M; i++)
	{
		cin >> start >> end;
		edge[start].insert(end);
		edge[end].insert(start);
	}

	DFS(vertex, edge, V);
	print();
	for (int i = 0; i < vertex.size(); i++)
	{
		vertex[i] = 0;
	}
	BFS(vertex, edge, V);
	print();
	return 0;
}