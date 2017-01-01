/*Задание 2.
Дано два текстовых файла. Выяснить, совпадают ли их
строки. Если нет, то вывести несовпадающую строку из
каждого файла.*/
#include "stdafx.h"

using namespace std;

int main()
{
	FILE *f1,
		 *f2;
	
	if (fopen_s(&f1, "D:\\Dz_copy.txt", "r") || fopen_s(&f2, "D:\\Dz.txt", "r"))
	{
		perror("Open");
		return 0;
	}
		
	char s1[200] = { 0 },
	     s2[200] = { 0 };
	bool flag = true;
	while (!feof(f1) && !feof(f2))
	{
		fgets(s1, 200, f1);
		fgets(s2, 200, f2);
		if (strcmp(s1, s2) != 0)
		{
			flag = false;
			cout << "file1 :\n" << s1 << endl;
			cout << "file2 :\n" << s2 << endl;
		}
	}
	
	if (flag && feof(f1)== feof(f2)) cout << "\nThese files have the same strings\n";
	
	fclose(f1);
	fclose(f2);
	
	return 0;
}

