#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
using namespace std;
int N;
int DP[1000002] = { 0,0,1,1 };
void Solve()
{
	int count = 0;
	int a, b, c;
	for (int i = 4; i <= N; i++)
	{
		if ((i % 2 == 0) || (i % 3 == 0))
		{
			if ((i % 2 == 0))
			{
				if ((i % 3 == 0))
				{
					DP[i] = min(DP[i-1]+1, min(DP[i / 2] + 1, DP[i / 3] + 1));

				}
				else
				{
					DP[i] = min(DP[i - 1] + 1, DP[i / 2] + 1);
				}
			}
			else
			{
				DP[i] = min(DP[i - 1] + 1, DP[i / 3] + 1);
			}
		}
		else
		{
			DP[i] = DP[i - 1] + 1;
		}
	}
	cout << DP[N];
}
int main()
{
	fastio;
	cin >> N;
	Solve();

}