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
enum
{
	EMPTY = 0,
	CCTV_1 = 1,
	CCTV_2 = 2,
	CCTV_3 = 3,
	CCTV_4 = 4,
	CCTV_5 = 5,
	WALL = 6,
};

struct SCCTV
{
	int x;
	int y;
	unsigned char type;

	SCCTV(int _x, int _y, unsigned char t)
		: x(_x), y(_y), type(t)
	{

	}
};

int N, M;
const int MAX = 9;
int empty_count = MAX * MAX;
int room[MAX][MAX];
int tempRoom[MAX][MAX];
vector<SCCTV> vecCCTV;
int cctv_cnt;
vector<vector<int>> dir;
void SetDir()
{
	const int NUMBERS = 4;  // 0~3
	const int LENGTH = 8;   // 뽑을 개수

	// 총 경우의 수: 4^8 = 65536
	long long total_cases = 1;
	for (int i = 0; i < cctv_cnt; i++) {
		total_cases *= NUMBERS;
	}

	//std::cout << "Total cases: " << total_cases << std::endl;
	dir.reserve(total_cases);

	// 모든 경우의 수 생성
	for (long long i = 0; i < total_cases; i++) {
		std::vector<int> combination;
		long long temp = i;

		// 4진법 형태로 변환하여 조합 생성
		for (int j = 0; j < cctv_cnt; j++) {
			combination.push_back(temp % NUMBERS); // 0~3의 숫자 선택
			temp /= NUMBERS;
		}

		dir.emplace_back(combination);
		//// 출력
		//for (int j = cctv_cnt - 1; j >= 0; j--) { // 거꾸로 출력
		//	std::cout << combination[j] << " ";
		//}
		//std::cout << std::endl;
	}
}

void Right(SCCTV& cctv)
{
	for (int i = cctv.y; i < M; ++i)
	{
		CHECK_CONDITION_BREAK(tempRoom[cctv.x][i] == WALL);
		tempRoom[cctv.x][i] = cctv.type;
	}
}

void Down(SCCTV& cctv)
{
	for (int i = cctv.x; i < N; ++i)
	{
		CHECK_CONDITION_BREAK(tempRoom[i][cctv.y] == WALL);
		tempRoom[i][cctv.y] = cctv.type;
	}
}

void Left(SCCTV& cctv)
{
	for (int i = cctv.y; i >= 0; --i)
	{
		CHECK_CONDITION_BREAK(tempRoom[cctv.x][i] == WALL);
		tempRoom[cctv.x][i] = cctv.type;
	}
}

void Up(SCCTV& cctv)
{
	for (int i = cctv.x; i >= 0; --i)
	{
		CHECK_CONDITION_BREAK(tempRoom[i][cctv.y] == WALL);
		tempRoom[i][cctv.y] = cctv.type;
	}
}

void Rotate_CCTV1(SCCTV& cctv, int dir)
{
	switch (dir)
	{
	case 0: Right(cctv); break;
	case 1:	Down(cctv); break;
	case 2:	Left(cctv); break;
	case 3: Up(cctv); break;
	default:
		break;
	}
}

void Rotate_CCTV2(SCCTV& cctv, int dir)
{
	switch (dir)
	{
	case 0:
	case 2:
	{
		Left(cctv);
		Right(cctv);
	}
	break;
	case 1:
	case 3:
	{
		Up(cctv);
		Down(cctv);
	}
	break;
	default:
		break;
	}
}

void Rotate_CCTV3(SCCTV& cctv, int dir)
{
	switch (dir)
	{
	case 0:
	{
		Up(cctv);
		Right(cctv);
	}
	break;
	case 1:
	{
		Down(cctv);
		Right(cctv);
	}
	break;
	case 2:
	{
		Down(cctv);
		Left(cctv);
	}
	break;
	case 3:
	{
		Up(cctv);
		Left(cctv);
	}
	break;
	default:
		break;
	}
}

void Rotate_CCTV4(SCCTV& cctv, int dir)
{
	switch (dir)
	{
	case 0:
	{
		Right(cctv);
		Up(cctv);
		Left(cctv);
	}
	break;
	case 1:
	{
		Right(cctv);
		Up(cctv);
		Down(cctv);
	}
	break;
	case 2:
	{
		Right(cctv);
		Down(cctv);
		Left(cctv);
	}
	break;
	case 3:
	{
		Up(cctv);
		Down(cctv);
		Left(cctv);
	}
	break;
	default:
		break;
	}
}

void Rotate_CCTV5(SCCTV& cctv, int dir)
{
	switch (dir)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	{
		Up(cctv);
		Down(cctv);
		Left(cctv);
		Right(cctv);
	}
	break;
	default:
		break;
	}
}
void Rotate(SCCTV &cctv,int dir)
{
	switch (cctv.type)
	{
	case CCTV_1: Rotate_CCTV1(cctv, dir); break;
	case CCTV_2: Rotate_CCTV2(cctv, dir); break;
	case CCTV_3: Rotate_CCTV3(cctv, dir); break;
	case CCTV_4: Rotate_CCTV4(cctv, dir); break;
	case CCTV_5: Rotate_CCTV5(cctv, dir); break;
	}
}

void Count()
{
	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if(tempRoom[i][j] == EMPTY)
				++sum;
		}
	}

	empty_count = min(empty_count, sum);
}


void Solve()
{
	for (const auto &dircase : dir)
	{
		memcpy(tempRoom, room, sizeof(room));
		for (int i = 0; i < cctv_cnt; ++i)
		{
			auto &curCCTV = vecCCTV[i];
			int curDir = dircase[i];
			
			Rotate(curCCTV, curDir);
		}
		Count();
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
		for (int j = 0; j < M; ++j)
		{
			cin >> room[i][j];
			if (EMPTY < room[i][j] && room[i][j] < WALL)
			{
				vecCCTV.emplace_back(i, j, room[i][j]);
			}
		}
	}
	cctv_cnt = vecCCTV.size();
	SetDir();
	Solve();
	cout << empty_count;
	return 0;
}