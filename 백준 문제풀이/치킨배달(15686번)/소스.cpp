#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//백트레킹
using namespace std;
int N, M;
int rst = 2500;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector< pair<int, int>> selected;
void Find(int start, int n)
{
	if (n == M)
	{
		int min_distnace;
		int sum = 0;
		//거리 계산
		for (auto& ele : house)
		{
			min_distnace = 2500;
			for (auto& ele2 : selected)
			{
				int d1 = abs(ele.first - ele2.first);
				int d2 = abs(ele.second - ele2.second);
				if ((d1 + d2) < min_distnace) min_distnace = d1 + d2;
			}
			sum += min_distnace;
		}
		rst = min(rst,sum);
		return;
	}
	for (int i = start; i < chicken.size(); i++)
	{
		selected.emplace_back(chicken[i]);
		Find(i+1,n+1); // i + 1 로 시작점 바꾸어 주지 않으면 시간초과남
		selected.pop_back();
	}
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
		for (int j = 0; j < N; j++)
		{
			cin >> tmp;
			if (tmp == 1) house.emplace_back(i+1,j+1);
			if (tmp == 2) chicken.emplace_back(i+1, j+1);
		}
	}
	Find(0,0);
	cout << rst;
	return 0;
}