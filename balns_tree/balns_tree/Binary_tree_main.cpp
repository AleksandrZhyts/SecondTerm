#include "stdafx.h"
#include "binary_tree.h"
#include <bitset>


binary_tree <int> tree;

void init_tree(int size, int, int, int, int, int, int, int, int, int, int, int, int, int)
{
	int* ptr = &size;
	Elem <int>* temp;

	for (int i(0); i < size; i++)
	{
		temp = new Elem<int>();
		temp->data = *(++ptr);
		tree.Insert(temp);
	}
}

int main()
{
	srand(unsigned int(time(0)));
	//init_tree(13, 45, 30, 50, 27, 39, 46, 90, 15, 38, 40, 103, 103, 103);
	Elem <int>* temp;
	for (int i(0); i < 1000; i++)
	{
		temp = new Elem<int>();
		temp->data = rand() % 100000;
		tree.Insert(temp);
	}
	tree.Print(tree.GetRoot());

	tree.show_tree_depth();

	time_t t = time(NULL);
	char str[30];
	ctime_s(str, 30, &t);
	cout <<"Data "<< str << endl;
	bitset<8>policy;
	char s[] = "222";
	char key = 'a';
	char iv = 'o';

	for (int i = 0; i < 3; i++) {
		unsigned char next_iv = s[i];
		s[i] = s[i] ^ key ^ iv;
		iv = next_iv;
	}
	cout <<"Shifr " <<s << endl;
	
	for (int i = 0; i < 3; i++) {
		unsigned char next_iv = s[i];
		s[i] = s[i] ^ key ^ iv;
		iv = next_iv;

	}
	policy =(int)(s);

	cout << "After " << s << endl;


	system("pause");

	//tree.Del(tree.Search(tree.GetRoot(), 103));
	//tree.Del(tree.Search(tree.GetRoot(), 103));

	//tree.Print(tree.GetRoot());

	//cout << tree.Search(tree.GetRoot(), 30)->data << endl;

	return 0;
}

