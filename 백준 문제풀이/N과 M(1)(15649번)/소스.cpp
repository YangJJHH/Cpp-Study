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
void findArr(int idx)
{
	if (arr.size() == M)
	{
		print();
		return;
	}
	
	for (int i = 0; i < N+1; i++)
	{
		if (!visited[i])
		{
			arr.push_back(idx);
			visited[idx] = 1;
			findArr(i);
			visited[idx] = 0;
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

	

	findArr(1);
	return 0;
}