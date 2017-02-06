/*Задание 3.
Используя контейнер map реализовать программу — словарь.
Основные возможности:
1. Поиск слова;
2. Добавление, удаление, редактирование слов;
3. Чтение и запись словаря в файл.*/

#include "stdafx.h"
#include "_dictionary.h"

using namespace std;

bool add_word(string word, string value, map<string, string>& _dict)
{
	pair<map<string, string>::iterator, bool>
		err = _dict.insert(make_pair(word, value));

	return (err.second);
}

void del_word(string word, map<string, string>& _dict)
{
	_dict.erase(_dict.find(word));       
}

bool edit_word(string word, map<string, string>& _dict)
{
	string temp_word;
	string temp_value;
	auto w = _dict.find(word);

	if (w != _dict.end())
	{
		del_word(word, _dict);
		cout << "\nEnter new word: ";
		getline(cin, temp_word);
		cout << "\nEnter new value: ";
		getline(cin, temp_value);
		add_word(temp_word, temp_value, _dict);
		return true;
	}
	else return false;
}

void show_dictionary(map<string, string>& _dict)
{
	map<string, string>::iterator it = _dict.begin();
	for (; it != _dict.end(); it++)
	{
		cout << it->first << " - " << it->second << endl;
	}
}

map<string, string>*  read_from_file(char* source)
{
	map<string, string> *new_dict = new map<string,string>[1];

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

		new_dict->insert({ str_word, str_value });
	}

	fclose(f);

	return new_dict;
	//show_dictionary(new_dict);
}

void write_to_file(char* source, map<string, string>& _dict)
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

void find_word(string word, map<string, string>& _dict)
{
	auto w = _dict.find(word);

	if (w != _dict.end())
		cout << "\nWe find : " << w->first << " - " << w->second << endl;
	else cout << "\nThis word isn't in dictionary\n";	
}

int main()
{
	map<string, string> _dict;
	string word,
		   value;
	char name_file[100];  

	cout << "Please, select preffer number...\n";
	char ch;
	do {
		cout << "\n1 - Input word\n";
		cout << "2 - Delete word\n";
		cout << "3 - Edit word\n";
		cout << "4 - Find word\n";
		cout << "5 - Write dictonary to file\n";
		cout << "6 - Read dictonary from file\n";
		cout << "7 - Show information\n";
		cout << "0 - Exit\n\n";
		cin >> ch;
		cin.get();

		switch (ch)
		{
		case '1':
			cout << "\nEnter word: ";
			getline(cin, word);
			cout << "\nEnter value of word: ";
			getline(cin, value);
			
			if (!add_word(word, value, _dict))
				cout << "\nThis word is in the dictionary already\n";
			break;
		
		case '2':
			cout << "\nEnter word: ";
			getline(cin, word);
			del_word(word, _dict);
			break;

		case '3':
			cout << "\nEnter word to edit: ";
			getline(cin, word);
			if (!edit_word(word, _dict))
				cout << "\nThis word isn't in the dictionary\n";
			break;

		case '4':
			cout << "\nEnter word to edit: ";
			getline(cin, word);
			find_word(word, _dict);
			break;

		case '5':
			cout << "\nEnter file name and pass to write dictionary: ";
			cin >> name_file;
			write_to_file(name_file, _dict);
			break;

		case '6':
			show_dictionary(*read_from_file(name_file));
			break;
		
		case '7':
			show_dictionary(_dict);
			break;
		}
	} while (ch != '0');
	
	return 0;
}


