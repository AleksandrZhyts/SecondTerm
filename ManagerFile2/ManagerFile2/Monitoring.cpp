#include "stdafx.h"

attemts Monitoring::Get_All_Attemts()
{
	ifstream file;
	file.open("log.txt");
	if (!file)
	{
		cout << "Failed to open 'log.txt' " << endl;
		return attemts();
	}
	string s;
	attemts ret;
	while (true)
	{
		file >> s;
		if (file.eof()) break;
		if (s == "[Error]") //got "[Error]" field?
		{
			ret.fail++;
		}
		if (s == "[Success]") //got "[Success]" field?
		{
			ret.suc++;
		}
	}
	file.close();
	return ret;
}

Monitoring::~Monitoring()
{
	is_init_complete = false;
}

bool Monitoring::Init_Data(char* nm, char* dat, char* fs, char* fd, bool suc, char* err)
{
	if (!nm || !dat || !fs || !fd || (suc == true && !err)) return false;
	if (strstr(nm, "[Error]") || strstr(dat, "[Error]") || strstr(fs, "[Error]") || strstr(fd, "[Error]") || strstr(err, "[Error]"))
		return false;
	if (strstr(nm, "[Success]") || strstr(dat, "[Success]") || strstr(fs, "[Success]") || strstr(fd, "[Success]") || strstr(err, "[Success]"))
		return false;
	_name = nm;
	_date_and_time = dat;
	_file_source = fs;
	_file_dest = fd;
	_success = suc;
	if (!_success)
	{
		_error_inf = err;
	}
	is_init_complete = true;
	return true;
}

bool Monitoring::Add_To_File()
{
	if(is_init_complete == false) return false;
	ofstream file("log.txt", ios::app);
	(_success) ? file << ("[Success]") : file << ("[Error]");
	file << endl <<_name << endl;
	file << _date_and_time << endl;
	file << _file_source << endl;
	file << _file_dest << endl;
	if (!_success)
		file << _error_inf << endl;
	file << endl;
	file.close();
	return true;
}

void Monitoring::Show_Stat()
{
	map<string, attemts> list;
	ifstream file;
	file.open("log.txt");
	if (!file)
	{
		cout << "Failed to open 'log.txt'" << endl;
		return;
	}
	string s;
	while (true)
	{
		getline(file, s);
		if (file.eof()) break;
		if (s == "[Error]") //got "[Error]" field?
		{
			getline(file, s);; //name
			for (auto it = list.begin(); it != list.end(); it++)
			{
				if (it->first == s) it->second.fail++; //name exists?
				continue;
			}
			attemts tmp;
			tmp.fail++;
			list.insert(pair<string, attemts>(s, tmp));
			continue;
		}
		if (s == "[Success]") //got "[Success]" field?
		{
			getline(file, s); //name
			for (auto it = list.begin(); it != list.end(); it++)
			{
				if (it->first == s) it->second.suc++; //name exists?
				continue;
			}
			attemts tmp;
			tmp.suc++;
			list.insert(pair<string, attemts>(s, tmp));
			continue;
		}
	}
	for (auto it = list.begin(); it != list.end(); it++)
	{
		cout << "Name:	<" << it->first << ">	All attemts: <" << it->second.fail + it->second.suc << ">	Seccessful attemts: <" << it->second.suc << ">" <<  endl;
	}
	file.close();
}

void Monitoring::Show_Fail_Stat()
{
	ifstream file;
	file.open("log.txt");
	if (!file)
	{
		cout << "Failed to open 'log.txt' " << endl;
		return;
	}
	map<string, int> list;
	string s;
	while (true)
	{
		getline(file, s);
		if (file.eof()) break;
		if (s == "[Error]") 
		{
			getline(file, s);getline(file, s);getline(file, s);getline(file, s);getline(file, s); //reads 5 strings until reaches (_error_inf)
			for (auto it = list.begin(); it != list.end(); it++)
			{
				if (it->first == s) //this error exists?
				{
					it->second++;
					continue;
				}
			}
			list.insert(pair<string, int>(s, 1)); //adds a new err
		}
	}
	file.close();
	while (!list.empty())
	{
		auto it_tmp = list.begin();
		for (auto it = list.begin(); it != list.end(); it++)
		{
			if (it_tmp->second > it->second) it_tmp = it;
		}
		cout <<"Error information:	<" << it_tmp->first << ">	Quantity: <" << it_tmp->second << ">" << endl; // Shows a line
		list.erase(it_tmp); // ...and deletes it
	}
}

void Monitoring::Show_Ratio()
{
	attemts atmts = Get_All_Attemts();
	if (atmts.fail == 0 && atmts.suc == 0)
		cout << "Nothing found!!! Perhaps, file 'log.txt' is empty!" << endl;
	cout << "Successful attemts:<" << atmts.suc << ">	(" << (double)((atmts.suc * 100) / (atmts.fail + atmts.suc)) << "%)" << endl;
	cout << "Failed attemts:	<" << atmts.fail << ">	(" << (double)((atmts.fail * 100) / (atmts.fail + atmts.suc)) << "%)" << endl;
}

void Monitoring::Show_Suc_Ettemts()
{
	multimap<string, string> list;
	ifstream file;
	file.open("log.txt");
	if (!file)
	{
		cout << "Failed to open 'log.txt'" << endl;
		return;
	}
	string nm, dat;
	while (true)
	{
		getline(file, nm);
		if (file.eof()) break;
		if (nm == "[Success]") //got "[Success]" field?
		{
			getline(file, nm); //name
			getline(file, dat); //date and time
			list.insert(pair<string, string>(nm, dat));
			continue;
		}
	}
	for (auto it = list.begin(); it != list.end(); it++)
	{
		cout << "NAme:	<" << it->first << ">	Date:	<" << it->second <<">" << endl;
	}
}

void Monitoring::Show_Fail_Ettemts()
{
	multimap<string, string> list;
	ifstream file;
	file.open("log.txt");
	if (!file)
	{
		cout << "Failed to open 'log.txt'" << endl;
		return;
	}
	string nm, inf;
	while (true)
	{
		getline(file, nm);
		if (file.eof()) break;
		if (nm == "[Error]") //got "[Success]" field?
		{
			getline(file, nm); //name
			getline(file, inf);getline(file, inf);getline(file, inf);getline(file, inf); // reads 4 strings to get 'error information'
			list.insert(pair<string, string>(nm, inf));
			continue;
		}
	}
	for (auto it = list.begin(); it != list.end(); it++)
	{
		cout << "Name:	<" << it->first << ">	Reason:	<" << it->second << ">" << endl;
	}
}


