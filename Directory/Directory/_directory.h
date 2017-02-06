/*Задание
Используя потоки создайте класс СПРАВОЧНИК со следующими полями:
1. Название фирмы;
2. Владелец;
3. Телефон;
4. Адрес;
5. Род деятельности.
Реализовать следующие возможности:
1. Поиск по названию;
2. Поиск по владельцу;
3. Поиск по номеру телефона;
4. Поиск по роду деятельности;
5. Показ всех записей и добавление.
Вся информация, должна сохранятся в файле, должна
быть реализована возможность добавления новых данных.*/

#pragma once

void RussianMessage(char *message);

class _directory
{
public:
	
	_directory();
	
	_directory(char*, char*, char*, char*, char*, char*);

	void put();

	void search_record(int);

	void add();
	
	void ShowFromFile();
	
	~_directory();
private:
	std::fstream f;
	char *company;
	char *owner;
	char *phone;
	char *address;
	char *occupation;
};

