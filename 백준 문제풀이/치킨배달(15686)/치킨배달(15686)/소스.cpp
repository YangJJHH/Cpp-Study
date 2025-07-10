#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define FILL(arr,val) fill(begin(arr), end(arr), val);
#define CHECK_CONDITION_CONTINUE(condition) if(condition) continue;
#define CHECK_CONDITION_BREAK(condition) if(condition) break;
#define CHECK_CONDITION_RETURN_VOID(condition) if(condition) return;
using namespace std;

enum eTYPE
{
	NONE	= 0,
	HOUSE	= 1,
	CHICKEN	= 2,
};

struct sPos
{
	int r;
	int c;
	sPos(int _r, int _c) : r(_r), c(_c)
	{}
};

int N, M;
const int MAX_N = 50;
int totalDistance = INT_MAX;
vector<sPos> vecChicken;
vector<sPos> vecHouse;
vector<int> vecDist;
vector<sPos> selected;
int CalcDist(const sPos p1, const sPos p2)
{
	return abs(p1.r - p2.r) + abs(p1.c - p2.c);
}

void Find(int idx, int count)
{
	if (count == M)
	{
		int sum = 0;
		for (auto& h : vecHouse)
		{
			int minDist = INT_MAX;
			for (auto& val : selected)
			{
				minDist = min(CalcDist(val, h), minDist);
			}
			sum += minDist;
		}
		totalDistance = min(sum, totalDistance);
		return;
	}
	for (int i = idx; i < vecChicken.size(); ++i)
	{
		selected.push_back(vecChicken[i]);
		Find(i+1, count+1);
		selected.pop_back();
	}
}

int main()
{
	fastio;
#ifndef BOJ
	freopen("input.txt", "r", stdin);
#endif // _TEST

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int val;
			cin >> val;

			switch (val)
			{
			case HOUSE:		vecHouse.emplace_back(i, j);	break;
			case CHICKEN:	vecChicken.emplace_back(i, j);	break;
			default:
				break;
			}
		}
	}

	Find(0, 0);

	cout << totalDistance;
	return 0;
}