#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define fastio cin.tie(NULL)->sync_with_stdio(false);

using namespace std;
long long x, y, z;

//ÀÌºÐÅ½»ö
int main()
{
	fastio;
	freopen("input.txt", "r", stdin);
	cin >> x >> y;
	z = y * 100 / x;
	long long z2 =z;
	long long start, end,mid;
	start = 0;
	end = 1e9;
	
	while (end - start>1)
	{
		mid = (start + end) / 2;
		z2 = (y+mid) * 100 / (x+mid);
		if (z2 > z)
		{
			end = mid;
		}
		else
		{
			start = mid;
		}
	}
	cout << ((((y + x) * 100 / (x + x)) == z) ? -1 : end);
	return 0;
}