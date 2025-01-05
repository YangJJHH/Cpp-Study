#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define _TEST
using namespace std;

int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	int N, X;
	cin >> N >> X;

	int iInput;
	for (int i = 0; i < N; ++i)
	{
		cin >> iInput;

		if (iInput < X)
			cout << iInput << " ";
	}
	return 0;
}