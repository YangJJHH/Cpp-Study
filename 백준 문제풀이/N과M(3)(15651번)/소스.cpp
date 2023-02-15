#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define fastio cin.tie(NULL)->sync_with_stdio(false);

using namespace std;
int N, M;
int arr[8];

void DFS(int depth)
{
	if (depth == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i < N + 1; i++)
	{
		arr[depth] = i;
		DFS(depth + 1);
	}
}
int main()
{
	fastio;
	freopen("input.txt", "r", stdin);
	cin >> N >> M;
	DFS(0);
	return 0;
}