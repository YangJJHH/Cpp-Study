#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <stack>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define _TEST
using namespace std;

void CheckBracket(const string& str)
{
	stack<char> s;
	bool balance = true;
	for (auto& ch : str)
	{
		if (ch != '(' && ch != '[' && ch != ')' && ch != ']') continue;

		if (ch == '(' || ch == '[')
		{
			s.push(ch);
		}
		else
		{
			if (s.empty())
			{
				balance = false;
				break;
			}

			char rst = s.top();
			s.pop();
			if (ch == ')')
			{
				if (rst != '(')
				{
					balance = false;
					break;
				}
			}
			else if (ch == ']')
			{
				if (rst != '[')
				{
					balance = false;
					break;
				}
			}
		}
	}

	if (s.empty() == false)
		balance = false;

	if(balance)
		cout << "yes\n";
	else
		cout << "no\n";
}

int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	string str;
	while (true)
	{
		getline(cin, str);

		if (str[0] == '.') break;

		CheckBracket(str);
	}

	return 0;
}