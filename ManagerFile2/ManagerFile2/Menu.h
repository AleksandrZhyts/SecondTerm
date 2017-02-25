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
	russianMessage("\t1 - ���� � �������\n");
	russianMessage("\t2 - �����������\n");
	russianMessage("\t0 - �����\n");

	this->setSelection();
	
	return selection != 0;
}

template <class T>
bool menu<T>::menu_User()
{
	system("pause");
	system("cls");
	russianMessage("\t1 - ����������� �����\n");
	russianMessage("\t2 - ���������� �����\n");
	russianMessage("\t3 - ����������� �����\n");
	russianMessage("\t4 - �������� �����\n");
	russianMessage("\t5 - ����� ����������� ����� �� �����\n");
	russianMessage("\t0 - �����\n");

	this->setSelection();

	return selection != 0;
}

template <class T>
bool menu<T>::menu_Admin()
{
	system("pause");
	system("cls"); 
	russianMessage("\t1 - ���������� ������������ � ��\n");
	russianMessage("\t2 - �������� ������������ �� ��\n");
	russianMessage("\t3 - �������������� ����� ��\n");
	russianMessage("\t4 - ����������� �����\n");
	russianMessage("\t5 - �������� �����\n");
	russianMessage("\t6 - ���������� �����\n");
	russianMessage("\t7 - ����������� �����\n");
	russianMessage("\t8 - ����� ����������� ����� �� �����\n");
	russianMessage("\t9 - �������������� ������������� �����\n");
	russianMessage("\t10 - ���� � ���� ����������� \n");
	russianMessage("\t0 - �����\n");

	this->setSelection();

	return selection != 0;
}

template <class T>
bool menu<T>::menu_Monitoring()
{
	system("pause");
	system("cls");
	russianMessage("\t1 - �������� ���������� �� ������������\n");
	russianMessage("\t2 - �������� ���������� �� �������� ������\n");
	russianMessage("\t3 - �������� ����������� ������� ������� � ���������\n");
	russianMessage("\t4 - �������� �� ������� �������\n");
	russianMessage("\t5 - �������� ������� �������\n");
	russianMessage("\t0 - �����\n");

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
