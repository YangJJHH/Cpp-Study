#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <stack>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define _TEST
using namespace std;
string input;
int answer = 0;

int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	int temp = 1;
	cin >> input;
	stack<char> st;
	stack<int> val;
	char prev = 0;
	for (auto& ele : input)
	{
		if (ele == '(')
		{
			temp *= 2;
			st.push(ele);
		}
		else if (ele == '[')
		{
			temp *= 3;
			st.push(ele);
		}
		else if (ele == ')')
		{
			if (st.empty() || st.top() != '(')
			{
				answer = 0;
				break;
			}
			if (prev == '(')
			{
				answer += temp;
			}

			temp /= 2;
			st.pop();
		}
		else if (ele == ']')
		{
			if (st.empty() || st.top() != '[')
			{
				answer = 0;
				break;
			}
			if (prev == '[')
			{
				answer += temp;
			}

			temp /= 3;
			st.pop();
		}

		prev = ele;
	}

	if (st.empty() == false)
		answer = 0;

	cout << answer;
	return 0;
}