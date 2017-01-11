#include "stdafx.h"
#include "_directory.h"

using namespace std;

_directory::_directory()
{
	company = nullptr;
	owner = nullptr;
	phone = nullptr;
	address = nullptr;
	occupation = nullptr;
}

_directory::_directory(char* c, char* o, char* p, char* a, char* oc)
{
	company = new char[strlen(c) + 1];
	if (!company) 
	{
		RussianMessage("Ошибка при выделении памяти !!!");
		exit(1);
	}
	strcpy_s(company, strlen(c) + 1, c);

	owner = new char[strlen(o) + 1];
	if (!owner)
	{
		RussianMessage("Ошибка при выделении памяти !!!");
		exit(1);
	}
	strcpy_s(owner, strlen(o) + 1, o);

	phone = new char[strlen(p) + 1];
	if (!phone)
	{
		RussianMessage("Ошибка при выделении памяти !!!");
		exit(1);
	}
	strcpy_s(phone, strlen(p) + 1, p);

	address = new char[strlen(a) + 1];
	if (!address)
	{
		RussianMessage("Ошибка при выделении памяти !!!");
		exit(1);
	}
	strcpy_s(address, strlen(a) + 1, a);

	occupation = new char[strlen(oc) + 1];
	if (!occupation)
	{
		RussianMessage("Ошибка при выделении памяти !!!");
		exit(1);
	}
	strcpy_s(occupation, strlen(oc) + 1, oc);
}

void _directory::put()
{
	char temp[1024];
	RussianMessage("\nВведите название компании:\n");
	std::cin >> temp;
	
	if (company) delete[] company;
	company = new char[strlen(temp) + 1];
	
	if (!company) 
	{
		RussianMessage("Ошибка при выделении памяти !!!");
		exit(1);
	}
	strcpy_s(company, strlen(temp) + 1, temp);
	
	RussianMessage("\nВведите имя хозяина:\n");
	std::cin >> temp;
	
	if (owner) delete[] owner;
	owner = new char[strlen(temp) + 1];
	
	if (!owner) 
	{
		RussianMessage("Ошибка при выделении памяти !!!");
		exit(1);
	}
	strcpy_s(owner, strlen(temp) + 1, temp);

	RussianMessage("\nВведите номер телефона:\n");
	std::cin >> temp;
	
	if (phone) delete[] phone;
	phone = new char[strlen(temp) + 1];
	
	if (!phone) 
	{
		RussianMessage("Ошибка при выделении памяти !!!");
		exit(1);
	}
	strcpy_s(phone, strlen(temp) + 1, temp);

	RussianMessage("\nВведите адрес компании:\n");
	std::cin >> temp;
	
	if (address) delete[] address;
	address = new char[strlen(temp) + 1];
	
	if (!address)
	{
		RussianMessage("Ошибка при выделении памяти !!!");
		exit(1);
	}
	strcpy_s(address, strlen(temp) + 1, temp);
	
	RussianMessage("\nВведите род деятельности:\n");
	std::cin >> temp;
	
	if (occupation) delete[] occupation;
	occupation = new char[strlen(temp) + 1];
	
	if (!occupation) 
	{
		RussianMessage("Ошибка при выделении памяти !!!");
		exit(1);
	}
	strcpy_s(occupation, strlen(temp) + 1, temp);
}

void _directory::search_record(int key)
{
	fstream f("d:\\directory.txt", ios::in | ios::binary);
	if (!f) {
		RussianMessage("Файл не открылся для чтения !!!");
		exit(1);
	}
	char *str_c = nullptr, 
		 *str_o = nullptr, 
		 *str_p = nullptr, 
		 *str_a = nullptr, 
		 *str_oc = nullptr;
	int _size,
		temp;
	
	bool flag = false;

	char str[256];
	RussianMessage("Введите поле для поиска: ");
	cin >> str;
	
	while (f.read((char*)&_size, sizeof(int)) && !flag)
	{
		delete[]str_c;
		delete[]str_o;
		delete[]str_p;
		delete[]str_a;
		delete[]str_oc;

		str_c = new char[_size + 1];
		if (!str_c)
		{
			RussianMessage("Ошибка при выделении памяти !!!");
			exit(1);
		}
		
		f.read((char*)str_c, _size * sizeof(char));
		str_c[_size] = '\0';
		
		f.read((char*)&temp, sizeof(int));
		str_o = new	char[temp + 1];
		if (!str_o)
		{
			RussianMessage("Ошибка при выделении памяти !!!");
			exit(1);
		}
		f.read((char*)str_o, temp * sizeof(char));
		str_o[temp] = '\0';
		
		f.read((char*)&temp, sizeof(int));
		str_p = new	char[temp + 1];
		if (!str_p)
		{
			RussianMessage("Ошибка при выделении памяти !!!");
			exit(1);
		}
		f.read((char*)str_p, temp * sizeof(char));
		str_p[temp] = '\0';
	
		f.read((char*)&temp, sizeof(int));
		str_a = new	char[temp + 1];
		if (!str_a)
		{
			RussianMessage("Ошибка при выделении памяти !!!");
			exit(1);
		}
		f.read((char*)str_a, temp * sizeof(char));
		str_a[temp] = '\0';
		
		f.read((char*)&temp, sizeof(int));
		str_oc = new	char[temp + 1];
		if (!str_oc)
		{
			RussianMessage("Ошибка при выделении памяти !!!");
			exit(1);
		}
		f.read((char*)str_oc, temp * sizeof(char));
		str_oc[temp] = '\0';
		
		switch (key)
		{
		case 1:
			if (strcmp(str_c, str) == 0) flag = true;
			break;
		case 2:
			if (strcmp(str_o, str) == 0) flag = true;
			break;
		case 3:
			if (strcmp(str_p, str) == 0) flag = true;
			break;
		case 4:
			if (strcmp(str_oc, str) == 0) flag = true;
			break;
		default:
			break;
		}
	}
	if (flag)
	{
		RussianMessage("\nKомпания: ");
		cout << str_c;
		RussianMessage("\nХозяин: ");
		cout << str_o;
		RussianMessage("\nТелефон: ");
		cout << str_p;
		RussianMessage("\nАдрес: ");
		cout << str_a;
		RussianMessage("\nРод занятий: ");
		cout << str_oc;
	}
	else cout << "\nThat record is absent in directory\n";
}

void _directory::add()
{
	int _size;
	fstream f("d:\\directory.txt", ios::out | ios::binary | ios::app);
	if (!f) {
		RussianMessage("Файл не открылся для записи !!!");
		exit(1);
	}
	
	_size = strlen(company);
	//Записываем количество символов в имени
	f.write((char*)&_size, sizeof(int));
	//Записываем имя
	f.write((char*)company, _size * sizeof(char));
	
	_size = strlen(owner);
	f.write((char*)&_size, sizeof(int));
	f.write((char*)owner, _size * sizeof(char));

	_size = strlen(phone);
	f.write((char*)&_size, sizeof(int));
	f.write((char*)phone, _size * sizeof(char));

	_size = strlen(address);
	f.write((char*)&_size, sizeof(int));
	f.write((char*)address, _size * sizeof(char));

	_size = strlen(occupation);
	f.write((char*)&_size, sizeof(int));
	f.write((char*)occupation, _size * sizeof(char));
	
	f.close();
}

void _directory::ShowFromFile()
{
	fstream f("d:\\directory.txt", ios::in | ios::binary);
	if (!f)
	{
		RussianMessage("Файл не открылся для чтения !!!");
		exit(1);
	}
	char *str_temp;
	int _size,
		 temp;
	
	//В цикле зачитываем содержимое файла
	while (f.read((char*)&_size, sizeof(int)))
	{
		str_temp = new char[_size + 1];
		if (!str_temp)
		{
			RussianMessage("Ошибка при выделении памяти !!!");
			exit(1);
		}
		RussianMessage("\nКомпания: ");
		
		f.read((char*)str_temp, _size * sizeof(char));
		str_temp[_size] = '\0';
		cout << str_temp << endl;
		
		RussianMessage("\nХозяин: ");
		f.read((char*)&temp, sizeof(int));
		
		delete[]str_temp;
		str_temp = new	char[temp + 1];
		if (!str_temp)
		{
			RussianMessage("Ошибка при выделении памяти !!!");
			exit(1);
		}
		f.read((char*)str_temp, temp * sizeof(char));
		str_temp[temp] = '\0';
		cout << str_temp << endl;
		
		RussianMessage("\nТелефон: ");
		f.read((char*)&temp, sizeof(int));
		
		delete[]str_temp;
		str_temp = new	char[temp + 1];
		if (!str_temp)
		{
			RussianMessage("Ошибка при выделении памяти !!!");
			exit(1);
		}
		f.read((char*)str_temp, temp * sizeof(char));
		str_temp[temp] = '\0';
		cout << str_temp << endl;
		
		RussianMessage("\nАдрес: ");
		f.read((char*)&temp, sizeof(int));
		
		delete[]str_temp;
		str_temp = new	char[temp + 1];
		if (!str_temp)
		{
			RussianMessage("Ошибка при выделении памяти !!!");
			exit(1);
		}
		f.read((char*)str_temp, temp * sizeof(char));
		str_temp[temp] = '\0';
		cout << str_temp << endl;
		
		RussianMessage("\nРод занятий: ");
		f.read((char*)&temp, sizeof(int));
		
		delete[]str_temp;
		str_temp = new	char[temp + 1];
		if (!str_temp)
		{
			RussianMessage("Ошибка при выделении памяти !!!");
			exit(1);
		}
		f.read((char*)str_temp, temp * sizeof(char));
		str_temp[temp] = '\0';
		cout << str_temp << endl;
		
		delete[]str_temp;
	}
}

_directory::~_directory()
{
	delete[] company;
	delete[] owner;
	delete[] phone;
	delete[] address;
	delete[] occupation;
}
