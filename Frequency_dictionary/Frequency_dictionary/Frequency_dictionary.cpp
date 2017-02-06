/*Задание 1.
Написать программу формирования частотного словаря
появления отдельных слов в некотором тексте. Обеспечить:
1. Чтение исходного текста из файла;
2. Вывод информации обо всех словах;
3. Вывод информации о наиболее часто встречающемся
слове;
4. Запись результата в файл.
При разработке программы использовать словарь типа
map.*/
#include "stdafx.h"

using namespace std;

bool create_dictionary(char* source, map<string, int>& freq_dict)
{
	FILE *f;
	if (fopen_s(&f, source, "r"))
	{
		perror("Open");
		return false;
	}
	char str[200],    
		 word[30];

	int count = 0;
	
	string str_word;

	while (!feof(f))
	{
		fgets(str, 200, f);
		
		int i = -1,
			j = 0;
		
		while (++i < (strlen(str) - 1))
		{
			j = 0;
			while (i < (strlen(str) - 1) && ((int)str[i] > 64 && (int)str[i] < 91 || (int)str[i] > 96 && (int)str[i] < 123)) 
				word[j++] = str[i++];
			
			word[j] = '\0';
			str_word = word;
			
			if (j)
			{
				count++;
				if (freq_dict.find(str_word) == freq_dict.end()) freq_dict.insert({ str_word, 1 });
				else freq_dict[str_word]++;
			}
		}
	}
	
	fclose(f);
	
	return (count != 0);
}

void show_dictionary(map<string, int>& freq_dict)
{
	map<string, int>::iterator it = freq_dict.begin();
	for (; it != freq_dict.end(); it++)
	{
		cout << it->first << " - " << it->second << endl;
	}
}

map<string, int>::iterator find_frequently_word(map<string, int>& freq_dict)
{
	string temp_max;
	int max = 0;
	map<string, int>::iterator it = freq_dict.begin();
	for (; it != freq_dict.end(); ++it)
	{
		if (max < it->second)
		{
			temp_max = it->first;
			max  = it->second;
		}
	}

	return freq_dict.find(temp_max);
}

bool write_dictionary_to_file(char* source, map<string, int>& freq_dict)
{
	FILE *f;
	if (fopen_s(&f, source, "w"))
	{
		perror("Open");
		return false;
	}
	char str[200];
	char count_word[10];
	map<string, int>::iterator it = freq_dict.begin();
	
	for (; it != freq_dict.end(); it++)
	{
		fputs(it->first.c_str(), f);
		fputs("=", f);
		_itoa_s(it->second, count_word, 10, 10);
		fputs(count_word, f);
		fputs("\n", f);
	}
	fclose(f);
	return true;
}

int main()
{
	map<string, int> freq_dict;
	
	if (!create_dictionary("d:\\temp.txt", freq_dict)) cout << "\nError\n";
	else
	{
		show_dictionary(freq_dict);
		
		write_dictionary_to_file("d:\\temp2.txt", freq_dict);
		
		cout <<"\nThe most frequent word = "
			 << find_frequently_word(freq_dict)->first 
			 << " found " 
			 << find_frequently_word(freq_dict)->second 
			 <<" times\n\n";
	}
		
	return 0;
}

