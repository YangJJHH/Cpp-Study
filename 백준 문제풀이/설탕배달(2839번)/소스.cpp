#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
using namespace std;
//그리디 알고리즘
int main()
{
	int N;
	cin >> N;
	int answer = -1;
	int count = N / 5; //5로 최대한 나눌수 있는 횟수 저장
	int rst;
	while (count>=0)
	{
		int tmp = N- 5 * count; // 5로 나눈 나머지가 3으로 나누어 떨어지지 않으면 5로 나누는 횟수를 차감
		if (tmp % 3 == 0)
		{
			answer = count + tmp / 3;
			break;
		}
		count--;
	}

	cout << answer;
	return 0;
}