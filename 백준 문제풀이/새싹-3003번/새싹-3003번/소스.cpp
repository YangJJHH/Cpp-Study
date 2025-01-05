#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define _TEST
using namespace std;
enum eCHESS
{
	KING = 0,
	QUEEN,
	LOOK,
	BISHOP,
	KNIGHT,
	PAWN,
	MAX,
};

const int chess[MAX] = { 1,1,2,2,2,8 };
int main()
{
	fastio;
	int input[MAX] = {};
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST

	for (int i = 0; i < MAX; ++i)
	{
		cin >> input[i];
		cout << chess[i] - input[i] << " ";
	}
	return 0;
}