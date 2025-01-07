#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
using namespace std;
int N,M;
int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	cin >> N >> M;
	vector<int> vec;
	for (int i = 0; i < M; ++i)
	{
		int val;
		cin >> val;
		vec.push_back(val);
	}

	deque<int> dq;
	for (int i = 0; i < N; i++)
	{
		dq.push_back(i + 1);
	}

	int answer = 0;
	for (auto& ele : vec)
	{
		while (true)
		{
			if (dq[0] == ele)
			{
				dq.pop_front();
				break;;
			}
			int i = 0;
			for (; i < dq.size(); ++i)
			{
				if (dq[i] == ele)
					break;
			}
			if (i < dq.size() - i)
			{
				int val = dq.front();
				dq.pop_front();
				dq.push_back(val);
			}
			else
			{
				int val = dq.back();
				dq.pop_back();
				dq.push_front(val);
			}
			answer++;
		}
	}
	cout << answer;
	return 0;
}