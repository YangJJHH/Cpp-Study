#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <vector>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define FILL(arr,val) fill(begin(arr), end(arr), val);
#define CHECK_CONDITION_CONTINUE(condition) if(condition) continue;
#define CHECK_CONDITION_BREAK(condition) if(condition) break;
#define CHECK_CONDITION_RETURN_VOID(condition) if(condition) return;
using namespace std;
int N;
int image[70][70];

bool Check(int n, int r, int c)
{
	int start = image[r][c];
	for (int i = r; i < r + n; ++i)
	{
		for (int j = c; j < c + n; ++j)
		{
			if (start != image[i][j]) return false;
		}
	}
	return true;
}

void solve(int n, int r, int c)
{
	if (Check(n, r, c))
	{
		cout << image[r][c];
	}
	else
	{
		cout << "(";
		if (n == 2)
		{
			for (int i = r; i < 2+r; ++i)
			{
				for (int j = c; j < 2+c; ++j)
				{
					cout << image[i][j];
				}
			}
		}
		else
		{
			int nextN = n / 2;
			for (int i = 0; i < 2; ++i)
			{
				for (int j = 0; j < 2; ++j)
				{
					int nextR = r + i * nextN;
					int nextC = c + j * nextN;

					solve(nextN, nextR, nextC);

				}
			}
		}



		cout << ")";
	}


}
int main()
{
	fastio;
#ifndef BOJ
	freopen("input.txt", "r", stdin);
#endif // _TEST

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); ++j)
		{
			image[i][j] = str[j]-'0';
		}
	}


	solve(N, 0, 0);
	return 0;
}