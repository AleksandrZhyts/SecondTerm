#pragma once
#include "stdafx.h"

using namespace std;

class Work_with_File
{
public:
	Work_with_File();
	
	bool setFileSource();

	string& getFileSource();
	
	void setFileDestination();

	string& getFileDestination();

	//Создание нового файла в текущем каталоге
	bool createFile(string&);

	//Удалить существующий файл из текущего каталога
	bool removeFile(string);

	//Переименовать существующий файл в текущем каталоге
	bool renameFile(string, string);

	//Создание копии  файла
	bool copyFile(string, string);

	//Копирование файла из текущего каталога в указанный пользователем каталог
	bool move_File(string, string);

	//Вывод содержимого указанного пользователем файла из текущего каталога на экран
	bool printFile(string);

	~Work_with_File();

private:
	string fileSource;
	string fileDestination;
};

