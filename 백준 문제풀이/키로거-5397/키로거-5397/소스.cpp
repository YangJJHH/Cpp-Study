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
int N;
vector<string> strLog;
list<char> password;
int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	cin >> N;
	strLog.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> strLog[i];
	}
	
	for (auto& ele : strLog)
	{
		password.clear();
		auto cursor = password.end();
		for (auto& ch : ele)
		{
			switch (ch)
			{
			case '<':
			{
				if (cursor != password.begin())
				{
					cursor--;
				}
			}
			break;
			case '>':
			{
				if (cursor != password.end())
				{
					cursor++;
				}
			}
			break;
			case '-':
			{
				if (cursor != password.begin())
				{
					cursor--;
					cursor = password.erase(cursor);
				}
			}
			break;
			default:
			{
				password.insert(cursor, ch);
			}
			break;
			}
		}

		for (auto& e : password)
		{
			cout << e;
		}
		cout << "\n";
	}
	return 0;
}