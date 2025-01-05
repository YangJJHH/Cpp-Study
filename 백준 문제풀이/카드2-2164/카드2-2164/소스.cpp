#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <queue>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
using namespace std;
queue<int> q;
int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	int N,val;
	cin >> N;
	
	for(int i=0; i<N; ++i)
	{
		q.push(i+1);
	}

	while (q.size() > 1)
	{
		q.pop();
		int front = q.front();
		q.pop();
		q.push(front);
	}

	cout << q.front();

	return 0;
}