#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <queue>
int N, COUNT;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt","r",stdin);
	cin >> N >> COUNT;
	queue<int> photo;
	vector<int> arr(COUNT);
	for (int i = 0; i < COUNT; i++)
	{
		cin >> arr[i];
	}
	
	return 0;
}