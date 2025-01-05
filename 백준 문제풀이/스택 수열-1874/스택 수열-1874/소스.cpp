#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
using namespace std;
int N;
stack<int> st;
int arr[100002];
int lastTop;
int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	vector<char> answer;
	st.push(1);
	lastTop = 1;
	answer.push_back('+');
	for (int i = 0; i < N; ++i)
	{
		int j = lastTop + 1;
		while (true)
		{
			if (!st.empty())
			{
				if (lastTop == N)
					break;
				if (st.top() == N)
					break;
				if (st.top() == arr[i])
				{
					answer.push_back('-');
					lastTop = max(st.top(), lastTop);
					st.pop();
					break;
				}
			}

			answer.push_back('+');
			st.push(j++);
		}

		if (!st.empty() && st.top() == arr[i])
		{
			answer.push_back('-');
			lastTop = max(st.top(), lastTop);
			st.pop();
		}
	}
	if (st.empty())
	{
		for (auto& ele : answer) cout << ele << '\n';
	}
	else
		cout << "NO";

	return 0;
}