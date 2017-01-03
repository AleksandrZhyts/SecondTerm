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

	//������ �� ���������� ����
	void Print(Elem<T>*);

	//����� �� ���������� ����
	Elem<T>* Search(Elem<T>*, T);

	//min �� ���������� ����
	Elem<T>* Min(Elem<T>*);

	//max �� ���������� ����
	Elem<T>* Max(Elem<T>*);

	//��������� ��� ���������� ����
	Elem<T>* Next(Elem<T>*);

	//���������� ��� ���������� ����
	Elem<T> * Previous(Elem<T>*);

	//������� ����
	void Insert(Elem<T>*);

	//�������� ����� ��� ���������� ����,
	//0 - �������� ����� ������
	void Del(Elem<T>* z = 0);

	//�������� ������
	Elem<T>* GetRoot();
	
	//������� ������
	void show_tree_depth();

private:
	Elem<T>* root;
	int left_branch,
	    right_branch;

	//������������ ������ 
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

//������ �� ���������� ����
template <class T>
void binary_tree<T>::Print(Elem<T>* Node)
{
	Elem<T> *Left = Node->left,
	        *Right = Node->right;

	if (Left) Print(Left);
	if (Right) Print(Right);

	cout << Node->data << endl;
}

//����� �� ���������� ����
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

//min �� ���������� ����
template <class T>
Elem<T>* binary_tree<T>::Min(Elem<T>* Node)
{
	if (Node != 0)
		while (Node->left != 0)
			Node = Node->left;
	return Node;
}

//max �� ���������� ����
template <class T>
Elem<T>* binary_tree<T>::Max(Elem<T>* Node)
{
	if (Node != 0)
		while (Node->right != 0)
			Node = Node->right;
	return Node;
}

//��������� ��� ���������� ����
template <class T>
Elem<T>* binary_tree<T>::Next(Elem<T>* Node)
{
	Elem<T>* y = 0;
	if (Node != 0)
	{
		//���� ���� ������ �������
		if (Node->right != 0)
			return Min(Node->right);
		//�������� ����
		y = Node->parent;
		//���� Node �� ������ � Node ������
		while (y != 0 && Node == y->right)
		{
			//�������� �����
			Node = y;
			y = y->parent;
		}
	}
	return y;
}

//���������� ��� ���������� ����
template <class T>
Elem<T>* binary_tree<T>::Previous(Elem<T>* Node)
{
	Elem<T> *y = 0;
	if (Node != 0)
	{
		//���� ���� ����� �������
		if (Node->left != 0)
			return Max(Node->left);
		//�������� ����
		y = Node->parent;
		//���� Node �� ������ � Node �����
		while (y != 0 && Node == y->left)
		{
			//�������� �����
			Node = y;
			y = y->parent;
		}
	}
	return y;
}

//������� ����
template <class T>
void binary_tree<T>::Insert(Elem<T>* z)
{
	//�������� ���
	Elem<T> *y = NULL,
	        *Node = root;
	
	bool flag = false;
	int index = 0;

	if (Node) flag = (z->data < Node->data); //���������� ����� left or right
			
	//����� �����
	while (Node != 0)
	{
		//������� ��������
		y = Node;
		if (z->data < Node->data)
			Node = Node->left;
		else
			Node = Node->right;
		index++;
	}
	//��������� ��������
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
		{    //������������� ������ ��� ������� ������ ������
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

//�������� ����� ��� ���������� ����,
//0 - �������� ����� ������
template <class T>
void binary_tree<T>::Del(Elem<T>* z)
{
	//�������� �����
	if (z != 0)
	{
		Elem<T> * Node, *y;
		//�� 2 �������
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
		//��������� �������� ����?
		if (y->parent == 0)
			root = Node;
		else if (y == y->parent->left)
			//����� �� ��������?
			y->parent->left = Node;
		else
			//������ �� ��������?
			y->parent->right = Node;
		if (y != z)
			//����������� ������ ����
			z->data = y->data;
		delete y;
	}
	else //�������� ����� ������
		while (root != 0)
			Del(root);
}

//�������� ������
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