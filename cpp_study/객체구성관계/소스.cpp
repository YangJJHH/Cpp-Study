#include "Monster.h"
using namespace std;

int main()
{
	Monster m1("troll",Position(0,0));

	//while (1) //gameloop
	{
		m1.MoveTo(Position(3, 4));
		cout << m1;
	}
	return 0;
}