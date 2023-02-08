#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int N, M;
vector<int> tree;
//ÀÌºÐÅ½»ö
bool check(int mid)
{
	long long sum =0;
	for (auto& ele : tree)
	{
		if (ele > mid) sum += ele - mid;
	}
	return sum >= M;
}
int main()
{
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	
	cin >> N >> M;
	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		tree.push_back(tmp);
	}
	int lo = 0;
	int hi = 1e9; // 0 9°³ 1,000,000,000
	int mid;
	while (hi - lo > 1)
	{
		mid = (lo + hi) / 2;
		if (check(mid))
		{
			lo = mid;
		}
		else
		{
			hi = mid;
		}
	}
	cout << lo;
}