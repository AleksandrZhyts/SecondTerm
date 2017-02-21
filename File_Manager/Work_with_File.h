#pragma once
//#include "stdafx.h"
#include "User.h"

class Work_with_File 
{
public:
	Work_with_File();

	//Создание базы данных пользователей
	//void createDb();

	//Создание нового файла в текущем каталоге
	bool createFile();

	//Удалить существующий файл из текущего каталога
	bool removeFile();

	//Переименовать существующий файл в текущем каталоге
	bool renameFile();

	//Создание копии  файла
	bool copyFile(char*, char*);

	//Копирование файла из текущего каталога в указанный пользователем каталог
	bool move_File();

	//Вывод содержимого указанного пользователем файла из текущего каталога на экран
	bool printFile();

	~Work_with_File();

};

