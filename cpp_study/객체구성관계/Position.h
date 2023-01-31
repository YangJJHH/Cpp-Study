#pragma once
#include <iostream>
class Position
{
private:
	int _x;
	int _y;
public:
	Position(const int& x, const int& y) : _x(x), _y(y)
	{}

	void Set(const int& x_taget, const int& y_target)
	{
		_x = x_taget;
		_y = y_target;
	}
	void Set(const Position&  target)
	{
		Set(target._x, target._y);
	}

	friend std::ostream& operator << (std::ostream& out, const Position& p)
	{
		out << p._x << "  " << p._y << std::endl;
		return out;
	}
};