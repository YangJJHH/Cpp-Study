#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <deque>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define _TEST
using namespace std;

deque<int> dq;
int N, val;
string command;
int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	cin >> N;
	while (N--)
	{
		cin >> command;
		if (command == "push_back")
		{
			cin >> val;
			dq.push_back(val);
		}
		else if (command == "push_front")
		{
			cin >> val;
			dq.push_front(val);
		}
		else if (command == "pop_front")
		{
			if (dq.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (command == "pop_back")
		{
			if (dq.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if (command == "size")
		{
			cout << dq.size() << "\n";
		}
		else if (command == "empty")
		{
			int rst = dq.empty() ? 1 : 0;
			cout << rst << "\n";
		}
		else if (command == "front")
		{
			if (dq.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << dq.front() << "\n";
			}
		}
		else if (command == "back")
		{
			if (dq.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << dq.back() << "\n";
			}
		}
	}


	return 0;
}