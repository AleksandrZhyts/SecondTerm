#pragma once

class UserPolicy 
{
public:
	UserPolicy();
	
	void init_map_policy();

	//0 - ������ �����������, 1 - ����������� � �����������,2 - ������� �����������
	int isUserCopyFile(string, const int&);

	~UserPolicy();

private:
	std::map<string, vector<string>> _policy;
};

