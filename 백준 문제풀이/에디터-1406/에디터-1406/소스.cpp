#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <list>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define _TEST
using namespace std;


int N;
char Command;
char subCommand;
list<char> input;
int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST

	string s;
	cin >> s;
	for (auto& ch : s)
	{
		input.push_back(ch);
	}

	auto cursor = input.end();
	cin >> N;
	while (N > 0)
	{
		cin >> Command;
		switch (Command)
		{
		case 'L':
		{
			if (cursor != input.begin())
				cursor--;
		}
		break;
		case 'D':
		{
			if (cursor != input.end())
				cursor++;
		}
		break;
		case 'B':
		{
			if (cursor != input.begin())
			{
				cursor--;
				cursor = input.erase(cursor);
			}
		}
		break;
		case 'P':
		{
			cin >> subCommand;
			input.insert(cursor, subCommand);
		}
		break;
		}

		N--;
	}
	for (auto& ch : input)
	{
		cout << ch;
	}
	return 0;
}