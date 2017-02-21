#include "stdafx.h"
#include "Work_with_File.h"

Work_with_File::Work_with_File() {}

bool Work_with_File::createFile()
{
	string name;
	russianMessage("Введите имя файла: ");
	getline(cin, name);
	cin.get();
	
	fstream f;
	f.open( name.c_str(), ios::out | ios::in | ios::binary | ios::app);
	if (!f) 
	{
		russianMessage("Файл не открылся !!!");
		return false;
	}
	
	string s;
	int select = 1,
		_size;

	while (select)
	{
		russianMessage("Введите информацию для записи в файл: \n");
		getline(cin, s);
		
		_size =s.size();
		f.write((char*)&_size, sizeof(int));
		f.write(s.c_str(), _size * sizeof(char));
		
		russianMessage("Хотите продолжить 1 - да; 0 - нет : \n");
		cin >> select;
		cin.get();
	}
	
	f.close();
	return true;
}

bool Work_with_File::removeFile()
{
	char Name[50];
	russianMessage("Введите имя файла: ");
	cin >> Name;
	return (remove(Name) == 0);
}

bool Work_with_File::renameFile()
{
	char oldName[50], newName[50];
	cout << "Enter old filename: ";
	cin >> oldName;
	cout << "Enter new filename: ";
	cin >> newName;

	return (rename(oldName, newName) == 0);
}

bool Work_with_File::copyFile(char *source, char *destination)
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

bool Work_with_File::move_File()
{
	char answer[20];
	char source[_MAX_PATH];
	char destination[_MAX_PATH];

	cout << "\nEnter file name to copy : ";
	cin.getline(source, _MAX_PATH);

	if (_access(source, 0) == -1)
	{
		cout << "\nFile name isn't correct\n";
		return false;
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
			return false;
		}
		else if (strcmp(answer, "1"))
		{
			cout << "\nEnter incorect\n";
			return false;
		}
		if (_access(destination, 02) == -1)
		{
			cout << "\nNo access to records\n";
			return false;
		}
	}
	if (!this->copyFile(source, destination))
		cout << "\nError working with file\n";
	return true;
}

bool Work_with_File::printFile()
{
	char source[_MAX_PATH];

	cout << "\nEnter file name to print : ";
	cin.getline(source, _MAX_PATH);

	if (_access(source, 0) == -1)
	{
		cout << "\nFile name isn't correct\n";
		return false;
	}

	fstream f;
	f.open( source, ios::out | ios::in | ios::binary | ios::app);
	if (!f) 
	{
		russianMessage("Файл не открылся !!!");
		return false;
	}

	char s[200];
	int _size;

	while (f.read((char*)&_size, sizeof(int))) 
	{
		f.read((char*)&s, _size*sizeof(char));
		
		s[_size] = '\0';
		cout << s << endl;
	}

	f.close();
	return true;
}

Work_with_File::~Work_with_File() {}
