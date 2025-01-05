#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define _TEST
using namespace std;

int A, B, C, D, P, M, N;
void CheckAttack(int time);
int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	cin >> A >> B >> C >> D;
	cin >> P >> M >> N;

	CheckAttack(P);
	CheckAttack(M);
	CheckAttack(N);

	return 0;
}

void CheckAttack(int time)
{
	int attacked = 0;
	
	int a = time % (A + B) ? time % (A + B) : time;
	if ( (A < a && a <= (A+B)) == false )
		attacked++;
	
	a = time % (C + D) ? time % (C + D) : time;
	if ((C < a && a <= (C+D)) == false)
		attacked++;
	
	cout << attacked << "\n";
}