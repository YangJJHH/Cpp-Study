#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <stack>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
using namespace std;
int N;
int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	cin >> N;
	string str;
	int answer = 0;
	while (N--)
	{
		stack<int> st;
		cin >> str;

		st.push(str[0]);
		str.erase(str.begin());
		for (auto& ch : str)
		{
			if (!st.empty() && st.top() == ch)
				st.pop();
			else
				st.push(ch);
		}
		if (st.empty())
			answer++;
	}
	cout << answer;
	return 0;
}