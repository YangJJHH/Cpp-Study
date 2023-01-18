#include <iostream>
#include <limits>

#include <cmath>

int parent[1000001];

void initial(int n) {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}


int Find(int a) {
	if (parent[a] == a) {
		return a;
	}
	int rst = Find(parent[a]);
	parent[a] = rst;
	return rst;
}
void Merge(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return;

	parent[a] = b;
}
int main()
{
	using namespace std;

	int n, m, a, b;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int oper;
	initial(n);
	for (int i = 1; i <= m; i++) {
		cin >> oper >> a >> b;
		if (oper) {
			if (Find(a) == Find(b)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
		else {
			Merge(a,b);
		}
	}
	return 0;
}
