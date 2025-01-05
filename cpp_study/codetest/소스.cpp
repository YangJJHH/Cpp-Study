#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	int n = 326123;


	string s = to_string(n);
	sort(s.begin(), s.end(), [](char s1, char s2) { return s1 > s2; });
	long long answer = stol(s);
	

	return 0;
}