
#include "stdafx.h"
#include "Man.h"
#include "Flat.h"
#include "_house.h"


int main()
{
	/*
	_house h(1, 2);
	std::cin >> h;
	std::cout << h;
	*/
	
	Flat fl1,fl2,fl3;
	std::cin >> fl1;
	std::cout << fl1;
	fl2 = fl1;
	std::cout << fl2;
	std::cin >> fl3;
	if (fl1 == fl2) std::cout << "Areas are equal\n";
	else std::cout << "Areas aren't equal\n";

	if (fl1 > fl3) std::cout << "First flat is more expensive \n";
	else std::cout << "Second flat is more expensive \n";

	//fl1.check_out_Person("a");
	//std::cout << fl1;
	//fl1.register_Person();
	//std::cout << fl1;
	
	return 0;
}

