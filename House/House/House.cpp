// House.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Man.h"
#include "Flat.h"
#include "_house.h"


int main()
{
	_house h(1, 2);
	std::cin >> h;
	std::cout << h;
	/*
	Flat fl;
	std::cin >> fl;
	std::cout << fl;
	fl.check_out_Person("a");
	std::cout << fl;
	fl.register_Person();
	std::cout << fl;
	*/
	return 0;
}

