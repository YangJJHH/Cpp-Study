#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int N;
int MAX = 0;
const int LENGTH = ('Z' - 'A') + 1;
int ch[LENGTH];
vector<string> word;
bool compare(string s1, string s2)
{
	return s1.length() > s2.length();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin >> N;
	string tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		word.push_back(tmp);
		for (int j = 0; j < tmp.length(); j++)
		{
			ch[(tmp[j] - 'A')] += pow(10,tmp.length() - j - 1);
		}
	}

	for (int i = 9; i >= 0; i--)
	{
		int m = 0,index = 0;
		for (int j = 0; j < LENGTH; j++)
		{
			if (m < ch[j])
			{
				m = ch[j];
				index = j;
			}
		}
		ch[index] = 0;
		for (auto& ele : word)
		{
			for (auto& e2 : ele)
			{
				if ((e2 - 'A') == index)
				{
					e2 = i+'0';
				}
			}
		}
	}
	int total = 0;
	for (auto& ele : word)
	{
		total+=stoi(ele);
	}
	cout << total;
	
	return 0;
}