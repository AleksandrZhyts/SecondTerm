#include "stdafx.h"
#include "MyString.h"

MyString::MyString() :_len(0)
{
	_s = new char[1];
	*_s = '\0';
}

MyString::MyString(char *st)
{
	_len = strlen(st);
	_s = new char[_len + 1];
	strcpy_s(_s, _len + 1, st);	
}

MyString::MyString(const MyString& st)
{
	if (_len) delete[] _s;
	
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
	return (strcmp(_s, st._s) < 0 );
}

bool MyString::operator>(const MyString& st) const
{
	return (strcmp(_s, st._s) > 0);
}

bool MyString::operator==(const MyString& st) const
{
	return (strcmp(_s, st._s) == 0);
}

bool MyString::operator!=(const MyString& st) const
{
	return (strcmp(_s, st._s) != 0);
}

MyString& MyString::operator+(const MyString& st)
{
	char *temp = new char[_len + st._len + 1];                    
	strcpy_s(temp, _len + 1, _s);
	strcat_s(temp, strlen(temp) + st._len + 1, st._s);
	
	MyString *str  = new MyString(temp);
	
	delete[] temp;
	return *str;
}

void MyString::operator+=(const MyString& st)
{
	*this = this->operator+(st);
}

void MyString::operator=(const MyString& st)
{
	delete[] _s;

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
		count_square_brackets = 0,
		*arr1 = new int[_len],
	    *arr2 = new int[_len],
	    *arr3 = new int[_len];

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
	is.getline(st._s, 200);
	return is;
}

MyString::~MyString()
{
	delete[] _s;
	_s = NULL;
}

BitString::BitString() :_len(0)
{
	_s = new char[1];
	*_s = '\0';
}

BitString::BitString(char* st)
{
	unsigned int index = 0;
	
	_len = strlen(st);
	_s = new char[_len + 1];

	while (*(st + index) != '\0' && (*(st + index) == '0' || *(st + index) == '1'))
		_s[index++] = st[index];
	
	_s[index] = '\0';
	
	if (index < strlen(st))
	{
		_len = 0;
		*_s = '\0';
	} 
	else 
		// fill in the missing line 0 to 8 , 16, or 32 bits
		if (_len != 8 && _len != 16 && _len != 32 && _len < 64)
		{
			unsigned int size = 8 * (_len < 8) + 16 * (_len > 8 && _len < 16) + 
								32 * (_len > 16 && _len < 32) + 64 * (_len > 32 && _len < 64);

			char* temp = new char[_len + 1];
			strcpy_s(temp, _len + 1, _s);

			delete[] _s;

			_s = new char[size + 1];

			for (unsigned int i = 0; i < size - _len; i++)
				_s[i] = '0';

			_s[size - _len] = '\0';

			strcat_s(_s, size + 1, temp);

			_len = size;

			delete[] temp;
		}
}

BitString::BitString(const BitString& st)
{
	if (_len) delete[] _s;

	_len = st._len;
	_s = new char[_len + 1];

	strcpy_s(_s, _len + 1, st._s);
}

void BitString::change_sign()
{
	bool flag = true;
	for (int i(_len - 1); i >= 0; i--)
	{
		_s[i] = (char)(49 - (_s[i] == '1'));  
		
		if (_s[i] == '0')
		{
			_s[i] = (char)(48 + flag);
			flag = false;
		}
		else _s[i] = (char)(49 - flag);
	}
}

void BitString::operator = (const BitString& st)
{
	delete[] _s;

	_len = st._len;
	_s = new char[_len + 1];
	strcpy_s(_s, _len + 1, st._s); 
}

BitString& BitString::operator+(const BitString& st)
{
	bool flag = (st._len > _len);
	unsigned int size = flag ? st._len : _len;
	
	char *temp1 = new char[size + 1],
		 *temp2 = new char[size + 1],
		 *temp3 = new char[size + 1];

	if (st._len != _len)
	{
		if (flag)
		{
			for (unsigned int i = 0; i < size - _len; i++)
				temp1[i] = (char)(48 + (*_s == 1));              //fill 1 or 0

			temp1[size - _len] = '\0';
			strcat_s(temp1, size + 1, _s);
			strcpy_s(temp2, size + 1, st._s);
		}
		else
		{
			for (unsigned int i = 0; i < size - st._len; i++)
				temp1[i] = (char)(48 + (*st._s == 1));          //fill 1 or 0

			temp1[size - st._len] = '\0'; 
			strcat_s(temp1, size + 1, st._s);
			strcpy_s(temp2, size + 1, _s);
		}	
	}
	else
	{
		strcpy_s(temp1, size + 1, _s);
		strcpy_s(temp2, size + 1, st._s);
	}
	temp3[size] = '\0';
	flag = false;
	
	for (int i(size - 1); i >= 0; i--)
	{
		if ((temp1[i] == '0') && (temp2[i] == '0') || (temp1[i] == '1') && (temp2[i] == '1'))
		{
			temp3[i] = (char)(48 + flag);
			flag = false;
		}
		else temp3[i] = (char)(49 - flag);
		
		if ((i < size - 1) && (temp1[i + 1] == '1') && (temp2[i + 1] == '1'))
		{
			flag = (temp3[i] == '1');
			temp3[i] = (char)(49 - (temp3[i] == '1'));
		}
	}
		
	BitString *Temp = new BitString(temp3);
	
	delete[] temp1;
	delete[] temp2;
	delete[] temp3;

	return *Temp; 
}

void BitString::operator+=(BitString& st)
{
	*this = this->operator+(st);
}

bool BitString::operator==(const BitString& st) const
{
	return (strcmp(_s, st._s) == 0);
}

bool BitString::operator!=(const BitString& st) const
{
	return (strcmp(_s, st._s) != 0);
}

std::ostream& operator<<(std::ostream& os, const BitString& st)
{
	return os << (strchr(st._s, '1') ? strchr(st._s, '1') : st._s);
}

BitString::~BitString()
{
	delete[] _s;
	_s = NULL;
}