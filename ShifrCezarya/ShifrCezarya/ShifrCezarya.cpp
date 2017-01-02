/*Задание 4.
Шифр Цезаря — один из древнейших шифров. При шифровании каждый символ заменяется другим, отстоящим
от него в алфавите на фиксированное число позиций.
Пример
Шифрование с использованием ключа: 3.
■ Оригинальный текст: Съешь же ещё этих мягких французских
булок, да выпей чаю.
■ Шифрованный текст: Фэзыя йз зьи ахлш пвёнлш чугрщцкфнлш
дцосн, жг еютзм ъгб.
■ Дан текстовый файл. Зашифровать его, используя шифр Цезаря.
Результат записать в другой файл.*/

#include "stdafx.h"

using namespace std;

int main()
{
	FILE *f1,
		 *f2;

	if (fopen_s(&f1, "D:\\test.txt", "r+"))
	{
		perror("Open");
		return 0;
	}
	
	if (fopen_s(&f2, "D:\\test2.txt", "a+"))
	{
		perror("Open");
		return 0;
	}
	
	char s[200] = { 0 };
	char let[] = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	
	while (!feof(f1))
	{
		fgets(s, 200, f1);

		for (unsigned int i(0); i < strlen(s); i++)
		{
			int index = -1;
			bool flag = false;
			while (++index < 66 && !flag)
				if (s[i] == let[index]) 
				{
					s[i] = let[(index < 33) ? (index + 3) % 33 : (index + 3) % 33 + 33];
					flag = true;
				}
		}
		fputs(s, f2);
	}

	//Расшифровка шифра
	fseek(f2, 0, 0);
	
	while (!feof(f2))
	{
		fgets(s, 200, f2);
		for (unsigned int i(0); i < strlen(s); i++)
		{
			int index = -1;
			bool flag = false;
			while (++index < 66 && !flag)
				if (s[i] == let[index])
				{
					s[i] = let[(index < 3 || (index > 32 && index < 36)) ? (index + 30) : (index - 3)];
					flag = true;
				}
		}
		fputs(s, f1);
	}

	fclose(f1);
	fclose(f2);
	
	return 0;
}