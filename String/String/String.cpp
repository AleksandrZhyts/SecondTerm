#include "stdafx.h"
#include "MyString.h"

int main()
{
	MyString st1("([x-y-z}*[x+2y)-{z+4x)]."), st2("({x-y-z}*[x+2y]-(z+4x));");
	MyString st3("((((()))).");

	char a[15] = {'1','2','3','4','5','6','1','1','1','1','1','1'};
	char *ptr1 = a,
		**ptr2 = &ptr1;
	std::cout << *ptr1 << std::endl;
	//std::cout << *ptr2 << std::endl;
	//++ptr2;
	std::cout << *(ptr2+1) << std::endl;

	/*
	std::cout << st1 << std::endl;
	std::cout << st2 << std::endl;
	
	std::cout << st1 + st2 << std::endl;
	std::cout << st1 << std::endl;
	
	st1 += st2;

	st2 = st1 + st2;
	
	std::cout << "New st1: " << st1 << std::endl;
	std::cout << "New st2: " << st2 << std::endl;
	

	std::cout << "Less ? " << (st1 < st2) << std::endl;
	std::cout << "Equal ? " << (st1 == st2) << std::endl;
	std::cout << "More ? " << (st1 > st2) << std::endl;
	
	try
	{
		for (unsigned int i(0); i <= st2.getLen(); i++)
		{
			std::cout << st2[i] << std::endl;
		}
	}
	catch (const char* message)
	{
		std::cout << "Error! " << message << std::endl;
	}
	*/
	/*
	if (!st1.bracket_location()) std::cout << " - error brackets\n";
	else std::cout << "String doesn't have mistakes\n";
	
	if (!st2.bracket_location()) std::cout << " - error brackets\n";
	else std::cout << "String doesn't have mistakes\n";

	if (!st3.bracket_location()) std::cout << " - error brackets\n";
	else std::cout << "String doesn't have mistakes\n";
	*/
	_getch();
	return 0;
}

