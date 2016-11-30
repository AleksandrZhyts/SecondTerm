#include "stdafx.h"
#include "MyString.h"

MyString::MyString(unsigned int size = 80)
{
	_len = size;
	_s = new char[_len];
	
}

MyString::MyString(char *str)
{
	_len = strlen(str);
	_s = new char[_len + 1];
	strcpy_s(_s, _len + 1, str);	
}

MyString::MyString(const MyString& st)
{
	_len = st._len;
	_s = new char[_len + 1];
	strcpy_s(_s, _len + 1, st._s);
}

const char* MyString::getString() 
{ 
	return _s; 
}

char& MyString:: operator[](unsigned int i)
{
	if (_s != NULL && i < _len)
		return _s[i];
	if (_s == NULL) throw "You can not take the index, string is empty ";
	else throw "Wrong index. More than size string";
}

bool MyString::operator<(const MyString& st) const
{
	if (strcmp(_s, st._s) < 0 ) return true;
	else return false;
}

bool MyString::operator>(const MyString& st) const
{
	if (strcmp(_s, st._s) > 0) return true;
	else return false;
}

bool MyString::operator==(const MyString& st) const
{
	if (strcmp(_s, st._s) == 0) return true;
	else return false;
}

const MyString MyString::operator+(const MyString& st)
{
	char *temp = new char[_len + st._len + 1];                    
	strcpy_s(temp, _len + 1, _s);
	strcat_s(temp, strlen(temp)+st._len+1, st._s);
	MyString str(temp);
	
	delete[] temp;
	return str;
}

void MyString::operator+=(const MyString& st)
{
	char *temp = new char[_len + 1];
	strcpy_s(temp, _len + 1, _s);
	
	this->~MyString();

	_len += st._len;
	_s = new char[_len + 1];
	
	strcpy_s(_s, strlen(temp) + 1, temp);
	strcat_s(_s, _len + 1, st._s);

	delete[] temp;
	
}

void MyString::operator=(const MyString& st)
{
	this->~MyString();
	
	_len = st._len;
	_s = new char[_len+1];
	strcpy_s(_s, _len + 1, st._s);
}

unsigned int MyString::getLen()
{
	return _len;
}

MyString::~MyString()
{
	delete[] _s;
	_s = NULL;
}