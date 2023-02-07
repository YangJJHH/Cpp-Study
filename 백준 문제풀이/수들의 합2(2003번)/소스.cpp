#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int N, M;
int main()
{
	//투 포인터
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin >> N >> M;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int left =0; // 구간의 왼쪽 포인터
	int right =0; // 먼저 나아갈 구간의 오른쪽 포인터
	int sum = arr[0];
	int cnt = 0;
	while (right < N)
	{
		if (sum < M) //합이 작다면 오른쪽을 한칸 더 움직임
		{
			right++;
			sum += arr[right];
		}
		else if(sum == M)  //합이 같다면 더 이상 왼쪽을 볼 필요가 없기 때문에 왼쪽 한칸 증가
		{
			cnt++;
			sum -= arr[left];
			left++;
		}
		else if(sum>M) //합이 크다면 왼쪽을 한칸 더 움직여 구간을 줄임
		{
			sum -= arr[left];
			left++;
		}
	}
	cout << cnt;
}