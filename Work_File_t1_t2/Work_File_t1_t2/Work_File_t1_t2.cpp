/*Задание 1.
Дан текстовый файл. Удалить из него последнюю строку.
Результат записать в другой файл.
Задание 2.
Дан текстовый файл. Найти длину самой длинной строки.
Задание 3.
Дан текстовый файл. Посчитать сколько раз в нем встречается заданное пользователем слово.
Задание 4.
Дан текстовый файл. Найти и заменить в нем заданное
слово. Что искать и на что заменять определяется пользователем.
*/
#include "stdafx.h"

using namespace std;

int main()
{
	FILE *f1,
		 *f2,
		 *f3;

	if (fopen_s(&f1, "D:\\Dz.txt", "r"))
	{
		perror("Open");
		return 0;
	}

	if (fopen_s(&f2, "D:\\Dz_10.txt", "a"))
	{
		perror("Open");
		return 0;
	}
	
	if (fopen_s(&f3, "D:\\Dz_10_4.txt", "a"))
	{
		perror("Open");
		return 0;
	}

	char s1[200] = { 0 };
	
	unsigned int max_length_string = 0;
	
	int const Max_Length_Word = 15;
	
	cout << "Enter the word for search: ";
	char f_word[Max_Length_Word];
	cin >> f_word;

	cout << "Enter the word for change: ";
	char ch_word[Max_Length_Word];
	cin >> ch_word;

	int count_word = 0;
	
	while (!feof(f1) )
	{
		fgets(s1, 200, f1);
		
		//task 1
		if (!feof(f1)) fputs(s1, f2);

		//task 2
		if (strlen(s1) > max_length_string) max_length_string = strlen(s1);

		//task 3
		char *involve = strstr(s1, f_word);
			while (involve)
			{
				count_word++;
				involve += strlen(f_word);
				involve = strstr(involve, f_word);
			}
	
		//task 4
		char *temp;
		involve = strstr(s1, f_word); 

		if (involve)
		{			
			unsigned int i = 0,
				         j = 0,
			             lengths_s1 = 0;
			
			while (s1[lengths_s1++] != '\n');
			s1[lengths_s1++] = '\0';
			
			temp = new char[lengths_s1 + count_word * (strlen(ch_word) - strlen(f_word)) + 1];
			
			while (i < lengths_s1)
				if (i != (involve - s1)) temp[j++] = s1[i++];
				else
				{
					for (unsigned int i(0); i < strlen(ch_word); i++)
						temp[j++] = ch_word[i];
					i += strlen(f_word);
					involve += strlen(f_word);
					involve = strstr(involve, f_word);
				}
		}
		else
		{
			temp = new char[strlen(s1) + 1];
			strcpy_s(temp, strlen(s1) + 1, s1);
		}
		
		fputs(temp, f3);
		
		delete[] temp ;
		temp = NULL;
		involve = NULL;	
	}
	
	cout << "The length of the longest line is " << max_length_string << endl;
	
	cout << "The word " << f_word << " in the file meet " << count_word << " times" << endl;
	
	fclose(f1);
	fclose(f2);
	fclose(f3);

	return 0;
}
