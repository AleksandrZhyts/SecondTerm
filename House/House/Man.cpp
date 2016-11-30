#include "stdafx.h"
#include "Man.h"

Man::Man()
{
	fio = NULL;
	sex = NULL;
	marital_status = NULL;
	m_phone = NULL;
	add_inf = NULL;
	age = 0;
	//std::cout << "Constructor Man" << std::endl;
}

Man::Man(char* f, unsigned int a, char* s, char* m_st, char* m_ph, char* inf)
{
	fio = new char[strlen(f) + 1];
	strcpy_s(fio, strlen(f) + 1, f);

	age = a;

	sex = new char[strlen(s) + 1];
	strcpy_s(sex, strlen(s) + 1, s);

	marital_status = new char[strlen(m_st) + 1];
	strcpy_s(marital_status, strlen(m_st) + 1, m_st);

	m_phone = new char[strlen(m_ph) + 1];
	strcpy_s(m_phone, strlen(m_ph) + 1, m_ph);

	add_inf = new char[strlen(inf) + 1];
	strcpy_s(add_inf, strlen(inf) + 1, inf);
}

Man::Man(const Man& m)
{
	Man m_copy(m.fio, m.age, m.sex, m.marital_status, m.m_phone, m.add_inf);   //так можно ??? 
}

void Man::operator=(const Man& m1)
{
	this->~Man();
	/*
	delete[] fio;
	fio = NULL;

	delete[] sex;
	sex = NULL;

	delete[] marital_status;
	marital_status = NULL;

	delete[] m_phone;
	m_phone = NULL;

	delete[] add_inf;
	add_inf = NULL;
	*/
// Ќе понимаю можно ли и как внутри этого метода вызвать €вный конструктор или копировани€ ? 	
	 //Man this(m1); ?
	
	fio = new char[strlen(m1.fio) + 1];
	strcpy_s(fio, strlen(m1.fio) + 1, m1.fio);

	age = m1.age;

	sex = new char[strlen(m1.sex) + 1];
	strcpy_s(sex, strlen(m1.sex) + 1, m1.sex);

	marital_status = new char[strlen(m1.marital_status) + 1];
	strcpy_s(marital_status, strlen(m1.marital_status) + 1, m1.marital_status);

	m_phone = new char[strlen(m1.m_phone) + 1];
	strcpy_s(m_phone, strlen(m1.m_phone) + 1, m1.m_phone);

	add_inf = new char[strlen(m1.add_inf) + 1];
	strcpy_s(add_inf, strlen(m1.add_inf) + 1, m1.add_inf);
	
}

char* Man::getFio()
{
	return fio;
}

Man::~Man()
{
	delete[] fio;
	fio = NULL;
	
	delete[] sex;
	sex = NULL;
	
	delete[] marital_status;
	marital_status = NULL;
	
	delete[] m_phone;
	m_phone = NULL;
	
	delete[] add_inf;
	add_inf = NULL;

	//std::cout << "Destructor Man" << std::endl;
}
