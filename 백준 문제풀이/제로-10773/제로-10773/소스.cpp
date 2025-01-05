#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <stack>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
using namespace std;
unsigned int sum;
int K;
int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	cin >> K;
	stack<int> st;
	int input;
	for (int i = 0; i < K; ++i)
	{
		cin >> input;
		if (input == 0)
			st.pop();
		else
			st.push(input);
	}

	while(!st.empty())
	{
		sum += st.top();
		st.pop();
	}
	cout << sum;
	return 0;
}