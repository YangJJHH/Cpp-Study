#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <algorithm>
#include <vector>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
using namespace std;
int func1(int n, int& cnt)
{ 
	if (n == 1 || n == 2)
	{
		cnt++;
		return 1;
	}
	else return func1(n - 1,cnt) + func1(n - 2,cnt);
}
void func2(int n, int &cnt)
{
	vector<int> arr(n);
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < n; i++)
	{
		arr[i] = arr[i - 2] + arr[i - 1];
		cnt++;
	}
}
int main()
{
	int n;
	int cnt1, cnt2;
	cnt1 = cnt2 = 0;
	cin >> n;
	func1(n,cnt1);
	func2(n, cnt2);
	cout << cnt1 << " "<< cnt2;
	return 0;
}