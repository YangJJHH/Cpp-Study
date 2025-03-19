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
int N, M, K;
const int MAX = 42;
int notebook[MAX][MAX];
struct sticker
{
	int r;
	int c;

	int rect[12][12];
};
vector<sticker> vecsticker;

void Rotate(sticker& s)
{
	sticker rotateSticker;
	rotateSticker.r = s.c;
	rotateSticker.c = s.r;

	for (int i = 0; i < s.r; ++i)
	{
		for (int j = 0; j < s.c; ++j)
		{
			rotateSticker.rect[j][s.r-i-1] = s.rect[i][j];
		}
	}

	s = rotateSticker;
}

bool SetPosition(sticker& s)
{
	int start_r;
	int start_c;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			CHECK_CONDITION_CONTINUE(i + s.r > N);
			CHECK_CONDITION_CONTINUE(j + s.c > M);

			start_r = i;
			start_c = j;

			bool bFail = false;
			for (int x = 0; x < s.r; ++x)
			{
				for (int y = 0; y < s.c; ++y)
				{
					if (s.rect[x][y] == 1 && notebook[i + x][j + y] == 1)
					{
						bFail = true;
						break;
					}
				}
				CHECK_CONDITION_BREAK(bFail);
			}

			if (bFail == false)
			{
				for (int x = 0; x < s.r; ++x)
				{
					for (int y = 0; y < s.c; ++y)
					{
						if(s.rect[x][y])
							notebook[start_r + x][start_c + y] = 1;
					}
				}

				return true;
			}
		}
	}

	return false;
}

void Solve()
{
	for (auto& st : vecsticker)
	{
		CHECK_CONDITION_CONTINUE(SetPosition(st));

		for (int i = 0; i < 3; ++i)
		{
			Rotate(st);
			CHECK_CONDITION_BREAK(SetPosition(st));
		}
	}

	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (notebook[i][j])
				++sum;
		}
	}

	cout << sum;
}


int main()
{
	fastio;
#ifndef BOJ
	freopen("input.txt", "r", stdin);
#endif // _TEST
	cin >> N >> M >> K;
	for (int i = 0; i < K; ++i)
	{
		sticker s;
		cin >> s.r >> s.c;

		for (int j = 0; j < s.r; ++j)
		{
			for (int k = 0; k < s.c; ++k)
			{
				cin >> s.rect[j][k];
			}
		}
		vecsticker.emplace_back(s);
	}

	Solve();
	return 0;
}