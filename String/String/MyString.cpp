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

bool MyString::bracket_location()
{
	int count_circle_brackets = 0,
		count_figure_brackets = 0,
		count_square_brackets = 0;
	int* arr1 = new int[_len];
	int* arr2 = new int[_len];
	int* arr3 = new int[_len];

	unsigned int i = 0;
	while ((_s[i] != ';') && (i < (_len + 1)))
	{
		switch (_s[i])
		{
		case '(': arr1[count_circle_brackets++] = i;
				  break;
		case '{': arr2[count_figure_brackets++] = i;
				  break;
		case '[': arr3[count_square_brackets++] = i;
				  break;
		case ')':
		{
			if ((count_circle_brackets == 0) ||
				(count_figure_brackets > 0) && (arr2[count_figure_brackets - 1] > arr1[count_circle_brackets - 1]) ||
				(count_square_brackets > 0) && (arr3[count_square_brackets - 1] > arr1[count_circle_brackets - 1]))
			{
				for (unsigned int j(0); j <= i; j++)
				{
					std::cout << _s[j];
				}
				return false;
			}
			else count_circle_brackets--;
			break;
		}
		case '}':
		{
			if ((count_figure_brackets == 0) ||
				(count_circle_brackets > 0) && (arr1[count_circle_brackets - 1] > arr2[count_figure_brackets - 1]) ||
				(count_square_brackets > 0) && (arr3[count_square_brackets - 1] > arr2[count_figure_brackets - 1]))
			{
				for (unsigned int j(0); j <= i; j++)
				{
					std::cout << _s[j];
				}
				return false;
			}
			else count_figure_brackets--;
			break;
		}
		case ']':
		{
			if ((count_square_brackets == 0) ||
				(count_circle_brackets > 0) && (arr1[count_circle_brackets - 1] > arr3[count_square_brackets - 1]) ||
				(count_figure_brackets > 0) && (arr2[count_figure_brackets - 1] > arr3[count_square_brackets - 1]))
			{
				for (unsigned int j(0); j <= i; j++)
				{
					std::cout << _s[j];
				}
				return false;
			}
			else count_square_brackets--;
			break;
		}
		default:
			break;
		}
		i++;
	}
	if (count_circle_brackets || count_figure_brackets || count_square_brackets)
	{
		std::cout << _s;
		return false;
	}
	else return true;
}

std::ostream& operator<<(std::ostream& os, const MyString& st)
{
	return os << st._s;
}

std::istream& operator >> (std::istream& is, const MyString& st)
{
	std::cout << "Enter string : ";
	is.getline(st._s, 80);
	return is;
}

MyString::~MyString()
{
	delete[] _s;
	_s = NULL;
}