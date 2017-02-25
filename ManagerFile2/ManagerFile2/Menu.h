#pragma once

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
	system("cls");
	russianMessage("\t1 - вход в систему\n");
	russianMessage("\t2 - регистрация\n");
	russianMessage("\t0 - выход\n");

	this->setSelection();
	
	return selection != 0;
}

template <class T>
bool menu<T>::menu_User()
{
	system("pause");
	system("cls");
	russianMessage("\t1 - копирование файла\n");
	russianMessage("\t2 - шифрование файла\n");
	russianMessage("\t3 - расшифровка файла\n");
	russianMessage("\t4 - создание файла\n");
	russianMessage("\t5 - вывод содержимого файла на экран\n");
	russianMessage("\t0 - выход\n");

	this->setSelection();

	return selection != 0;
}

template <class T>
bool menu<T>::menu_Admin()
{
	system("pause");
	system("cls"); 
	russianMessage("\t1 - добавление пользователя в БД\n");
	russianMessage("\t2 - удаление пользователя из БД\n");
	russianMessage("\t3 - редактирование файла БД\n");
	russianMessage("\t4 - копирование файла\n");
	russianMessage("\t5 - удаление файла\n");
	russianMessage("\t6 - шифрование файла\n");
	russianMessage("\t7 - расшифровка файла\n");
	russianMessage("\t8 - вывод содержимого файла на экран\n");
	russianMessage("\t9 - переименование существующего файла\n");
	russianMessage("\t10 - вход в меню мониторинга \n");
	russianMessage("\t0 - выход\n");

	this->setSelection();

	return selection != 0;
}

template <class T>
bool menu<T>::menu_Monitoring()
{
	system("pause");
	system("cls");
	russianMessage("\t1 - просмотр статистики по пользователю\n");
	russianMessage("\t2 - просмотр статистики по причинам неудач\n");
	russianMessage("\t3 - просмотр соотношения удачных попыток к неудачным\n");
	russianMessage("\t4 - просмотр не удачных попыток\n");
	russianMessage("\t5 - просмотр удачных попыток\n");
	russianMessage("\t0 - выход\n");

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

class Entrance_Program : public menu<int>
{
public:
	Entrance_Program();
	void use_menu_Login();
	void use_menu_User();
	void use_menu_Admin();
	void use_menu_Monitoring();
	~Entrance_Program();
};
