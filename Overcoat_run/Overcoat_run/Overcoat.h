#pragma once

enum ov_coat { coat, fur_coat, sheepskin_coat, raincoat, windbreaker };

class Overcoat
{
	ov_coat clouth;
	double price;

public:
	Overcoat();
	
	Overcoat(double, ov_coat);
	
	Overcoat(const Overcoat&);
	
	void operator=(const Overcoat&);
	
	bool operator==(const Overcoat&);
	
	bool operator>(const Overcoat&);
	
	void setPrice(double);

	void setClouth(ov_coat);

	double getPrice();
	
	friend std::ostream& operator<<(std::ostream& os, Overcoat& cl);
	
	~Overcoat();
};

