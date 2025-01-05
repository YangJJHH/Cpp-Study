#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <vector>
#include <list>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
using namespace std;
int N, K;
int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	cin >> N >> K;
	list<int> li;
	for (int i = 0; i < N; ++i)
		li.push_back(i+1);

	auto iter = li.begin();
	vector<int> answer;
	int count = 0;
	while (!li.empty())
	{
		if (count == K - 1)
		{
			answer.push_back(*iter);
			iter = li.erase(iter);
			count = 0;

			if (iter == li.end())
				iter = li.begin();
		}
		else
		{
			count++;
			if (iter == li.end())
				iter = li.begin();
			else
				iter++;

			if (iter == li.end())
				iter = li.begin();
		}
	}
	cout << "<";
	for (int i = 0; i < answer.size() - 1; ++i)
	{
		cout << answer[i] << ", ";
	}
	cout << answer[answer.size() - 1] << ">";

	return 0;
}