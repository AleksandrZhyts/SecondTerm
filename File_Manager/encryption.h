#pragma once
//#include <iostream>
//#include <string>
//#include "hash.h"
class encryption
{
public:
	bool encoding(const string, string);
	bool decoding(string, string);
	string hash(const string);
	bool check_hash(const string);
private:
	string _inString;
	string _outString;

};