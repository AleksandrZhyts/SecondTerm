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

	//�������� ������ ����� � ������� ��������
	bool createFile(string&);

	//������� ������������ ���� �� �������� ��������
	bool removeFile(string);

	//������������� ������������ ���� � ������� ��������
	bool renameFile(string, string);

	//�������� �����  �����
	bool copyFile(string, string);

	//����������� ����� �� �������� �������� � ��������� ������������� �������
	bool move_File(string, string);

	//����� ����������� ���������� ������������� ����� �� �������� �������� �� �����
	bool printFile(string);

	~Work_with_File();

private:
	string fileSource;
	string fileDestination;
};

