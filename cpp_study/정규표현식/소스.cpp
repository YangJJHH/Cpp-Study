#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
	//regex re("\\d"); // 숫자하나
	//regex re("\\d*"); //숫자여러개
	// regex re("[ab]*"); // a와b 만 ok
	//regex re("[[:digit:]]{3}"); // :digit: == \d 서로 같은 의미, 숫자형식의 값을 3개 이상 받으면 ok
	//regex re("[A-Z]+"); //알파벳 형식의 1개이상
	//regex re("[A-Z]{1,3}"); //최소1개 최대 3개
	regex re("([0-9]{1})([-]?)([0-9]{1,4})"); //  ?: 있어도되고 없어도되고
	string str;
	while (true)
	{
		getline(cin, str);
		if (regex_match(str, re))
		{
			cout << "Match" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}