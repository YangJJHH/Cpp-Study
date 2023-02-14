#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#define fastio cin.tie(NULL)->sync_with_stdio(false);

using namespace std;
int N, M;
vector<int> arr;
vector<int> visited;
void print()
{
	for (auto& ele : arr)
	{
		cout << ele << " ";
	}
	cout << "\n";
}
void findArr()
{
	if (arr.size() == M)
	{
		print();
		return;
	}
	
	for (int i = 1; i < N+1; i++)
	{
		if (!visited[i])
		{
			arr.push_back(i);
			visited[i] = 1;
			findArr();
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
	arr.reserve(M);

	

	findArr();
	return 0;
}