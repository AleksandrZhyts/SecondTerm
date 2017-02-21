#include "stdafx.h"
#include "User.h"

User::User()
{
	//расшифровываем DB
	f.open("Db.txt", ios::out | ios::in | ios::binary | ios::app);
	if (!f)
	{
		russianMessage("Файл не открылся !!!");
		exit(1);
	}
}

void User::enterUser(int key)
{
	switch (key)
	{
	case 0:
		russianMessage("\nВведите имя пользователя:\n");
		getline(cin,_user.name);
	
		russianMessage("\nВведите пароль:\n");
		getline(cin,_user.password);
		
		//шифруем пароль

		russianMessage("\nВведите приоритет: 0 - admin, 1 - guest, 2 - developer, 3 - tester:\n");
		cin >> _user.user_Policy;
		break;
	case 1:
		russianMessage("\nВведите имя пользователя:\n");
		getline(cin,_user.name);
	
		russianMessage("\nВведите пароль:\n");
		getline(cin,_user.password);
		
		//шифруем пароль
		break;
	case 2:
		russianMessage("\nВведите имя пользователя:\n");
		getline(cin,_user.name);
		break;
	}
}

void User::writeUser(fstream& f)
{
	int _size = _user.name.size();
	f.write((char*)&_size, sizeof(int));
	f.write(_user.name.c_str(), _size * sizeof(char));

	_size = _user.password.size();
	f.write((char*)&_size, sizeof(int));
	f.write(_user.password.c_str(), _size * sizeof(char));

	f.write((char*)&_user.user_Policy, sizeof(int));

	f.seekg(f.tellp());
}

void User::addUserDb()
{
	enterUser();
	
	if (!is_User_Db()) writeUser(f);
	else russianMessage("\nЭто имя пользователя уже зарегистрировано\n");
}

void User::editUserDb(int key)
{
	fstream f2;
	f2.open("TempDb.txt", ios::out | ios::in | ios::binary | ios::app);
	if (!f)
	{
		russianMessage("Файл не открылся !!!");
		exit(1);
	}
	
	enterUser(2);

	member m;
	int _size;
	char s[100];
	bool is_user = false;

	f.seekg(0);

	while (f.read((char*)&_size, sizeof(int)))
	{
		f.read((char*)s, _size * sizeof(char));
		s[_size] = '\0';
		m.name = s;

		f.read((char*)&_size, sizeof(int));
		f.read((char*)s, _size * sizeof(char));
		s[_size] = '\0';
		m.password = s;

		f.read((char*)&m.user_Policy, sizeof(int));

		if (!_user.name.compare(m.name))  
		{
			is_user = true;
			
			if (key == 0) continue;
			
			russianMessage("\nВведите новые данные\n");
			enterUser();
				
			writeUser(f2);
		}
		else
		{
			_size = m.name.size();
			f2.write((char*)&_size, sizeof(int));
			f2.write(m.name.c_str(), _size * sizeof(char));

			_size = m.password.size();
			f2.write((char*)&_size, sizeof(int));
			f2.write(m.password.c_str(), _size * sizeof(char));

			f2.write((char*)&m.user_Policy, sizeof(int));
		}
	}

	f.close();
	f2.close();
	
	remove("Db.txt");
	Work_with_File wf;
	wf.copyFile("TempDb.txt", "Db.txt");
	remove("TempDb.txt");

	f.open("Db.txt", ios::out | ios::in | ios::binary | ios::app);
	if (!f)
	{
		russianMessage("Файл не открылся !!!");
		exit(1);
	}

	if (!is_user) russianMessage("Неверное имя пользователя или пароль");
}

void User::createDb()
{
	int select = 1;

	while (select)
	{
		addUserDb();

		russianMessage("Хотите ещё добавить пользователя 1 - да; 0 - нет : \n");
		cin >> select;
		cin.get();
	}
}

void User::registerUser()
{
	string name,
		   password1,
		   password2;
	
	russianMessage("\nВведите имя пользователя:\n");
	getline(cin,_user.name);

	do 
	{
		russianMessage("\nВведите пароль:\n");
		getline(cin,password1);

		russianMessage("\nПовторите пароль:\n");
		getline(cin,password2);

		
		if (password1.compare(password2))
			russianMessage("\nПароли не совпадают\n");
		else break;
	} while (1);

		//шифруем пароль

	_user.password = password1;
	
	_user.user_Policy = 1;

	if (!is_User_Db()) writeUser(f);
	else russianMessage("\nЭто имя пользователя уже зарегистрировано\n");
}

bool User::is_User_Db()
{
	member m;
	int _size;
	char s[100];
	
	f.seekg(0);
	
	while (f.read((char*)&_size, sizeof(int)))   
	{
		f.read((char*)s, _size * sizeof(char));
		s[_size] = '\0';
		m.name = s;
		
		f.read((char*)&_size, sizeof(int));
		f.read((char*)s, _size * sizeof(char));
		s[_size] = '\0';
		m.password = s;
		
		f.read((char*)&m.user_Policy, sizeof(int));
		
		if (!_user.name.compare(m.name) && !_user.password.compare(m.password))
		{
			_user.user_Policy = m.user_Policy;
			f.clear();
			return true;
		}
	}

	f.clear();
	return false;
}

member& User::getUser()
{
	return _user;
}

User::~User()
{
	//Зашифровываем DB
	f.close();
}
