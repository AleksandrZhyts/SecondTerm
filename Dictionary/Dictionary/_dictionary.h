#pragma once

/*Задание 3.
Используя контейнер map реализовать программу — словарь.
Основные возможности:
1. Поиск слова;
2. Добавление, удаление, редактирование слов;
3. Чтение и запись словаря в файл.*/

using namespace std;


class _dictionary
{
public:
	
	_dictionary();

	_dictionary(string, string);

	bool add_word(string, string);
	
	void del_word(string);

	bool edit_word(string);

	map<string, string>& read_from_file(char*);

	void write_to_file(char*);

	friend ostream& operator<<(ostream& os, map<string, string> d);
	
	map<string, string>::iterator find_word(string);
	
	~_dictionary();

private:
	map<string, string> _dict;
};

_dictionary::_dictionary()
{
	_dict.insert({ "", "" });
}

_dictionary::_dictionary(string word, string value)
{
	_dict.insert({ word, value });
}

bool _dictionary::add_word(string word, string value)
{
	pair<map<string, string>::iterator, bool>
		err =_dict.insert(make_pair(word, value));
	
	return (err.second);
}

void _dictionary::del_word(string word)
{
	_dict.erase(_dict.find(word));
}

bool _dictionary::edit_word(string word)
{
	string temp_word;
	string temp_value;
	auto w = _dict.find(word);
	
	if (w != _dict.end())
	{
		this->del_word(word);
		cout << "\nEnter new word: ";
		getline(cin, temp_word);
		cout << "\nEnter new value: ";
		getline(cin, temp_value);
		this->add_word(temp_word, temp_value);
		return true;
	}
	else return false;
}

map<string, string>& _dictionary::read_from_file(char* source)
{
	map<string, string> new_dict;
	
	FILE *f;
	if (fopen_s(&f, source, "r"))
	{
		perror("Open");
		return new_dict;
	}

	char str[200],
		 word[30],
		 value[170];
	
	string str_word,
		   str_value;

	int i = 0,
		j = 0;

	while (!feof(f))
	{
		fgets(str, 200, f);

		i = 0;
		j = 0;

		while (i < (strlen(str) - 1) && (str[i] != '-'))
			word[j++] = str[i++];

		word[j] = '\0';
		str_word = word;

		j = 0;
		while (++i < (strlen(str) - 1))
			value[j++] = str[i];

		value[j] = '\0';
		str_value = value;

		 new_dict.insert({ str_word, str_value });
	}

	fclose(f);

	return new_dict;
}

void _dictionary::write_to_file(char* source)
{
	FILE *f;
	if (fopen_s(&f, source, "w"))
	{
		perror("Open");
		return;
	}
	
	map<string, string>::iterator it = _dict.begin();

	for (; it != _dict.end(); it++)
	{
		fputs(it->first.c_str(), f);
		fputs("-", f);
		fputs(it->second.c_str(), f);
		fputs("\n", f);
	}
	fclose(f);
}

ostream& operator<<(ostream& os, map<string, string> d)
{
	map<string, string>::iterator it = d.begin();
	for (; it != d.end(); it++)
		os << it->first << " - " << it->second << endl;
	return os;
}

map<string, string>::iterator _dictionary::find_word(string key)
{
	return _dict.find(key);
}

_dictionary::~_dictionary() {};
