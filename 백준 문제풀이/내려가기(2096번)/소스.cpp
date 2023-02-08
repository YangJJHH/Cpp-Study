#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
//다이나믹 프로그래밍 DP
//메모리가 4MB 제한이기 때문에 주의
//풀이 원리
//현재 칸에 있는 값과 위에서 올 수 있는 경우의 값들중 큰것 을 더해서 현재칸에 저장, 최소값은 반대로
using namespace std;
int N;
int main()
{
	fastio;
	freopen("input.txt","r",stdin);
	cin >> N;
	int max_dp[3] = { 0 }; //최대 점수 기록
	int min_dp[3] = { 0 }; //최소 점수 기록
	int arr[3] = { 0 }; //위에 칸에 있는 값 나타냄
	int pre[3] = { 0 }; //위에 칸에 있는 값 나타냄

	for (int i = 0; i < N; i++)
	{
		cin >> arr[0] >> arr[1] >> arr[2]; //현재칸
		
		//위에 칸 저장
		pre[0] = max_dp[0];
		pre[1] = max_dp[1];
		pre[2] = max_dp[2];
		//위에 칸중 최대값 비교 후 현재칸의 값과 더해서 현재칸에 저장
		max_dp[0] = max(pre[0],pre[1]) + arr[0];
		max_dp[2] = max(pre[1], pre[2]) + arr[2];
		max_dp[1] = max(max(pre[0], pre[1]),pre[2]) + arr[1];

		//위에 칸 저장
		pre[0] = min_dp[0];
		pre[1] = min_dp[1];
		pre[2] = min_dp[2];
		//위에 칸중 최소값 비교 후 현재칸의 값과 더해서 현재칸에 저장
		min_dp[0] = min(pre[0], pre[1]) + arr[0];
		min_dp[2] = min(pre[1], pre[2]) + arr[2];
		min_dp[1] = min(min(pre[0], pre[1]), pre[2]) + arr[1];
	}
	cout << max(max(max_dp[0], max_dp[1]), max_dp[2]) << " " << min(min(min_dp[0], min_dp[1]), min_dp[2]);
	return 0;
}