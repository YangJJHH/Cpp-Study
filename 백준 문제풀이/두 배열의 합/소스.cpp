#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define fastio cin.tie(NULL)->sync_with_stdio(false);

using namespace std;
long long sum;
int N, T, M;
long long rst = 0;
// 풀이방법
// 갯수는 1000개,시간은 2초 제한이기 때문에 O(n^2) 이여도 충분함
// 따라서 부분합을 모두 구해주고 T에서 한 부분합을 뺀 값이 다른 부분합에 몇개 있는지 찾아내는 방법
// lower_bound(시작,끝 ,목표값) : 목표값보다 크거나 같은 원소중 제일 처음 나오는것
// upper_bound(시작,끝 ,목표값) : 목표값보다 큰 원소중 제일 처음 나오는것
// 즉 lower_bound() - upper_bound() 하면 만족하는 부분합이 몇개 있는지 알 수 있음

//직접구현
int Lower(const vector<long long>& v,long long target)
{
	int start = -1;
	int end = v.size();
	int mid ;
	//이분탐색
	while (end - start > 1)
	{
		mid = (start + end) / 2;
		if (v[mid] >= target)
		{
			end = mid;
		}
		else if (v[mid] < target)
		{
			start = mid;
		}
	}
	return end;
}
int Upper(const vector<long long>& v, long long target)
{
	int start = -1;
	int end = v.size();
	int mid;
	//이분탐색
	while (end - start > 1)
	{
		mid = (start + end) / 2;
		if (v[mid] > target)
		{
			end = mid;
		}
		else if (v[mid] <= target)
		{
			start = mid;
		}
	}
	return end;
}
int main()
{
	fastio;
	freopen("input.txt", "r", stdin);
	cin >> T >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	cin >> M;
	vector<int> b(M);
	for (int i = 0; i < M; i++)
	{
		cin >> b[i];
	}

	vector<long long> v, v2;
	for (int i = 0; i < N; i++)
	{
		sum = a[i];
		v.push_back(sum);
		for (int j = i+1; j < N; j++)
		{
			sum += a[j];
			v.push_back(sum);
		}
	}

	for (int i = 0; i < M; i++)
	{
		sum = b[i];
		v2.push_back(sum);
		for (int j = i + 1; j < M; j++)
		{
			sum += b[j];
			v2.push_back(sum);
		}
	}
	sort(v2.begin(),v2.end());
	for (auto& ele : v)
	{
		//auto a = lower_bound(v2.begin(), v2.end(), T - ele) - v2.begin();
		//auto b = upper_bound(v2.begin(), v2.end(), T - ele) - v2.begin();
		auto a = Lower(v2, T - ele);
		auto b = Upper(v2, T - ele);
		rst += b - a;
	}
	

	cout << rst;
	return 0;
}