#include "stdafx.h"

using namespace std;

class pet
{
public:
	pet() { /*cout << "\nconstr pet\n";*/ };
	
	~pet() {/*cout << "\ndestr pet\n";*/ };
	
	void move()
	{
		cout << "\nI can";
	}
	
	void eat()
	{
		cout << "\nI love eating";
	}
};

class parrot : public pet
{
public:
	parrot(char* _name, char* _color) 
	{
		//cout << "\nconstr parrot\n";
		strcpy_s(name, strlen(_name) + 1, _name);
		strcpy_s(color, strlen(_color) + 1, _color);
	}

	~parrot()
	{
		//cout << "\ndestr parrot\n";
	}

	void move()
	{
		pet::move();
		cout << " fly very high";
	}

	void eat()
	{
		pet::eat();
		cout << " berries\n";
	}
	void show()
	{
		cout << "\nMy name is " << name;
		cout << "\nMy color is " << color;
		move();
		eat();
	}

private:
	char name[15];
	char color[15];
};

class cat : public pet
{
public:
	cat(char* _name, char* _color)
	{
		//cout << "\nconstr cat\n";
		strcpy_s(name, strlen(_name) + 1, _name);
		strcpy_s(color, strlen(_color) + 1, _color);
	}

	~cat()
	{
		//cout << "\ndestr cat\n";
	}

	void move()
	{
		pet::move();
		cout << " walk quietly";
	}

	void eat()
	{
		pet::eat();
		cout << " mouses\n";
	}
	void show()
	{
		cout << "\nMy name is " << name;
		cout << "\nMy color is " << color;
		move();
		eat();
	}

private:
	char name[15];
	char color[15];
};

class dog : public pet
{
public:
	dog(char* _name, char* _color)
	{
		//cout << "\nconstr dog\n";
		strcpy_s(name, strlen(_name) + 1, _name);
		strcpy_s(color, strlen(_color) + 1, _color);
	}

	~dog()
	{
		//cout << "\ndestr dog\n";
	}

	void move()
	{
		pet::move();
		cout << " run fast";
	}

	void eat()
	{
		pet::eat();
		cout << " bones and meat\n";
	}
	void show()
	{
		cout << "\nMy name is " << name;
		cout << "\nMy color is " << color;
		move();
		eat();
	}

private:
	char name[15];
	char color[15];
};

int main()
{
	parrot p("Arra", "yellow");
	p.show();
	
	cat c("Murka", "braun");
	c.show();
	
	dog d("Rex", "black");
	d.show();

	return 0;
}

