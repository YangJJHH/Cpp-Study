#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
//세그먼트 트리
//(이진트리)
using namespace std;
int N, M, K;
long long init(vector<long long>& arr, vector<long long>& tree, int node, int start, int end)
{
	if (start == end) return tree[node]=arr[start];
	int mid = (start + end) / 2;
	//자식 양쪽의 합
	return tree[node] = init(arr,tree,node*2,start,mid) + init(arr, tree, node * 2 +1, mid+1, end);
}
long long partSum(vector<long long>& tree, int start, int end, int node, int left, int right)
{
	if (left > end || right < start) return 0;
	if (left <= start && right >= end) return tree[node];
	int mid = (start + end) / 2;
	return partSum(tree, start,mid,node*2,left,right) + partSum(tree, mid+1, end, node * 2+1, left, right);
}
void change(vector<long long>& tree, int start, int end, int node, int target, long long value)
{
	if (target<start || target>end) return;
	tree[node] += value;
	if (start == end) return;
	int mid = (start + end) / 2;
	change(tree, start, mid, node * 2,target,value);
	change(tree, mid+1, end, node * 2 +1, target, value);
}
int main()
{
	fastio;
	freopen("input.txt", "r", stdin);
	cin >> N >> M >> K;
	//트리 높이는 logN
	// 노드갯수는 2^(높이 + 1)
	int height = (int)ceil(log2(N));
	int tree_size = (1<<21);
	vector<long long>arr(N);
	vector<long long>tree(tree_size);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	init(arr,tree,1,0,N-1);

	long long a, b, c;
	for (int i = 0; i < M + K; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			long long diff = c - arr[b - 1];
			arr[b - 1] = c;
			change(tree,0,N-1,1,b-1, diff);
		}
		else if(a == 2)
		{
			cout <<partSum(tree, 0, N - 1, 1,b-1,c-1)<< '\n';
		}
	}
	return 0;
}