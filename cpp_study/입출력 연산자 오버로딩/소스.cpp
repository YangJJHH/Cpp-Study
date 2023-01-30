#include <iostream>
#include <fstream>
using namespace std;

class Point
{
private:
	int _x;
	int _y;
public:
	Point(int x =0 , int y = 0) : _x(x), _y(y)
	{}

	friend ostream& operator << (ostream& out, const Point& point)
	{
		out << point._x << "  "<< point._y << endl;
		return out; //리턴을 통해 체이닝 가능
	}

	friend istream& operator >> (istream& in, Point& point)
	{
		in >> point._x >> point._y;
		return in; //리턴을 통해 체이닝 가능
	}
};

int main()
{
	Point p(1, 2),p2(3,4);
	cout << p << p2;

	Point p3, p4;
	cin >> p3 >> p4;
	cout << p3 << p4;

	//파일 출력
	/*ofstream of("out.txt");
	of << p << p2;
	of.close();*/

	return 0;
}