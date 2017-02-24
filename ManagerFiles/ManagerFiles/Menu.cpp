#pragma once
#include "stdafx.h"

void russianMessage(char *message)
{
	char rmessage[256];
	CharToOemA(message, rmessage);
	std::cout << rmessage;
}

Work_with_File _file;
User user;
UserPolicy policyUser; 

Entrance_Program::Entrance_Program() {}

void Entrance_Program::use_menu_Login()
{
	while (menu_Login())
		switch (getSelection())
		{
		case 1:
			user.enterUser(1);
			if (user.is_User_Db())
				(!user.getUser().user_Policy) ? use_menu_Admin() : use_menu_User();
			else
			{
				russianMessage("\n�������� ��� ��� ������\n");
				system("pause");
			}
			break;
		case 2:
			user.registerUser();
			use_menu_User();
			break;
		}
}

void Entrance_Program::use_menu_User()
{
	int copy_resolution;
	string _nameFile;
	while (menu_User())
		switch (getSelection())
		{
		case 2:    
			//�������� �����
			russianMessage("\n������� ���� � ��� ����� ���������: \n");
			getline(cin, _nameFile);
			_file.createFile(_nameFile); //���������� ����������
			break;
		case 3:   
			//����� ����������� ����� �� �����
			if (_file.setFileSource())
				_file.printFile(_file.getFileSource()); //���������� ����������
			break;
		case 1:	  
			//����������� �����
			
			if (_file.setFileSource())
			{
				_file.setFileDestination();

				policyUser.init_map_policy();

				copy_resolution = policyUser.isUserCopyFile(_file.getFileSource(), user.getUser().user_Policy);

				if (copy_resolution == 0)
				{
					russianMessage("\n��� ���� ��� �����������\n"); //monitoring 

				}
				if (copy_resolution == 1)
				{
					//����������
					russianMessage("\n����������� � �����������\n");
					_file.move_File(_file.getFileSource(), _file.getFileDestination());
				}
				if (copy_resolution == 2)
				{
					russianMessage("\n������� ����������� \n");
					_file.move_File(_file.getFileSource(), _file.getFileDestination());
				}
			}
			break; 
		}
}

void Entrance_Program::use_menu_Admin()
{
	while (menu_Admin())
		switch (getSelection())
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
			//����������� �����
			
			if (_file.setFileSource())
			{
				_file.setFileDestination();
				_file.move_File(_file.getFileSource(), _file.getFileDestination());
			}
			break;
		case 5:
			//�������� �����
			if (_file.setFileSource())
				_file.removeFile(_file.getFileSource());
			break;
		case 6:
			//���������� �����
			break;
		case 7:
			//����������� �����
			break;
		case 8:
			//������ ����������� ����� �� �����
			if (_file.setFileSource())
				_file.printFile(_file.getFileSource());
			break;
		case 9:
			//�������������� ������������� �����
			if (_file.setFileSource())
			{
				_file.setFileDestination();
				_file.renameFile(_file.getFileSource(), _file.getFileDestination());
			}
				
			break;
		case 10:
			//���� � ���� �����������
			use_menu_Monitoring();
			break;
		}
}

void Entrance_Program::use_menu_Monitoring()
{
	while (menu_Monitoring())
		switch (getSelection())
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