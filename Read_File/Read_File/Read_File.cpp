/*Дан текстовый файл. Необходимо создать новый файл
и записать в него следующую статистику по исходному
файлу:
■ Количество символов;
■ Количество строк;
■ Количество гласных букв;
■ Количество согласных букв;
■ Количество цифр.*/

#include "stdafx.h"

using namespace std;

int main()
{
	FILE *f1,
		 *f2;
	
	if (fopen_s(&f1, "D:\\Dz.txt", "r"))
	{
		perror("Open");
		return 0;
	}
	
	int count_symb = 0,
		count_str = 0,
		count_vowel = 0,
		count_consan = 0,
		count_dig = 0;

	char s[200] = { 0 };
	
	while (!feof(f1))
	{
		fgets(s, 200, f1);
		
		count_str++;
		
		for (unsigned int i(0); i < strlen(s); i++)
		{
			if (s[i] < 48 || (s[i]>57 && s[i] < 65) || (s[i]>90 && s[i] < 97) || (s[i]>122 && s[i] < 128)) count_symb++;
			else if (s[i] > 47 && s[i] < 58) count_dig++;
			else if (s[i] == 65 || s[i] == 69 || s[i] == 73 || s[i] == 79 || s[i] == 85 || s[i] == 89 || s[i] == 97
				|| s[i] == 101 || s[i] == 105 || s[i] == 111 || s[i] == 117 || s[i] == 121) count_vowel++;
			else count_consan++;
		}
	}

	if (fopen_s(&f2, "D:\\information.txt", "a"))
	{
		perror("Open");
		return 0;
	}
	char *temp = new char[5];

	fputs("String : ", f2);
	_itoa_s(count_str, temp, 4, 10);
	fputs(temp, f2);
	fputs("\n", f2);

	fputs("Symbols : ", f2);
	_itoa_s(count_symb, temp, 4, 10);
	fputs(temp, f2);
	fputs("\n", f2);
	
	fputs("Vowels : ", f2);
	_itoa_s(count_vowel, temp, 4, 10);
	fputs(temp, f2);
	fputs("\n", f2);
	
	fputs("Consanants : ", f2);
	_itoa_s(count_consan, temp, 4, 10);
	fputs(temp, f2);
	fputs("\n", f2);

	fputs("Digits : ", f2);
	_itoa_s(count_dig, temp, 4, 10);
	fputs(temp, f2);
	fputs("\n", f2);
	
	fclose(f1);
	fclose(f2);

	return 0;
}
