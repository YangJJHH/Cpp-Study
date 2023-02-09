#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <string>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
using namespace std;
int n, m;
int s[1000001];

//부모 찾으면서 갱신
int find(int a)
{
	if (s[a] == a) {
		return a;
	}
	int rst = find(s[a]);
	s[a] = rst; // 제일 위의 루트까지 갔다가 그 값으로 부모 갱신
	return rst;
}
int main()
{
	fastio;
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	//집합 초기
	for (int i = 1; i <= n; i++)
	{
		s[i] = i;
	}
	int a, b, c;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
		//합집합
		if (a == 0)
		{
			//서로의 루트 찾아서 같은 집합인지 확인, 아닌경우만 합연산
			b = find(b);
			c = find(c);
			if (b != c)
			{
				s[b] = c;
			}
		}
		else
		{
			//같은 집합인 경우
			cout << ((find(b) == find(c)) ? "YES" : "NO") << "\n";
		}
	}
	return 0;
}
