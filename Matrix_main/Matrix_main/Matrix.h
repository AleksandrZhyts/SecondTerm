#pragma once

using namespace std;

const double EPS = 1e-9;

template<class T>
class Matrix
{
public:
	Matrix(int, int);
	
	Matrix(const Matrix<T>&);
	
	~Matrix();

	void init();

	void init_User();

	T Max();
	
	T Min();
	
	Matrix<T>& operator =(const Matrix<T>&);

	Matrix<T> operator +(const Matrix<T>&);
	
	Matrix<T> operator -(const Matrix<T>&);
	
	Matrix<T> operator *(const Matrix<T>&);

	Matrix<T> operator /(const Matrix<T>&);

	friend ostream& operator<<(ostream& os, const Matrix<T>& _matr)
	{
		cout.setf(ios_base::fixed);
		cout.precision(2);
		
		for (int i(0); i < _matr.row; i++)
		{
			for (int j(0); j < _matr.col; j++)
				os << setw(4) << _matr.matr[i][j] << " ";
			os << "\n";
		}
		os << "\n";
		return os;
	}
	
private:
	T** matr;
	int col;
	int row;
	bool inversion();
};

template<class T>
Matrix<T>::Matrix(int r = 0, int c = 0)
{
	row = r;
	col = c;
	matr = new T*[row];
	for (int i(0); i < row; i++)
		matr[i] = new T[col];
	
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& _matr)
{
	col = _matr.col;
	row = _matr.row;
	matr = new T*[row];
	for (int i(0); i < row; i++)
		matr[i] = new T[col];
	
	for (int i(0); i < row; i++)
		for (int j(0); j < col; j++)
			matr[i][j] = _matr.matr[i][j];
}

template<class T>
Matrix<T>::~Matrix()
{
	for (int i(0); i < row; i++)
		delete[] matr[i];
	delete[] matr;
}

template<class T>
void Matrix<T>::init()
{
	for (int i(0); i < row; i++)
		for (int j(0); j < col; j++)
			matr[i][j] = (T) rand()/300;

}

template<class T>
void Matrix<T>::init_User()
{
	for (int i(0); i < row; i++)
	{
		cout << "Entering " << i + 1 << " string:\n";
		for (int j(0); j < col; j++)
		{
			cout << "Enter " << j + 1 << " element: ";
			cin >> matr[i][j];
		}
	}
}

template<class T>
T Matrix<T>::Max()
{
	T max = matr[0][0];
	for (int i(0); i < row; i++)
		for (int j(0); j < col; j++)
			if (max < matr[i][j]) max = matr[i][j];
	return max;
}

template<class T>
T Matrix<T>::Min()
{
	T min = matr[0][0];
	for (int i(0); i < row; i++)
		for (int j(0); j < col; j++)
			if (min > matr[i][j]) min = matr[i][j];
	return min;
}

template<class T>
Matrix<T>& Matrix<T>::operator =(const Matrix<T>& _matr)
{
	if (this == &_matr)	return *this;

	this->~Matrix();

	row = _matr.row;
	col = _matr.col;
	
	matr = new T*[row];
	for (int i(0); i < row; i++)
		matr[i] = new T[col];

	for (int i(0); i < row; i++)
		for (int j(0); j < col; j++)
			matr[i][j] = _matr.matr[i][j];

	return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator +(const Matrix<T>& _matr)
{
	
	if (row != _matr.row || col != _matr.col)
	{
		cout << "Error! Different size matrix !\n";
		return *this;
	}
	else
	{
		Matrix<T> sum(_matr.row, _matr.col);

		for (int i(0); i < row; i++)
			for (int j(0); j < col; j++)
				sum.matr[i][j] = _matr.matr[i][j] + matr[i][j];
		return sum;
	}
}

template<class T>
Matrix<T> Matrix<T>::operator -(const Matrix<T>& _matr)
{
	if (row != _matr.row || col != _matr.col)
	{
		cout << "Error! Different size matrix !\n";
		return *this;
	}
	else
	{
		Matrix<T> sub(_matr.row, _matr.col);

		for (int i(0); i < row; i++)
			for (int j(0); j < col; j++)
				sub.matr[i][j] = matr[i][j] - _matr.matr[i][j] ;
		return sub;
	}
}

template<class T>
Matrix<T> Matrix<T>::operator *(const Matrix<T>& _matr)
{
	if (col != _matr.row )
	{
		cout << "Error! These matrix can't multiplication !|\n";
		return *this;
	}
	else
	{
		Matrix<T> mul(row, _matr.col);

		for (int i(0); i < row; i++)
			for (int j(0); j < _matr.col; j++)
			{
				mul.matr[i][j] = (T)0;
				for (int k(0); k < col; k++)
					mul.matr[i][j] += matr[i][k] * _matr.matr[k][j];
			}
		return mul;
	}
}

template<class T>
bool Matrix<T>::inversion()
{
	T temp;
	Matrix <T> E(row, col);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			E.matr[i][j] = 0;
			if (i == j)
				E.matr[i][j] = 1;
		}

	for (int k = 0; k < row; k++)
	{
		// Если элемент на главной диагонали = 0 то ищем строку, где элемент
		// того же столбца не нулевой, и меняем строки местами
		if (fabs(matr[k][k]) < 1e-8)  
		{
			bool changed = false;

			for (int i = k + 1; i < row; ++i)
			{
				if (fabs(matr[i][k]) > 1e-8)
				{
					swap(matr[k], matr[i]);
					swap(E.matr[k], E.matr[i]);
					changed = true;
					break;
				}
			}
			if (!changed) return false;
		}

		temp = matr[k][k];

		for (int j = 0; j < col; j++)
		{
			matr[k][j] /= temp;
			E.matr[k][j] /= temp;
		}

		for (int i = k + 1; i < row; i++)
		{
			temp = matr[i][k];

			for (int j = 0; j < row; j++)
			{
				matr[i][j] -= matr[k][j] * temp;
				E.matr[i][j] -= E.matr[k][j] * temp;
			}
		}
	}

	for (int k = row - 1; k > 0; k--)
	{
		for (int i = k - 1; i >= 0; i--)
		{
			temp = matr[i][k];
			for (int j = 0; j < col; j++)
			{
				matr[i][j] -= matr[k][j] * temp;
				E.matr[i][j] -= E.matr[k][j] * temp;
			}
		}
	}

	*this = E;
	return true;
}

template<class T>
Matrix<T> Matrix<T>::operator /(const Matrix<T>& _matr)
{
	if (row != col || _matr.row != _matr.col || row != _matr.row)
	{
		cout << "Error! These matrix can't division !|\n";
		return *this;
	}
	Matrix<T> div(row, col);
	div = _matr;
	if (div.inversion()) return  *this * div;
	else return *this;
}
