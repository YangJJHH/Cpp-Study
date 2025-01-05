#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <queue>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
using namespace std;
int N;
queue<int> q;
int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	string command;
	cin >> N;
	for(int i=0; i<N; ++i)
	{
		cin >> command;
		if (command == "push")
		{
			int val;
			cin >> val;
			q.push(val);
		}
		else if (command == "pop")
		{
			if (q.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				int val = q.front();
				q.pop();
				cout << val << '\n';
			}
		}
		else if (command == "size")
		{
			cout << q.size() << '\n';
		}
		else if (command == "empty")
		{
			if (q.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (command == "front")
		{
			if (q.empty()) cout << -1 << '\n';
			else cout << q.front() << '\n';
		}
		else if (command == "back")
		{
			if (q.empty()) cout << -1 << '\n';
			else cout << q.back() << '\n';
		}
	}
	return 0;
}