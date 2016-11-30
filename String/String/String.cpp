// String.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "MyString.h"

int main()
{
	MyString st1("Yes or "), st2("No ");
	
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
	
	_getch();
	return 0;
}

