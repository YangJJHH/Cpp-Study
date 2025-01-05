#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <queue>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define _TEST
using namespace std;

queue<int> q;
int N,val;
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
		if (command == "push")
		{
			cin >> val;
			q.push(val);
		}
		else if (command == "pop")
		{
			if (q.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (command == "size")
		{
			cout << q.size() << "\n";
		}
		else if (command == "empty")
		{
			int rst = q.empty() ? 1 : 0;
			cout << rst << "\n";
		}
		else if (command == "front")
		{
			if (q.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << q.front() << "\n";
			}
		}
		else if (command == "back")
		{
			if (q.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << q.back() << "\n";
			}
		}
	}


	return 0;
}