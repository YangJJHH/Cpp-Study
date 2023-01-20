#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date
{
private: //public, private, protected.  default = private
	int _month;
	int _day;
	int _year;
public:
	void SetDate(const int& month, const int& day, const int& year)
	{
		_month = month;
		_day = day;
		_year = year;
	}
};

int main()
{
	//Date today{1,20,2023};
	Date today;
	today.SetDate(8,4,2023);
	return 0;  
}