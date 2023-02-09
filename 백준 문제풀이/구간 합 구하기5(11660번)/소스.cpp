#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <string>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
//DP
using namespace std;
long long sum;
int N, M;
int arr_sum[1024][1024];
int arr[1024][1024];



int main()
{
	fastio;
	freopen("input.txt", "r", stdin);
	cin >> N >> M;
	//누적합 구하기
	for (int i = 0; i < N; i++)
	{
		sum = 0;
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			sum += arr[i][j];
			arr_sum[i][j] = sum;
		}
		for (int j = 0; j < N; j++)
		{
			if (i == 0) continue;
			arr_sum[i][j] += arr_sum[i-1][j];
		}
	}
	int x1, x2, y1, y2;
	
	for (int i = 0; i < M; i++)
	{
		sum = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		int xx = x1 - 1 - 1;
		int yy = y1 - 1 - 1;
		if (xx < 0 && yy < 0)
		{
			sum = arr_sum[x2-1][y2-1];
		}
		else if (xx < 0)
		{
			sum = arr_sum[x2 - 1][y2 - 1]  - arr_sum[x2 - 1][yy];
		}
		else if (yy<0)
		{
			sum = arr_sum[x2 - 1][y2 - 1] - arr_sum[xx][y2 - 1];
		}
		else
		{
			sum = arr_sum[x2 - 1][y2 - 1] - arr_sum[xx][y2 - 1] - arr_sum[x2 - 1][yy] + arr_sum[xx][yy];
		}
		
		cout << sum << "\n";
	}

	return 0;
}