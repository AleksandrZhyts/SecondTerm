#pragma once

class Reservoir
{
		char* name;
		char* type_reservoir;
		double length;
		double width;
		double depth;
	
public:
	
	Reservoir();
	
	Reservoir(char*, char*, double, double, double);
	
	Reservoir(const Reservoir& r);
	
	double water_valume();

	double water_surface();

	bool compare_type(const Reservoir& r); 

	bool operator<( Reservoir& r);
	
	void operator=(const Reservoir& r);
	
	void setName(char*);
	
	char* getName();
	
	void setType_reservoir(char*);
	
	char* getType_reservoir();
	
	void setLength(double);
	
	double getLength();
	
	void setWidth(double);
	
	double getWidth();
	
	void setDepth(double);
	
	double getDepth();

	friend std::ostream& operator<<(std::ostream&, Reservoir&);
		
	friend std::istream& operator >> (std::istream&, Reservoir&);
	
	~Reservoir();
};
