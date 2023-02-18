#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#define fastio cin.tie(NULL)->sync_with_stdio(false);

using namespace std;
int N;
int operators[4]{ 0 };
int arr[11];
int sum = 0;
int min_rst = 10e9;
int max_rst = -10e9;
void DFS(int idx)
{
	if (idx == N-1)
	{
		min_rst = min(arr[idx], min_rst);
		max_rst = max(arr[idx], max_rst);
		return;
	}
	for (int i=0; i<4; i++)
	{
		int tmp =0;
		if (operators[i])
		{
			operators[i]--;
			tmp = arr[idx + 1];
			switch (i)
			{
			case 0:
				arr[idx+1] = arr[idx] + arr[idx + 1];
				break;
			case 1:
				arr[idx + 1] = arr[idx] - arr[idx + 1];
				break;
			case 2:
				arr[idx + 1] = arr[idx] * arr[idx + 1];
				break;
			case 3:
				if (arr[idx] < 0)
				{
					arr[idx + 1] = (-1*arr[idx]) / arr[idx + 1] * -1;
				}
				else 
				{
					arr[idx + 1] = int(arr[idx] / arr[idx + 1]);
				}
				break;
			
			}
			DFS(idx+1);
			arr[idx + 1] = tmp;
			operators[i]++;
		}
	}
}
int main()
{
	fastio;
	freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> operators[i];
	}
	DFS(0);
	cout << max_rst << "\n";
	cout << min_rst << "\n";
	return 0;
}