#pragma once

using namespace std;

template <class T>
struct Elem
{
	T data;
	Elem <T> *left = NULL,
		     *right = NULL, 
		     *parent = NULL;
};

template <class T>
class binary_tree
{
public:
	binary_tree();

	~binary_tree();

	//печать от указанного узла
	void Print(Elem<T>*);

	//поиск от указанного узла
	Elem<T>* Search(Elem<T>*, T);

	//min от указанного узла
	Elem<T>* Min(Elem<T>*);

	//max от указанного узла
	Elem<T>* Max(Elem<T>*);

	//следующий для указанного узла
	Elem<T>* Next(Elem<T>*);

	//предыдущий для указанного узла
	Elem<T> * Previous(Elem<T>*);

	//вставка узла
	void Insert(Elem<T>*);

	//удаление ветки для указанного узла,
	//0 - удаление всего дерева
	void Del(Elem<T>* z = 0);

	//получить корень
	Elem<T>* GetRoot();
	
	//глубина дерева
	void show_tree_depth();

private:
	Elem<T>* root;
	int left_branch,
	    right_branch;

	//балансировка дерева 
	void Balansing(bool flag, T data);
};

template <class T>
binary_tree<T>::binary_tree()
{
	root = NULL;
	left_branch = right_branch = 0;
}

template <class T>
binary_tree<T>::~binary_tree()
{
	Del();
}

//печать от указанного узла
template <class T>
void binary_tree<T>::Print(Elem<T>* Node)
{
	Elem<T> *Left = Node->left,
	        *Right = Node->right;

	if (Left) Print(Left);
	if (Right) Print(Right);

	cout << Node->data << endl;
}

//поиск от указанного узла
template <class T>
Elem<T>* binary_tree<T>::Search(Elem<T>* Node, T key)
{
	while (Node != 0 && Node->data != key)
	{
		if (Node->data < key)
			Node = Node->right;
		else
			Node = Node->left;
	}
	return Node;
}

//min от указанного узла
template <class T>
Elem<T>* binary_tree<T>::Min(Elem<T>* Node)
{
	if (Node != 0)
		while (Node->left != 0)
			Node = Node->left;
	return Node;
}

//max от указанного узла
template <class T>
Elem<T>* binary_tree<T>::Max(Elem<T>* Node)
{
	if (Node != 0)
		while (Node->right != 0)
			Node = Node->right;
	return Node;
}

//следующий для указанного узла
template <class T>
Elem<T>* binary_tree<T>::Next(Elem<T>* Node)
{
	Elem<T>* y = 0;
	if (Node != 0)
	{
		//если есть правый потомок
		if (Node->right != 0)
			return Min(Node->right);
		//родитель узла
		y = Node->parent;
		//если Node не корень и Node справа
		while (y != 0 && Node == y->right)
		{
			//Движемся вверх
			Node = y;
			y = y->parent;
		}
	}
	return y;
}

//предыдущий для указанного узла
template <class T>
Elem<T>* binary_tree<T>::Previous(Elem<T>* Node)
{
	Elem<T> *y = 0;
	if (Node != 0)
	{
		//если есть левый потомок
		if (Node->left != 0)
			return Max(Node->left);
		//родитель узла
		y = Node->parent;
		//если Node не корень и Node слева
		while (y != 0 && Node == y->left)
		{
			//Движемся вверх
			Node = y;
			y = y->parent;
		}
	}
	return y;
}

//вставка узла
template <class T>
void binary_tree<T>::Insert(Elem<T>* z)
{
	//потомков нет
	Elem<T> *y = NULL,
	        *Node = root;
	
	bool flag = false;
	int index = 0;

	if (Node) flag = (z->data < Node->data); //определяем ветку left or right
			
	//поиск места
	while (Node != 0)
	{
		//будущий родитель
		y = Node;
		if (z->data < Node->data)
			Node = Node->left;
		else
			Node = Node->right;
		index++;
	}
	//заполняем родителя
	z->parent = y;
	
	if (y == 0) root = z;
	else
	{
		if (z->data < y->data) y->left = z;

		if (z->data > y->data) y->right = z;

		if ((y->right == NULL) || (y->left == NULL))
			if (flag) left_branch += (index > left_branch);
			else right_branch += (index > right_branch);
		else
		{    //рассматриваем случай для первого уровня дерева
			if (!left_branch && right_branch && flag) left_branch++;        
			if (left_branch && !right_branch && !flag) right_branch++;       
		}

		if (fabs(left_branch - right_branch) == 2) Balansing(flag, z->data);
	}
}

template <class T>
void binary_tree<T>::Balansing(bool flag, T data)
{
	Elem<T> *y = NULL,
	        *Node = root;

	if (flag) 
	{
		if (data < Node->left->data) left_branch--;
		right_branch++;
		y = Node->left;
		Node->left = y->right;
		if (y->right) y->right->parent = Node;
		y->right = Node;
		Node->parent = y;	
	}
	else
	{
		left_branch++;
		if (data > Node->right->data) right_branch--;
		y = Node->right;
		Node->right = y->left;
		if (y->left) y->left->parent = Node; 
		y->left = Node;
		Node->parent = y;
	}
	y->parent = NULL;
	root = y;
}

//удаление ветки для указанного узла,
//0 - удаление всего дерева
template <class T>
void binary_tree<T>::Del(Elem<T>* z)
{
	//удаление куста
	if (z != 0)
	{
		Elem<T> * Node, *y;
		//не 2 ребенка
		if (z->left == 0 || z->right == 0)
			y = z;
		else
			y = Next(z);

		if (y->left != 0)
			Node = y->left;
		else
			Node = y->right;
		if (Node != 0)
			Node->parent = y->parent;
		//Удаляется корневой узел?
		if (y->parent == 0)
			root = Node;
		else if (y == y->parent->left)
			//слева от родителя?
			y->parent->left = Node;
		else
			//справа от родителя?
			y->parent->right = Node;
		if (y != z)
			//Копирование данных узла
			z->data = y->data;
		delete y;
	}
	else //удаление всего дерева
		while (root != 0)
			Del(root);
}

//получить корень
template <class T>
Elem<T>* binary_tree<T>::GetRoot()
{
	return root;
}

template <class T>
void binary_tree<T>::show_tree_depth()
{
	cout << "Left branch " << left_branch << endl;
	cout << "Right branch " << right_branch << endl;
}