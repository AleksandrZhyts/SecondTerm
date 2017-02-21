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
	russianMessage("\t������� 1 ��� ����� � �������\n");
	russianMessage("\t������� 2 ��� �����������\n");
	russianMessage("\t������� 0 ��� ������\n");

	this->setSelection();
	
	return selection != 0;
}

template <class T>
bool menu<T>::menu_User()
{
	system("pause");
	system("cls");
	russianMessage("\t������� 1 ��� �������� �����\n");
	russianMessage("\t������� 2 ��� ������ ����������� ����� �� �����\n");
	russianMessage("\t������� 3 ��� ����������� �����\n");
	russianMessage("\t������� 0 ��� ������\n");

	this->setSelection();

	return selection != 0;
}

template <class T>
bool menu<T>::menu_Admin()
{
	system("pause");
	system("cls"); 
	russianMessage("\t������� 1 ��� ���������� ������������ � ��\n");
	russianMessage("\t������� 2 ��� �������� ������������ �� ��\n");
	russianMessage("\t������� 3 ��� �������������� ����� ��\n");
	russianMessage("\t������� 4 ��� ����������� �����\n");
	russianMessage("\t������� 5 ��� �������� �����\n");
	russianMessage("\t������� 6 ��� ���������� �����\n");
	russianMessage("\t������� 7 ��� ����������� �����\n");
	russianMessage("\t������� 8 ��� ������ ����������� ����� �� �����\n");
	russianMessage("\t������� 9 ��� ����� � ���� ����������� \n");
	russianMessage("\t������� 0 ��� ������\n");

	this->setSelection();

	return selection != 0;
}

template <class T>
bool menu<T>::menu_Monitoring()
{
	system("pause");
	system("cls");
	russianMessage("\t������ 1 ��� ��������� ���������� �� ������������\n");
	russianMessage("\t������� 2 ��� ��������� ���������� �� �������� ������\n");
	russianMessage("\t������� 3 ��� ��������� ����������� ������� ������� � ���������\n");
	russianMessage("\t������� 4 ��� ��������� �� ������� �������\n");
	russianMessage("\t������� 5 ��� ��������� ������� �������\n");
	russianMessage("\t������� 0 ��� ������\n");

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
