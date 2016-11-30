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

	friend std::istream& operator>>(std::istream& is, Man& m)
	{
		std::cout << "Enter FIO : ";
		
		m.fio = new char[100];
		is.getline(m.fio, 99);

		std::cout << "Enter age : ";
		is >> m.age;
		is.get();

		std::cout << "Enter sex : ";
		m.sex = new char[8];
		is.getline(m.sex, 7);

		std::cout << "Enter marital status : ";
		m.marital_status = new char[10];
		is.getline(m.marital_status, 9);

		std::cout << "Enter mobile phone : ";
		m.m_phone = new char[16];
		is.getline(m.m_phone, 15);
		
		std::cout << "Enter additional information : ";
		m.add_inf = new char[81];
		is.getline(m.add_inf, 80);
		
		return is;
	}
	
	friend std::ostream& operator<<(std::ostream& os, const Man& m)
	{
		os << "FIO : " << m.fio << std::endl;
		os << "Age : " << m.age << std::endl;
		os << "Sex : " << m.sex << std::endl;
		os << "Marital status : " << m.marital_status << std::endl;
		os << "Mobile phone : " << m.m_phone << std::endl;
		os << "Additional information : " << m.add_inf << std::endl;
		return os;
	}
	
	~Man();
};

