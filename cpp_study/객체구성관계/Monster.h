#pragma once
#include <string>
#include "Position.h"
class Monster
{

private:
	std::string _name;
	Position _location;
public:
	Monster(const std::string name, const Position& location) : _name(name), _location(location)
	{

	}

	void MoveTo(const Position& target)
	{
		_location.Set(target);
	}

	friend std::ostream& operator << (std::ostream &out, const Monster &m )
	{
		out << m._name<<"  " << m._location <<std::endl;
		return out;
	}
};