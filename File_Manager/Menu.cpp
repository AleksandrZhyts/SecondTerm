#pragma once
#include "stdafx.h"
#include "Menu.h"

void russianMessage(char *message)
{
	char rmessage[256];
	CharToOemA(message, rmessage);
	std::cout << rmessage;
}

Work_with_File _file;
menu<int> m;
User user;

Entrance_Program::Entrance_Program() {}

void Entrance_Program::use_menu_Login()
{
	while (m.menu_Login())
		switch (m.getSelection())
		{
		case 1:
			user.enterUser(1);
			if (user.is_User_Db())
				(!user.getUser().user_Policy) ? use_menu_Admin() : use_menu_User();
			else
				russianMessage("\n�������� ��� ��� ������\n");
			break;
		case 2:
			user.registerUser();
			//_member = getUser();
			use_menu_User();
			break;
		}
}

void Entrance_Program::use_menu_User()
{
	while (m.menu_User())
		switch (m.getSelection())
		{
		case 1:
			//�������� �����
			_file.createFile(); //���������� ����������
			break;
		case 2:
			//����� ����������� ����� �� �����
			_file.printFile(); //���������� ����������
			break;
		case 3:
			//����������� �����
			
			break;
		}
}

void Entrance_Program::use_menu_Admin()
{
	while (m.menu_Admin())
		switch (m.getSelection())
		{
		case 1:
			//���������� ������������ � ��
			user.createDb();
			break;
		case 2:
			//�������� ������������ �� ��
			user.editUserDb();
			break;
		case 3:
			//�������������� ��
			user.editUserDb(1);
			break;
		case 4:
			//����������� �����\n
			_file.move_File();
			break;
		case 5:
			//�������� �����
			_file.removeFile();
			break;
		case 6:
			//���������� �����
			break;
		case 7:
			//����������� �����
			break;
		case 8:
			//������ ����������� ����� �� �����
			_file.printFile();
			break;
		case 9:
			//���� � ���� �����������
			use_menu_Monitoring();
			break;
		}
}

void Entrance_Program::use_menu_Monitoring()
{
	while (m.menu_Monitoring())
		switch (m.getSelection())
		{
		case 1:
			//���������� �� ������������
			break;
		case 2:
			//���������� �� �������� ������
			break;
		case 3:
			//����������� ������� ������� � ���������
			break;
		case 4:
			//�������� �� ������� �������
			break;
		case 5:
			//�������� ������� �������
			break;
		}
}

Entrance_Program::~Entrance_Program() {}