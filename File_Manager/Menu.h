#pragma once
#include "User.h"
#include "Work_with_File.h"

using namespace std;

void russianMessage (char *message);

template <class T>
class menu
{
public:
	menu();
	virtual bool menu_Login();
	virtual bool menu_User();
	virtual bool menu_Admin();
	virtual bool menu_Monitoring();
	void setSelection();
	T getSelection();

	~menu();
private:
	T selection;
};

template <class T>
menu<T>::menu():selection(0){}

template <class T>
bool menu<T>::menu_Login()
{
	//system("pause");
	system("cls");
	russianMessage("\tВведите 1 для входа в систему\n");
	russianMessage("\tВведите 2 для регистрации\n");
	russianMessage("\tВведите 0 для выхода\n");

	this->setSelection();
	
	return selection != 0;
}

template <class T>
bool menu<T>::menu_User()
{
	system("pause");
	system("cls");
	russianMessage("\tВведите 1 для создания файла\n");
	russianMessage("\tВведите 2 для вывода содержимого файла на экран\n");
	russianMessage("\tВведите 3 для копирования файла\n");
	russianMessage("\tВведите 0 для выхода\n");

	this->setSelection();

	return selection != 0;
}

template <class T>
bool menu<T>::menu_Admin()
{
	system("pause");
	system("cls"); 
	russianMessage("\tВведите 1 для добавления пользователя в БД\n");
	russianMessage("\tВведите 2 для удаления пользователя из БД\n");
	russianMessage("\tВведите 3 для редактирования файла БД\n");
	russianMessage("\tВведите 4 для копирования файла\n");
	russianMessage("\tВведите 5 для удаления файла\n");
	russianMessage("\tВведите 6 для шифрования файла\n");
	russianMessage("\tВведите 7 для расшифровки файла\n");
	russianMessage("\tВведите 8 для вывода содержимого файла на экран\n");
	russianMessage("\tВведите 9 для входа в меню мониторинга \n");
	russianMessage("\tВведите 0 для выхода\n");

	this->setSelection();

	return selection != 0;
}

template <class T>
bool menu<T>::menu_Monitoring()
{
	system("pause");
	system("cls");
	russianMessage("\tведите 1 для просмотра статистики по пользователю\n");
	russianMessage("\tВведите 2 для просмотра статистики по причинам неудач\n");
	russianMessage("\tВведите 3 для просмотра соотношения удачных попыток к неудачным\n");
	russianMessage("\tВведите 4 для просмотра не удачных попыток\n");
	russianMessage("\tВведите 5 для просмотра удачных попыток\n");
	russianMessage("\tВведите 0 для выхода\n");

	this->setSelection();
	
	return selection != 0;
}

template <class T>
void menu<T>::setSelection()
{
	T select;
	cin >> select;
	selection = select;
	cin.get();
}

template <class T>
T menu<T>::getSelection()
{
	return selection;
}

template <class T>
menu<T>::~menu(){}

class Entrance_Program 
{
public:
	Entrance_Program();
	void use_menu_Login();
	void use_menu_User();
	void use_menu_Admin();
	void use_menu_Monitoring();
	~Entrance_Program();
};
