#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <vector>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define FILL(arr,val) fill(begin(arr), end(arr), val);
#define CHECK_CONDITION_CONTINUE(condition) if(condition) continue;
#define CHECK_CONDITION_BREAK(condition) if(condition) break;
#define CHECK_CONDITION_RETURN_VOID(condition) if(condition) return;
using namespace std;
void ChatBot(int Total, int n)
{
	int dashCnt = (Total - n) * 4;
	string dash(dashCnt, '_');
	cout << dash << "\"재귀함수가 뭔가요?\"\n";
	if (n == 0)
	{
		cout << dash << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
		cout << dash << "라고 답변하였지.\n";
		return;
	}
	cout << dash << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
	cout << dash << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
	cout << dash << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
	ChatBot(Total, n - 1);
	

	cout << dash  << "라고 답변하였지.\n";
}
int main()
{
	fastio;
#ifndef BOJ
	freopen("input.txt", "r", stdin);
#endif // _TEST

	int N;
	cin >> N;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	ChatBot(N,N);

	return 0;
}