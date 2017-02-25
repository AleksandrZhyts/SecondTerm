#pragma once

class UserPolicy 
{
public:
	UserPolicy();
	
	void init_map_policy();

	//0 - запрет копирования, 1 - копирование с шифрованием,2 - обычное копирование
	int isUserCopyFile(string, const int&);

	~UserPolicy();

private:
	std::map<string, vector<string>> _policy;
};

