/*Задание 5.
Создайте программу «Простейший файловый менеджер»:
1. Создание нового файла в текущем каталоге;
2. Удаление файла из текущего каталога;
3. Переименование файла в текущем каталоге;
4. Перемещение файла из текущего каталога в указанный
пользователем каталог;
5. Вывод содержимого указанного пользователем файла
из текущего каталога на экран
*/
#include "stdafx.h"

using namespace std;

//Создание нового файла в текущем каталоге
void CreateFile();

//Удалить существующий файл из текущего каталога
void RemoveFile();

//Переименовать существующий файл в текущем каталоге
void RenameFile();

// Перемещение файла из текущего каталога в указанный пользователем каталог
void MoveFile();

//Вывод содержимого указанного пользователем файла из текущего каталога на экран
void PrintFile();

int main()
{
	cout << "Please, select preffer number...\n";
	char ch;
	do {
		cout << "\n1 - Create\n";
		cout << "2 - Remove\n";
    	cout << "3 - Rename\n";
		cout << "4 - Move\n";
		cout << "5 - Print\n";
		cout << "0 - Exit\n\n";
		cin >> ch;
		cin.get();

		switch (ch)
		{
		case '1':
			CreateFile();
			break;
		case '2':
			RemoveFile();
			break;
		case '3':
			RenameFile();
			break;
		case '4':
			MoveFile();
			break;
		case '5':
			PrintFile();
			break;
		}
	} while (ch != '0'); 
	
	return 0;
}

void CreateFile()
{
	char Name[50];
	cout << "Enter filename: ";
	cin >> Name;
	cin.get();
	FILE *f;

	if (fopen_s(&f, Name, "w"))
	{
		perror("Open");
		return;
	}

	char s[500];
	cout << "Enter information to write in file: \n";
	cin.getline(s, 500);
	fputs(s, f);

	fclose(f);
	cout << "Ok.\n\n";
}

//Удалить существующий файл из текущего каталога
void RemoveFile()
{
	char Name[50];
	cout << "Enter filename: ";
	cin >> Name;
	if (remove(Name) != 0)
		cout << "Error!\n Couldn't remove file.	Check filename.\n";
	else cout << "Ok.\n";
}

//Переименовать существующий файл в текущем каталоге
void RenameFile()
{
	char oldName[50], newName[50];
	cout << "Enter old filename: ";
	cin >> oldName;
	cout << "Enter new filename: ";
	cin >> newName;
	
	if (rename(oldName, newName) != 0)
		cout << "Error!\n Couldn't rename file.	Check old and new filename.\n\n";
	else cout << "Ok.\n\n";
}

// Перемещение файла из текущего каталога в указанный пользователем каталог
//Функция копирования файла
bool CopyFile(char *source, char *destination)
{
	const int size = 65536;
	FILE *src, *dest;
	if (fopen_s(&src, source, "rb")) return false;
	
	char *data = new char[size];
	
	if (!data) return false;
	
	if (fopen_s(&dest, destination, "wb"))
	{
		delete[]data;
		return false;
	}
	
	int realsize;
	while (!feof(src))
	{
		realsize = fread(data, sizeof(char), size, src);
		fwrite(data, sizeof(char), realsize, dest);
	}
	
	fclose(src);
	fclose(dest);
	return true;
}

void MoveFile()
{
	char answer[20];
	char source[_MAX_PATH];
	char destination[_MAX_PATH];
	
	cout << "\nEnter file name to copy : ";
	cin.getline(source, _MAX_PATH);
	
	if (_access(source, 0) == -1)
	{
		cout << "\nFile name isn't correct\n";
		return;
	}
	cout << "\nEnter path and file name to copy : ";
	cin.getline(destination, _MAX_PATH);
	
	if (_access(destination, 0) == 0)
	{
		cout << "\nThis file already exists overwrite it(1 - Yes / 2 - No) ? \n";
		cin.getline(answer, 20);
		if (!strcmp(answer, "2"))
		{
			cout << "\nOperation canceled\n";
			return;
		}
		else if (strcmp(answer, "1")) {
			cout << "\nEnter incorect\n";
			return;
		}
		if (_access(destination, 02) == -1)
		{
			cout << "\nNo access to records\n";
			return;
		}
	}
	if (!CopyFile(source, destination))	cout << "\nError working with file\n";
	else cout << "Ok.\n\n";
}

//Вывод содержимого указанного пользователем файла из текущего каталога на экран
void PrintFile()
{
	char source[_MAX_PATH];
	
	cout << "\nEnter file name to print : ";
	cin.getline(source, _MAX_PATH);

	if (_access(source, 0) == -1)
	{
		cout << "\nFile name isn't correct\n";
		return;
	}

	FILE *f;
	
	if (fopen_s(&f, source, "r"))
	{
		perror("Open");
		return;
	}
	char s1[200] = { 0 };
		
	while (!feof(f))
	{
		fgets(s1, 200, f);
		cout << s1 << endl;
	}

	fclose(f);
}
		