#pragma once
#include "stdafx.h"

using namespace std;

struct attemts
{
	double suc = 0, fail = 0; 
};
class Monitoring
{
public:
	Monitoring() { _success = 0, is_init_complete = 0; }
	~Monitoring();
	bool Init_Data(char* nm, char* dat, char* fs, char* fd, bool suc, char* err);
	bool Get_Status() { return is_init_complete; } //returns true if all data is completed (use it when you are going to save a new data to file)
	bool Add_To_File();
	void Show_Stat();
	void Show_Fail_Stat();
	void Show_Ratio();
	void Show_Suc_Ettemts();
	void Show_Fail_Ettemts();
private:
	string _name, _date_and_time, _file_source, _file_dest, _error_inf;
	bool _success, is_init_complete;
	attemts Get_All_Attemts();
};

