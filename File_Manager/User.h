#pragma once
#include "Menu.h"

using namespace std;

//enum groupUser { admin, guest, developer, tester };
// �������1 - ��������� ���������� ����� � ����� ������������
// �������2 - ��������� ���������� ����� � ����� ������������
// �������3 - ��������� ���������� ����� � ����� ������������ �������������� ����������
// �������4 - ��������� ���������� ����� � ����� ������� ��� ����������

struct member
{
	string name;
	string password;
	int user_Policy;
};

class User
{
public:
	User();

	void enterUser(int key = 0);

	void writeUser(fstream&);

	void addUserDb();

	//key = 0 - �������� ������������, key = 1 - �������������� ������ ������������ 
	void editUserDb(int key = 0);
	
	void createDb();

	bool is_User_Db();

	void registerUser();

	member& getUser();
	
	//void entranceSystem();

	~User();
private:
	fstream f;
	member _user;
};

