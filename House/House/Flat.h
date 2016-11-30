#pragma once
#include "Man.h"

class Flat
{
	unsigned int number_roommates;
	char *h_phone;
	unsigned int num_rooms;
	double total_space;
	double living_space;;
	double kitchen_space;
	unsigned int floor;

public:
	Man *roommates;
	
	Flat();
	
	Flat(const Flat&);
	
	void register_Person();
	
	void check_out_Person(char*);
	
	int search_person(char*);
	
	unsigned int getNumber_roommates();

	void operator=(const Flat&);

	friend std::istream& operator>>(std::istream& , Flat&);

	friend std::ostream& operator<<(std::ostream& , Flat&);
	
	~Flat();
};

