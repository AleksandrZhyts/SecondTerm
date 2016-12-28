#include "stdafx.h"

//������� ����������� �����
bool CopyFile(char *source, char *destination)
{
	const int size = 65536;
	FILE *src, *dest;
	//�������� �����
	if (fopen_s(&src, source, "rb"))
	{
		return false;
	}
	//��������� ����������� �����
	//int handle = _fileno(src);
	//��������� ������ ��� ������
	char *data = new char[size];
	if (!data)
	{
		return false;
	}
	//�������� �����, ���� ����� ������������� �����������
	if (fopen_s(&dest, destination, "wb"))
	{
		delete[]data;
		return false;
	}
	int realsize;
	while (!feof(src))
	{
		//������ ������ �� �����
		realsize = fread(data, sizeof(char), size, src);
		//������ ������ � ����
		fwrite(data, sizeof(char), realsize, dest);
	}
	//�������� ������
	fclose(src);
	fclose(dest);
	return true;
}