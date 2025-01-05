#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
using namespace std;
int N;
stack<int> st;
unordered_map<int, int> map_idx;
int answer[500002];
int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	cin >> N;
	int val;
	st.push(0);
	for (int i = 0; i < N; ++i)
	{
		cin >> val;
		map_idx[val] = i+1;

		while (!st.empty())
		{
			int top = st.top();
			if (top >= val)
			{
				answer[i] = map_idx[top];
				st.push(val);
				break;
			}
			st.pop();
		}

		if (st.empty())
		{
			st.push(val);
			answer[i] = 0;
		}
		
	}

	

	for (int i = 0; i < N; ++i)
	{
		cout << answer[i]<<" ";
	}
	return 0;
}