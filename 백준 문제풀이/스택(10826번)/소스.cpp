#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <string>
#define fastio cin.tie(NULL)->sync_with_stdio(false);

using namespace std;
int N;
vector<int> stack;
bool IsEmpty() 
{
	if(stack.empty()) cout << -1 << "\n";
	return stack.empty();
}
void Command(string str)
{
	if (str == "pop")
	{
		if (IsEmpty()) return;
		cout <<stack.back()<<"\n";
		stack.pop_back();
	}
	else if (str == "top")
	{
		if (IsEmpty()) return;
		cout << stack.back() << "\n";
	}
	else if (str == "size")
	{
		cout << stack.size() << "\n";
	}
	else if (str == "empty")
	{
		cout << (stack.empty() ? 1 : 0)<<"\n";
	}
	else
	{
		string tmp = str.substr(5,str.length()-5);
		stack.push_back(stoi(tmp));
	}
}
int main()
{
	fastio;
	freopen("input.txt", "r", stdin);
	cin >> N;
	cin.ignore();
	string str;
	while (N--)
	{
		getline(cin,str);
		Command(str);
	}
	return 0;
}