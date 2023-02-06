#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
int N, M;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt","r",stdin);
	cin >> N;
	set<int> s;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		s.insert(tmp);
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int tmp;
		cin >> tmp;
		auto it = s.find(tmp);
		cout << ((it == s.end()) ? 0 : 1) << '\n';
	}


	return 0;
}