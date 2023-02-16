#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#define fastio cin.tie(NULL)->sync_with_stdio(false);

using namespace std;
int N, M;
int arr[9] = {0,};
void DFS(int depth, int start)
{
	if (depth == M)
	{
		for (int i=0; i<M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = start; i <= N; i++)
	{
		arr[depth] = i;
		DFS(depth+1,i);
	}
}
int main()
{
	fastio;
	freopen("input.txt", "r", stdin);
	cin >> N >> M;
	DFS(0, 1);
	return 0;
}