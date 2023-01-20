#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Friend
{
public: //access specifier
	string name;
	string address;
	int age;
	int height;
	int weight;

	void Print()
	{
		cout << name << " " << address << " " << age << " " << height << " " << weight << endl;
	}
};
int main()
{
	Friend freind{"jh","seoul",1,1,1}; //Instanciation, Instance
	freind.Print();

	vector<Friend> my_friends;
	my_friends.resize(5);

	for (auto& ele : my_friends)
	{
		ele.Print();
	}
	
	return 0;
}