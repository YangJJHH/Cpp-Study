#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define FILL(arr,val) fill(begin(arr), end(arr), val);
#define CHECK_CONDITION_CONTINUE(condition) if(condition) continue;
#define CHECK_CONDITION_BREAK(condition) if(condition) break;
#define CHECK_CONDITION_RETURN_VOID(condition) if(condition) return;
using namespace std;
int N;
vector<string> guitar;
vector<string> vecDictionary;
map<string, int> cacheSum;
unordered_map<string, int> rankDictionary;
int CalcSum(std::string & s)
{
	int sum = 0;
	for (auto val : s)
	{
		if (isdigit(val))
			sum += val - '0';
	}
	return sum;
}

bool CompareGuitar(std::string& s1, std::string& s2)
{
	// compare length
	if (s1.size() != s2.size()) return s1.size() < s2.size();

	// compare sum
	int s1Sum = cacheSum[s1];
	int s2Sum = cacheSum[s2];
	if (s1Sum != s2Sum) return s1Sum < s2Sum;

	// dictionary
	return rankDictionary[s1] < rankDictionary[s2];

}
int main()
{
	fastio;
#ifndef BOJ
	freopen("input.txt", "r", stdin);
#endif // _TEST
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		std::string str;
		cin >> str;
		cacheSum[str] = CalcSum(str);
		guitar.push_back(str);
		vecDictionary.push_back(str);
	}

	std::sort(vecDictionary.begin(), vecDictionary.end());
	for (int i = 0; i < vecDictionary.size(); ++i)
	{
		rankDictionary[vecDictionary[i]] = i;
	}

	std::sort(guitar.begin(), guitar.end(), CompareGuitar);

	for (int i = 0; i < N; ++i)
	{
		cout << guitar[i] << "\n";
	}
	return 0;
}