#include "stdafx.h"
//#include "UserPolicy.h"

UserPolicy::UserPolicy(){}

void UserPolicy::init_map_policy()
{
	FILE *f_Policy;
	if (fopen_s(&f_Policy, "Policy.txt", "r"))
	{
		russianMessage("Файл policy не открылся !!!");
		exit(1);
	}

	char str[200],
		 number_Rule[30],
		 value_Rule[100];

	string str_number_Rule,
		   str_value_Rule;
	vector<string> vec_value_Rule;
	//vec_value_Rule.resize(15);

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
		_policy.insert(std::pair<string,vector<string>>(str_number_Rule, vec_value_Rule));  //{ str_number_Rule, vec_value_Rule }
		vec_value_Rule.clear();
	}
	fclose(f_Policy);
}

int UserPolicy::isUserCopyFile(string filename, const int& us_Policy) 
{
	int nWordEnd = filename.find('.'),
		value_copy = 0,
		i = 0;

	string sub_string = filename.substr(nWordEnd, filename.size()-1);
	
	map<string, vector<string>>::iterator it = _policy.begin();
	
	FILE *f;
	if (fopen_s(&f, filename.c_str(), "r"))
	{
		russianMessage("Файл не открылся !!!");
		return value_copy;
	}
	char str[200];
	string str_curent,
		   str_number_Rule;
	 
	if (us_Policy == 1) str_number_Rule = "guest.rule1";
	if (us_Policy == 2) str_number_Rule = "developer.rule1";
	if (us_Policy == 3) str_number_Rule = "tester.rule1";
	
	it = _policy.find(str_number_Rule);
	
	for (i = 0; i < it->second.size() && it->second[i].compare(sub_string); i++);
	if (i < it->second.size()) return value_copy;//monitoring

	it++;
	for (i = 0; i < it->second.size() && it->second[i].compare(sub_string); i++);
	if (i >= it->second.size()) return value_copy;  //monitoring 

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
			return value_copy; //monitoring
		}
	}
		
	fclose(f);
	if (value_copy == 0) value_copy = 2;
	return value_copy;
}

UserPolicy::~UserPolicy()
{}
