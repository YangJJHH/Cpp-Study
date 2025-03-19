#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define FILL(arr,val) fill(begin(arr), end(arr), val);
#define CHECK_CONDITION_CONTINUE(condition) if(condition) continue;
#define CHECK_CONDITION_BREAK(condition) if(condition) break;
#define CHECK_CONDITION_RETURN_VOID(condition) if(condition) return;
using namespace std;
int N;
const int MAX = 23;
int arr[MAX][MAX];
int backup[MAX][MAX];
int curstate[MAX][MAX];
vector<vector<int>> movecase;

enum
{
	UP =0,
	DOWN,
	LEFT,
	RIGHT,
};

void GetCase()
{
	movecase.reserve(1024);
	for (int i = 0; i < 1024; ++i)
	{
		int temp = i;
		vector<int> vec;
		for (int j = 0; j < 5; ++j)
		{
			int val = temp % 4;
			vec.push_back(val);
		}
		movecase.emplace_back(vec);
	}
}

void Up()
{
	bool isCheck[MAX][MAX];
	memset(isCheck, 0, sizeof(isCheck));

	for (int c = 0; c < N; ++c)
	{
		for (int r = 1; r < N; ++r)
		{
			CHECK_CONDITION_CONTINUE(curstate[r][c] == 0);

			int tmp = r;
			while (tmp)
			{
				int next = tmp - 1;
				
				if (curstate[next][c] == 0)
				{
					curstate[next][c] = curstate[tmp][c];
					curstate[tmp][c] = 0;

					isCheck[next][c] = isCheck[tmp][c];
					isCheck[tmp][c] = false;
				}
				else
				{
					if ((curstate[next][c] == curstate[tmp][c]) && !isCheck[next][c] && !isCheck[tmp][c])
					{
						curstate[next][c] = curstate[next][c] * 2;
						curstate[tmp][c] = 0;

						isCheck[next][c] = true;
						curstate[tmp][c] = false;
					}
					else
						break;
				}

				--tmp;
			}
		}
	}
}
void Down()
{
	bool isCheck[MAX][MAX];
	memset(isCheck, 0, sizeof(isCheck));

	for (int c = 0; c < N; ++c)
	{
		for (int r = N-2; r >= 0; --r)
		{
			CHECK_CONDITION_CONTINUE(curstate[r][c] == 0);

			int tmp = r;
			while (tmp < N - 1)
			{
				int next = tmp + 1;

				if (curstate[next][c] == 0)
				{
					curstate[next][c] = curstate[tmp][c];
					curstate[tmp][c] = 0;

					isCheck[next][c] = isCheck[tmp][c];
					isCheck[tmp][c] = false;
				}
				else
				{
					if ((curstate[next][c] == curstate[tmp][c]) && !isCheck[next][c] && !isCheck[tmp][c])
					{
						curstate[next][c] = curstate[next][c] * 2;
						curstate[tmp][c] = 0;

						isCheck[next][c] = true;
						curstate[tmp][c] = false;
					}
				}

				++tmp;
			}
		}
	}
}
void Left()
{
	bool isCheck[MAX][MAX];
	memset(isCheck, 0, sizeof(isCheck));

	for (int r = 0; r < N; ++r)
	{
		for (int c = 1; c < N; ++c)
		{
			CHECK_CONDITION_CONTINUE(curstate[r][c] == 0);

			int tmp = c;
			while (tmp)
			{
				int next = tmp - 1;

				if (curstate[r][next] == 0)
				{
					curstate[r][next] = curstate[r][tmp];
					curstate[r][tmp] = 0;

					isCheck[r][next] = isCheck[r][tmp];
					isCheck[r][tmp] = false;
				}
				else
				{
					if ((curstate[r][next] == curstate[r][tmp]) && !isCheck[r][next] && !isCheck[r][tmp])
					{
						curstate[r][next] = curstate[r][next] * 2;
						curstate[r][tmp] = 0;

						isCheck[r][next] = true;
						isCheck[r][tmp] = false;
					}
				}

				--tmp;
			}
		}
	}
}
void Right()
{
	bool isCheck[MAX][MAX];
	memset(isCheck, 0, sizeof(isCheck));

	for (int r = 0; r < N; ++r)
	{
		for (int c = N-2; c >= 0; --c)
		{
			CHECK_CONDITION_CONTINUE(curstate[r][c] == 0);

			int tmp = c;
			while (tmp < N-1)
			{
				int next = tmp + 1;

				if (curstate[r][next] == 0)
				{
					curstate[r][next] = curstate[r][tmp];
					curstate[r][tmp] = 0;

					isCheck[r][next] = isCheck[r][tmp];
					isCheck[r][tmp] = false;
				}
				else
				{
					if ((curstate[r][next] == curstate[r][tmp]) && !isCheck[r][next] && !isCheck[r][tmp] )
					{
						curstate[r][next] = curstate[r][next] * 2;
						curstate[r][tmp] = 0;

						isCheck[r][next] = true;
						isCheck[r][tmp] = false;
					}
				}

				++tmp;
			}
		}
	}
}

void Move(int dir)
{
	switch (dir)
	{
	case UP: Up();			break;
	case DOWN: Down();		break;
	case LEFT: Left();		break;
	case RIGHT: Right();	break;
	}
}

void Solve()
{
	int max_value = 0;
	for (const auto& game : movecase)
	{
		memcpy(curstate, arr, sizeof(arr));
		for (const auto& dir : game)
		{
			Move(dir);
		}

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				max_value = max(max_value, curstate[i][j]);
			}
		}
	}

	cout << max_value;
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
		for (int j = 0; j < N; ++j)
		{
			cin >> arr[i][j];
		}
	}

	GetCase();
	Solve();
	return 0;
}