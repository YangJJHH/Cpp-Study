#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
int x[] = { 0,0,-1,1 };
int y[] = { -1,1,0,0 };
int R, C, minutes = 0;
string* map;
class Point
{
public:
	int x;
	int y;
	Point(int ix = 0, int iy = 0) : x(ix), y(iy)
	{}
};
void Move(bool isWater = false)
{
	// 가는 방향 판단 기능
	if (isWater)
	{

	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << map[i][j];
		}
		cout << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);

	cin >> R >> C;
	cin.ignore();
	map = new string[R];
	//물과 고슴도치 좌표
	queue<Point> water;
	queue<Point> gosm;
	vector<vector<Point>> waters;

	for (int i = 0; i < R; i++)
	{
		getline(cin, map[i]);
		int w, g;
		w = map[i].find('*');
		g = map[i].find('S');
		if (w != string::npos)
		{
			water.emplace(i,w);
		}
		if (g != string::npos)
		{
			gosm.emplace(i,g);
		}
	}

	


	//메모리 해제
	delete[] map;
	return 0;
}