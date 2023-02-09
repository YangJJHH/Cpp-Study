#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <string>
#define fastio cin.tie(NULL)->sync_with_stdio(false);

using namespace std;
int N;
pair<char, char> node[26];

void pre(char start)
{
	if (start == '.') return;
	cout << start;
	pre(node[start - 'A'].first);
	pre(node[start - 'A'].second);
	
}
void inorder(char start)
{
	if (start == '.') return;
	
	inorder(node[start - 'A'].first);
	cout << start;
	inorder(node[start - 'A'].second);
}
void post(char start)
{
	if (start == '.') return;
	post(node[start - 'A'].first);
	post(node[start - 'A'].second);
	cout << start;
}
int main()
{
	fastio;
	freopen("input.txt", "r", stdin);
	cin >> N;
	char a, b, c;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c;
		node[a - 'A'] = { b,c };
	}
	pre('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	post('A');
	return 0;
}