#pragma once
#include "Reservoir.h"

class Array_reserv_water
{
	Reservoir *arr_water;
	unsigned int amount;

public:
	Array_reserv_water(unsigned int);
	
	Array_reserv_water(const Array_reserv_water&);
	
	Reservoir operator[](unsigned int);

	void add_Reserv(Reservoir&);
	
	int Array_reserv_water::search_reservoir(char*);
	
	void del_Reserv(char*);

	friend std::ostream& operator<<(std::ostream& os, Array_reserv_water& arr)
	{
		for (unsigned int i(0); i < arr.amount; i++)
		{
			os << i + 1 << " reservoir :\n";
			os << arr.arr_water[i];
		}
		return os;
	}

	friend std::istream& operator >> (std::istream& is, Array_reserv_water& arr)
	{
		for (unsigned int i(0); i < arr.amount; i++)
		{
			std::cout << "Enter " << i + 1 << " reservoir :\n";
			is >> arr.arr_water[i];
		}
		return is;
	}
	
	~Array_reserv_water();
};

