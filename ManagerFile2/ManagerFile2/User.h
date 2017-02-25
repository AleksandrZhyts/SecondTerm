#pragma once

using namespace std;

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

	//key = 0 - ввод имя+пароль+статус, 1 - ввод имя+пароль, 2 - ввод имя
	void enterUser(int key = 0);

	void writeUser(fstream&);

	void addUserDb();

	//key = 0 - удаление пользователя, key = 1 - редактирование записи пользователя 
	void editUserDb(int key = 0);
	
	void createDb();

	bool is_User_Db();

	void registerUser();

	member& getUser();

	~User();
private:
	fstream f;
	member _user;
};

