#pragma once
#include "Menu.h"

using namespace std;

//enum groupUser { admin, guest, developer, tester };
// правило1 - запрещено копировать файлы с этими расширениями
// правило2 - разрешено копировать файлы с этими расширениями
// правило3 - разрешено копировать файлы с этими расширениями предварительно зашифровав
// правило4 - запрещено копировать файлы с этими словами без шифрования

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

	//key = 0 - удаление пользователя, key = 1 - редактирование записи пользователя 
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

