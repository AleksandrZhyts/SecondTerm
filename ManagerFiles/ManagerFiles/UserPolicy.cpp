#include "stdafx.h"

struct member;

UserPolicy::UserPolicy(){}

void UserPolicy::init_map_policy()
{
	FILE *f_Policy;
	if (fopen_s(&f_Policy, "Policy.txt", "r"))
	{
		russianMessage("���� policy �� �������� !!!");
		exit(1);
	}

	char str[200],
		 number_Rule[30],
		 value_Rule[100];

	string str_number_Rule,
		   str_value_Rule;
	vector<string> vec_value_Rule;
	
	int i = 0,
		j = 0;

	while (!feof(f_Policy))
	{
		fgets(str, 200, f_Policy);

		i = 0;
		j = 0;

		while (i < (strlen(str) - 1) && (str[i] != '='))
			number_Rule[j++] = str[i++];

		number_Rule[j] = '\0';
		str_number_Rule = number_Rule;

		
		while (i < (strlen(str) - 1))
		{
			i++; j = 0;
			while (i < (strlen(str) - 1) && str[i] != ';' && str[i] != ',')
				value_Rule[j++] = str[i++];

			if (j)
			{
				value_Rule[j] = '\0';
				str_value_Rule = value_Rule;
				vec_value_Rule.push_back(str_value_Rule);
			}
		}
		_policy.insert(std::pair<string,vector<string>>(str_number_Rule, vec_value_Rule));  
		vec_value_Rule.clear();
	}
	fclose(f_Policy);
}

int UserPolicy::isUserCopyFile(string filename, const member& us_Policy)
{
	int nWordEnd = filename.find('.'),
		value_copy = 0,
		i = 0;
	bool is_file_shifr = false;

	string sub_string = filename.substr(nWordEnd, filename.size()-1);
	
	map<string, vector<string>>::iterator it = _policy.begin();
	
	Hash _hash;

	if (_hash.is_File_Shifr(filename))
	{
		_hash.shifrFile(filename, true);
		is_file_shifr = true;
	}

	FILE *f;
	if (fopen_s(&f, filename.c_str(), "r"))
	{
		russianMessage("���� �� �������� !!!");
		return value_copy;
	}
	char str[200];
	string str_curent,
		   str_number_Rule;
	 
	if (us_Policy.user_Policy == 1) str_number_Rule = "guest.rule1";
	if (us_Policy.user_Policy == 2) str_number_Rule = "developer.rule1";
	if (us_Policy.user_Policy == 3) str_number_Rule = "tester.rule1";

	Monitoring monitoring;
	time_t t = time(NULL);
	char _data_time[30];
	ctime_s(_data_time, 30, &t);

	
	it = _policy.find(str_number_Rule);
	
	for (i = 0; i < it->second.size() && it->second[i].compare(sub_string); i++);
	if (i < it->second.size()) 
	{
		fclose(f);
		if (is_file_shifr) _hash.shifrFile(filename);
		
		//monitoring
		monitoring.Init_Data(us_Policy.name, _data_time, filename, filename, false, "Violated the first rule of backup policies");
		if (monitoring.Get_Status()) monitoring.Add_To_File();
	
		return value_copy;   
	}

	it++;
	for (i = 0; i < it->second.size() && it->second[i].compare(sub_string); i++);
	if (i >= it->second.size())
	{
		fclose(f);
		if (is_file_shifr) _hash.shifrFile(filename);

		//monitoring
		monitoring.Init_Data(us_Policy.name, _data_time, filename, filename, false, "Violated the second rule of backup policies");
		if (monitoring.Get_Status()) monitoring.Add_To_File();

		return value_copy;  
	}

	it++;
	for (i = 0; i < it->second.size() && it->second[i].compare(sub_string); i++);
	if (i < it->second.size()) value_copy = 1; //monitoring

	it++;
	while (!feof(f))
	{
		fgets(str, 200, f);
		str[strlen(str)] = '\0';
		str_curent = str;
		for (i = 0; i < it->second.size() && (str_curent.find(it->second[i]) == -1); i++);
		if (i < it->second.size()) value_copy = 1;//monitoring
	}
		
	fseek(f, 0, 0);

	it++;
	while (!feof(f))
	{
		fgets(str, 200, f);
		str[strlen(str)] = '\0';
		str_curent = str;
		for (i = 0; i < it->second.size() && (str_curent.find(it->second[i]) == -1); i++);
		if (i < it->second.size()) 
		{
			value_copy = 0;
			fclose(f);
			if (is_file_shifr) _hash.shifrFile(filename);

			//monitoring
			monitoring.Init_Data(us_Policy.name, _data_time, filename, filename, false, "Violated the fifth rule of backup policies");
			if (monitoring.Get_Status()) monitoring.Add_To_File();

			return value_copy; 
		}
	}
		
	fclose(f);
	if (value_copy == 0) value_copy = 2;
	
	if (is_file_shifr) _hash.shifrFile(filename);
	return value_copy;
}

UserPolicy::~UserPolicy()
{}
