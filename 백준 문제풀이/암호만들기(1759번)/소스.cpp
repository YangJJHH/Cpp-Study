#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int L, C;
char ch[15];

void DFS(int start, int m, int j, string str) //글자수, 모음수, 자음수 
{
	if (start == C) return;
	str += ch[start];
	if (ch[start] == 'a' || ch[start] == 'e' || ch[start] == 'i' || ch[start] == 'o' || ch[start] == 'u') m++;
	else j++;

	if (str.size() == L)
	{
		if (m > 0 && j > 1)
		{
			cout << str<<"\n";
		}
		char tmp = str.back();
		str.erase(str.end()-1);
		if (ch[tmp] == 'a' || ch[tmp] == 'e' || ch[tmp] == 'i' || ch[tmp] == 'o' || ch[tmp] == 'u') m--;
		else j--;
		return;
	}
	for (int i = start + 1; i < C; i++)
	{
		DFS(i, m, j, str);
	}
	
	
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin >> L >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> ch[i];
	}
	sort(ch, ch + C);
	for (int i = 0; i <= C - L; i++)
	{
		DFS(i, 0, 0, "");
	}

}