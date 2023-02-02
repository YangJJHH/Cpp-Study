#include <iostream>
#include <string>

using namespace std;

class Animal
{
private:
	string _name;
public:
	Animal(string name ="") : _name(name)
	{}

	virtual void speak()  //virtual 키워드를 통해 자식 클래스에서 재정의된 함수 사용
	{
		cout << "???" << endl;
	}
};
class Cat : public Animal
{
public:
	Cat(string name) : Animal(name)
	{}

	void speak()
	{
		cout << "Cat!" << endl;
	}
};

class Dog : public Animal
{
public:
	Dog(string name) : Animal(name)
	{}

	void speak()
	{
		cout << "Dog!" << endl;
	}
};

int main()
{
	Cat c("cat1");
	Cat c2("cat2");
	Dog d("dog");
	Animal* animals[] = {&c,&c2,&d };
	for (auto& ele : animals)
	{
		ele->speak();
	}
	return 0;
}