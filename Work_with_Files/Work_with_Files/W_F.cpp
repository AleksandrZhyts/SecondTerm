#include "stdafx.h"

//Функция копирования файла
bool CopyFile(char *source, char *destination)
{
	const int size = 65536;
	FILE *src, *dest;
	//Открытие Файла
	if (fopen_s(&src, source, "rb"))
	{
		return false;
	}
	//Получение дескриптора файла
	//int handle = _fileno(src);
	//выделение памяти под буффер
	char *data = new char[size];
	if (!data)
	{
		return false;
	}
	//Открытие файла, куда будет производиться копирование
	if (fopen_s(&dest, destination, "wb"))
	{
		delete[]data;
		return false;
	}
	int realsize;
	while (!feof(src))
	{
		//Чтение данных из файла
		realsize = fread(data, sizeof(char), size, src);
		//Запись данных в файл
		fwrite(data, sizeof(char), realsize, dest);
	}
	//Закрытие файлов
	fclose(src);
	fclose(dest);
	return true;
}