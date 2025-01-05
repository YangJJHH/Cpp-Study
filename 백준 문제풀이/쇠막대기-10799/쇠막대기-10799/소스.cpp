#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <stack>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define _TEST
using namespace std;
string str;
stack<char> st;
stack<int> val;
int razer, stick, totalRazer, totalCount = 0;

int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	cin >> str;
	char prev = 0;
	for (auto& ele : str)
	{
		switch (ele)
		{
		case '(':
		{
			val.push(0);
			st.push(ele);
		}
		break;
		case ')':
		{
			st.pop();
			int value = val.top();
			val.pop();
			if (prev == '(')
			{
				if (val.empty() == false)
				{
					value++;
					int preval = val.top();
					preval += value;
					val.pop();
					val.push(preval);
				}
			}
			else
			{
				totalCount += value + 1;
				if (val.empty() == false)
				{
					int preval = val.top();
					preval += value;
					val.pop();

					val.push(preval);
				}
			}
		}
		break;
		}

		prev = ele;
	}

	cout << totalCount;
	return 0;
}