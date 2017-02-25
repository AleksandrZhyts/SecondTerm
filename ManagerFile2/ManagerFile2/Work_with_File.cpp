#include "stdafx.h"
//#include "Work_with_File.h"

using namespace std;

Work_with_File::Work_with_File() {}

bool Work_with_File::setFileSource()
{
	russianMessage("\n������� ���� � ��� ����� ���������: \n");
	getline(cin, fileSource);

	if (_access(fileSource.c_str(), 0) == -1)
	{
		russianMessage("\n�������� ��� ����� ��� ����\n"); //monitoring ??
		return false;
	}	
	return true;
}

string& Work_with_File::getFileSource()
{
	return fileSource;
}
	
void Work_with_File::setFileDestination()
{
	russianMessage("\n������� ���� � ��� ����� �����: \n");
	getline(cin,fileDestination);
}

string& Work_with_File::getFileDestination()
{
	return fileDestination;
}

bool Work_with_File::createFile(string& name)
{
	FILE *f;
	if (fopen_s(&f, name.c_str(), "a"))
	{
		russianMessage("\n���� �� �������� !!!\n");
		exit(1);
	}

	char str[200];
	int select;

	do
	{
		russianMessage("������� ���������� ��� ������ � ����: \n");
		cin.getline(str, 200);
		strcat_s(str,"\n");
		fputs(str, f);
		
		russianMessage("������ ���������� ����� ���������� 1 - ��; 0 - ��� : \n");
		cin >> select;
		cin.get(); 
	} while (select);
	
	fclose(f);
	return true;
}

bool Work_with_File::removeFile(string name)
{
	return (remove(name.c_str()) == 0);
}

bool Work_with_File::renameFile(string oldName, string newName)
{
	return (rename(oldName.c_str(), newName.c_str()) == 0);
}

bool Work_with_File::copyFile(string source, string destination)
{
	const int size = 65536;
	FILE *src, *dest;
	if (fopen_s(&src, source.c_str(), "rb")) return false;

	char *data = new char[size];

	if (!data) return false;

	if (fopen_s(&dest, destination.c_str(), "wb"))
	{
		fclose(src);
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

bool Work_with_File::move_File(string source, string destination)
{
	char answer[20];

	if (_access(destination.c_str(), 0) == 0)
	{
		russianMessage("\n���� � ����� ������ ��� ����������. ������ ������������ (1- ��/2 - ���)?\n");
		cin.getline(answer, 20);
		if (!strcmp(answer, "2"))
		{
			russianMessage("\n�������� ��������!\n");
			return false;
		}
		else if (strcmp(answer, "1"))
		{
			russianMessage("\n�� ������ ����!\n");
			return false;
		}
		if (_access(destination.c_str(), 02) == -1)
		{
			russianMessage("\n��� ������� � ������ :\n");
			return false;
		}
	}

	if (!this->copyFile(source, destination))
		russianMessage("\n������ ��� ������ � ������:\n");
	return true;
}

bool Work_with_File::printFile(string source)
{
	FILE *f;
	if (fopen_s(&f, source.c_str(), "r"))
	{
		russianMessage("\n���� �� �������� !!!\n");
		exit(1);
	}

	char str[200];
	
	while (!feof(f))
	{
		fgets(str, 200, f);
		str[strlen(str)] = '\0';
		cout << str << endl;
	}
	fclose(f);
	return true;
}

Work_with_File::~Work_with_File() {}
