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

	friend std::ostream& operator<<(std::ostream&, Array_reserv_water&);
	
	friend std::istream& operator >> (std::istream&, Array_reserv_water&);
	
	~Array_reserv_water();
};

