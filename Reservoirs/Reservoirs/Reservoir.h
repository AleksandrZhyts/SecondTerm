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

	bool compare_type(const Reservoir& r); //Сравнение типов море-море или бассейн-пруд

	bool operator<(const Reservoir& r);
	
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

	friend std::ostream& operator<<(std::ostream& os, Reservoir& r)
	{
		os << "Name reservoir: " << r.name << std::endl;
		os << "Type reservoir: " << r.type_reservoir << std::endl;
		os << "length reservoir: " << r.length << std::endl;
		os << "Width reservoir: " << r.width << std::endl;
		os << "Depth reservoir: " << r.depth << std::endl;
		return os;
	}
	
	friend std::istream& operator >> (std::istream& is, Reservoir& r)
	{
		std::cout << "Enter name of reservoir : \n";
		is.getline(r.name, 50);
		
		std::cout << "Enter type of reservoir : \n";
		is.getline(r.type_reservoir, 14);

		std::cout << "Enter length of reservoir : \n";
		is >> r.length;

		std::cout << "Enter width of reservoir : \n";
		is >> r.width;
		
		std::cout << "Enter depth of reservoir : \n";
		is >> r.depth;
		
		is.get();

		return is;
	}

	~Reservoir();
};
