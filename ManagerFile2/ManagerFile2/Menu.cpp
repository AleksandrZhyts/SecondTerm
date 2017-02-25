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
Monitoring monitoring;
Hash _hash;

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
				russianMessage("\nНеверное имя или пароль\n");
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
		case 1:	  
			//копирование файла
			
			if (_file.setFileSource())
			{
				_file.setFileDestination();

				policyUser.init_map_policy();

				copy_resolution = policyUser.isUserCopyFile(_file.getFileSource(), user.getUser().user_Policy);

				if (copy_resolution == 0)
				{
					russianMessage("\nНет прав для копирования\n"); //monitoring 
					break;
				}
				if (copy_resolution == 1)
				{
					//Шифрование
					russianMessage("\nКопирование с шифрованием\n");
					
					if (!_hash.is_File_Shifr(_file.getFileSource()))  //Мониторинг
						_hash.shifrFile(_file.getFileSource());

					_file.move_File(_file.getFileSource(), _file.getFileDestination());
					break;
				}
				if (copy_resolution == 2)
				{
					russianMessage("\nОбычное копирование \n");
					_file.move_File(_file.getFileSource(), _file.getFileDestination());
				}
			}
			break; 
		case 2:
			//шифрования файла
			if (_file.setFileSource())
			{
				if (!_hash.is_File_Shifr(_file.getFileSource()))  //Мониторинг
					_hash.shifrFile(_file.getFileSource());
				else russianMessage("\nФайл уже зашифрован\n");
			}
			break;
		case 3:
			//расшифровка файла
			if (_file.setFileSource())    //Мониторинг
			{
				if (_hash.is_File_Shifr(_file.getFileSource()))
					_hash.shifrFile(_file.getFileSource(), true);
			}
			break;
		case 4:
			//создание файла
			russianMessage("\nВведите путь и имя файла источника: \n");
			getline(cin, _nameFile);
			_file.createFile(_nameFile); //обработать исключения
			break;
		case 5:
			//вывод содержимого файла на экран
			if (_file.setFileSource())
				_file.printFile(_file.getFileSource()); //обработать исключения
			break;
		}
}

void Entrance_Program::use_menu_Admin()
{
	while (menu_Admin())
		switch (getSelection())
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
			//копирования файла
			if (_file.setFileSource())
			{
				_file.setFileDestination();
				_file.move_File(_file.getFileSource(), _file.getFileDestination());
			}
			break;
		case 5:
			//удаления файла
			if (_file.setFileSource())
				_file.removeFile(_file.getFileSource());
			break;
		case 6:
			//шифрования файла
			if (_file.setFileSource())
			{
				if (!_hash.is_File_Shifr(_file.getFileSource()))  //Мониторинг
					_hash.shifrFile(_file.getFileSource());
				else russianMessage("\nФайл уже зашифрован\n");
			}
			break;
		case 7:
			//расшифровки файла
			if (_file.setFileSource())    //Мониторинг
			{
				if (_hash.is_File_Shifr(_file.getFileSource()))
					_hash.shifrFile(_file.getFileSource(),true);
			}
			break;
		case 8:
			//вывода содержимого файла на экран
			if (_file.setFileSource())
				_file.printFile(_file.getFileSource());
			break;
		case 9:
			//переименование существующего файла
			if (_file.setFileSource())
			{
				_file.setFileDestination();
				_file.renameFile(_file.getFileSource(), _file.getFileDestination());
			}
				
			break;
		case 10:
			//вход в меню мониторинга
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