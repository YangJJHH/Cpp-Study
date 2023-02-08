#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
// 투 포인터
using namespace std;

int N, S,LENGTH = 1e5;

int main()
{
	fastio;
	freopen("input.txt","r",stdin);
	cin >> N >> S;
	vector<int> arr(N);
	for (auto& ele : arr)
	{
		cin >> ele;
	}

	int left = 0;
	int right = 0;
	int sum = arr[0];
	int flag = 0;
	while (right<N)
	{
		if (sum < S)
		{
			right++;
			if (right >= N) break;
			sum += arr[right];
		}
		else
		{
			flag = 1;
			LENGTH = min((right-left +1),LENGTH);
			sum -= arr[left];
			left++;
		}
	}
	cout << (flag ? LENGTH : 0);
}