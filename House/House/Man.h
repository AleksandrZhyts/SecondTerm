#pragma once

class Man
{
	char *fio;
	unsigned int age;
	char *sex;
	char *marital_status;
	char *m_phone;
	char *add_inf;

public:
	Man();

	Man(char*, unsigned int, char*, char*, char*, char*);
	
	Man(const Man&);
	
	void operator=(const Man&);

	char* getFio();

	friend std::istream& operator>>(std::istream& , Man&);
	
	friend std::ostream& operator<<(std::ostream& , const Man&);
		
	~Man();
};

