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
				russianMessage("\nНеверное имя или пароль\n");
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
			//создания файла
			_file.createFile(); //обработать исключения
			break;
		case 2:
			//вывод содержимого файла на экран
			_file.printFile(); //обработать исключения
			break;
		case 3:
			//копирования файла
			
			break;
		}
}

void Entrance_Program::use_menu_Admin()
{
	while (m.menu_Admin())
		switch (m.getSelection())
		{
		case 1:
			//добавления пользователя в БД
			user.createDb();
			break;
		case 2:
			//удаление пользователя из БД
			user.editUserDb();
			break;
		case 3:
			//редактирование БД
			user.editUserDb(1);
			break;
		case 4:
			//копирования файла\n
			_file.move_File();
			break;
		case 5:
			//удаления файла
			_file.removeFile();
			break;
		case 6:
			//шифрования файла
			break;
		case 7:
			//расшифровки файла
			break;
		case 8:
			//вывода содержимого файла на экран
			_file.printFile();
			break;
		case 9:
			//вход в меню мониторинга
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
			//статистика по пользователю
			break;
		case 2:
			//статистика по причинам неудач
			break;
		case 3:
			//соотношение удачных попыток к неудачным
			break;
		case 4:
			//просмотр не удачных попыток
			break;
		case 5:
			//просмотр удачных попыток
			break;
		}
}

Entrance_Program::~Entrance_Program() {}