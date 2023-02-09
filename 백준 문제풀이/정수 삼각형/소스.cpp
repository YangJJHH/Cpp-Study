#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <string>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
//DP
//풀이방법
//현재칸의 값고 아래로 갈 수있는 칸의 값을 더한후 저장하며 내려감
//맨 마지막 줄에는 각 경우에서 가장 큰값들로 더해진 합들이 나오게 됨
using namespace std;
int arr[500][500]{0}; // 원본 배열
int tri[500][500]{0}; //진행하면서 더할 합들의 저장
int N;
int max_sum =0;
void move()
{
	for (int i = 0; i < N-1; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			tri[i + 1][j] = max(tri[i+1][j],tri[i][j]+arr[i+1][j]); //아래의 있는 칸과 더해서 tri에 있는 값과 비교하여 큰값 저장
			tri[i + 1][j+1] = max(tri[i + 1][j+1], tri[i][j] + arr[i + 1][j+1]); //대각선으로
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
		for (int j = 0; j <= i; j++)
		{
			cin >> arr[i][j];
		}
	}
	tri[0][0] = arr[0][0];
	move();
	for (int i=0; i<N; i++)
	{
		max_sum = max(max_sum,tri[N-1][i]);
	}
	cout << max_sum;
	return 0;
}