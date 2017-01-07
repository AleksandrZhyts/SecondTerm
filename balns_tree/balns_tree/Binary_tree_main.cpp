#include "stdafx.h"
#include "binary_tree.h"

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

	init_tree(13, 45, 30, 50, 27, 39, 46, 90, 15, 38, 40, 103, 103, 103);

	tree.Print(tree.GetRoot());

	tree.show_tree_depth();

	system("pause");

	tree.Del(tree.Search(tree.GetRoot(), 103));
	tree.Del(tree.Search(tree.GetRoot(), 103));

	tree.Print(tree.GetRoot());

	//cout << tree.Search(tree.GetRoot(), 30)->data << endl;

	return 0;
}

