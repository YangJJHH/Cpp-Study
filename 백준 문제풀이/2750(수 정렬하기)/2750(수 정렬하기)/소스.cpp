#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define FILL(arr,val) fill(begin(arr), end(arr), val);
#define CHECK_CONDITION_CONTINUE(condition) if(condition) continue;
#define CHECK_CONDITION_BREAK(condition) if(condition) break;
#define CHECK_CONDITION_RETURN_VOID(condition) if(condition) return;
using namespace std;
vector<int> arr;
vector<int> tmp;
void Merge(int start, int end)
{
	int mid = (start + end) / 2;

	int lIdx = start;
	int rIdx = mid;
	
	for( int i=start; i<end; ++i)
	{
		if( lIdx == mid ) tmp[i] = arr[rIdx++];
		else if (rIdx == end) tmp[i] = arr[lIdx++];
		else if (arr[lIdx] < arr[rIdx]) tmp[i] = arr[lIdx++];
		else tmp[i] = arr[rIdx++];
	}

	for (int i = start; i < end; ++i)
		arr[i] = tmp[i];
}

void MergeSort(int start, int end)
{
	if (start + 1 == end) return;
	int mid = (start + end) / 2;
	MergeSort(start, mid);
	MergeSort(mid, end);
	Merge(start, end);
}

int main()
{
	fastio;
#ifndef BOJ
	freopen("input.txt", "r", stdin);
#endif // _TEST
	int N;
	cin >> N;
	arr.resize(N);
	tmp.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	MergeSort(0, N);
	for (int i = 0; i < N; ++i)
	{
		cout << arr[i] <<'\n';
	}

	return 0;
}