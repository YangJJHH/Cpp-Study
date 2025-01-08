#define _CRT_SECURE_NO_DEPRECATE
#define _TEST
#include <cstring>	// for memset
#include <limits.h>	// for INT_MAX
#include <iostream>
#include <string>
#include <deque>
#include <sstream>
#define fastio cin.tie(NULL)->sync_with_stdio(false);
using namespace std;
int T,N;
string p,strArr;

int main()
{
	fastio;
#ifdef _TEST
	freopen("input.txt", "r", stdin);
#endif // _TEST
	deque<int> dq;
	cin >> T;
	while (T--)
	{
		cin >> p;
		cin >> N;
		cin >> strArr;
		
		strArr.erase(strArr.begin());
		strArr.erase(strArr.end() - 1);

 		istringstream iss(strArr);
		string buffer;
		dq.clear();
		while (getline(iss, buffer, ','))
		{
			dq.push_back(stoi(buffer));
		}

		bool reverse = false;
		bool bErr = false;
		string answer;
		for (auto& ele : p)
		{
			if (ele == 'R')
			{
				if(dq.empty()) continue;
				reverse = reverse ? false : true;
			}
			else if (ele == 'D')
			{
				if (dq.empty())
				{
					cout << "error" << '\n';
					bErr = true;
					break;
				}

				if (reverse)
					dq.pop_back();
				else
					dq.pop_front();
			}
		}

		if(bErr) continue;
		cout << "[";
		if (reverse)
		{
			for (int i = dq.size() - 1; i >= 0; i--)
			{
				cout << dq[i];
				if (i != 0)
					cout << ',';
			}
		}
		else
		{
			for (int i = 0; i < dq.size(); i++)
			{
				cout << dq[i];
				if (i != dq.size() - 1)
					cout << ',';
			}
		}
		cout << "]" << '\n';
	}

	return 0;
}