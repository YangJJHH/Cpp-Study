#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
using namespace std;
int N;
int main()
{
	fastio;
	freopen("input.txt", "r", stdin);
	cin >> N;
	int R, G, B;
	vector<vector<int>> arr(N + 1, vector<int>(3));
	for (int i = 1; i <= N; i++)
	{
		cin >> R >> G >> B;
		arr[i][0] = min(arr[i - 1][1], arr[i - 1][2]) + R;
		arr[i][1] = min(arr[i - 1][0], arr[i - 1][2]) + G;
		arr[i][2] = min(arr[i - 1][0], arr[i - 1][1]) + B;
	}
	cout << min(min(arr[N][0], arr[N][1]), arr[N][2]);
	return 0;
}