#pragma once
//#include "stdafx.h"
#include "User.h"

class Work_with_File 
{
public:
	Work_with_File();

	//�������� ���� ������ �������������
	//void createDb();

	//�������� ������ ����� � ������� ��������
	bool createFile();

	//������� ������������ ���� �� �������� ��������
	bool removeFile();

	//������������� ������������ ���� � ������� ��������
	bool renameFile();

	//�������� �����  �����
	bool copyFile(char*, char*);

	//����������� ����� �� �������� �������� � ��������� ������������� �������
	bool move_File();

	//����� ����������� ���������� ������������� ����� �� �������� �������� �� �����
	bool printFile();

	~Work_with_File();

};

