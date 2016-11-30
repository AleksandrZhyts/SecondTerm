// Reservoirs.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include"Reservoir.h"
#include"Array_reserv_water.h"

int main()
{
	Array_reserv_water arr(2);
	std::cin >> arr;
	Reservoir r3("Naroch", "lake", 2800, 1500, 300);
	arr.add_Reserv(r3);
	std::cout << arr;
	arr.del_Reserv("a");
	std::cout << arr;
	/*
	Reservoir r1, r2("Red sea", "sea", 4800, 2600, 1300);
	std::cin >> r1;
	std::cout << r1 << r2;
	std::cout << r1.getName() << " has surface : " << r1.water_surface() << std::endl;
	std::cout << r2.getName() << " has water valume : " << r2.water_valume() << std::endl;
	std::cout << "The same type reservoir ? " << r1.compare_type(r2) << std::endl;
	std::cout << "Who is biger ? " << (r1 < r2)<< std::endl;
	r1 = r2;
	std::cout << "The same type reservoir ? " << r1.compare_type(r2) << std::endl;
	std::cout << r1 << r2;
	*/
	
	return 0;
}

