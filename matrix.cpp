#include <iostream>
#include "matrix.h"
using namespace std;

template <typename T>
Matrix<T>::Matrix(int rows, int columns)
	:m_Rows(rows), m_Columns(columns)
{
	//Allocate memory for the new matrix, initalize all elements to 0;
	m_Matrix = new T[rows * columns]();
}

//Copy constructor
template <typename T>
Matrix<T>::Matrix(const Matrix& matrixToCopy)
	: m_Rows(matrixToCopy.m_Rows), m_Columns(matrixToCopy.m_Columns)
{
	//Allocate memory for the new matrix
	m_Matrix = new T[matrixToCopy.m_Rows * matrixToCopy.m_Columns];

	//Copy values to the new matrix
	for (int i = 0; i < matrixToCopy.m_Rows; i++)
	{
		for (int j = 0; j < matrixToCopy.m_Columns; j++)
		{
			(*this)(i, j) = matrixToCopy(i, j);
		}
	}
}

//Move constructor
template <typename T>
Matrix<T>::Matrix(Matrix&& matrixToCopy) noexcept
	: m_Matrix(matrixToCopy.m_Matrix), m_Rows(matrixToCopy.m_Rows), m_Columns(matrixToCopy.m_Columns)
{
	matrixToCopy.m_Matrix = nullptr;
}

template <typename T>
Matrix<T>::~Matrix()
{
	delete[] m_Matrix;
	m_Matrix = nullptr;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& mRight)
{
	//Avoids self-assignment
	if (&mRight != this)
	{
		//De-allocate memory, then allocate with new matrix size
		delete[] m_Matrix;
		m_Rows = mRight.m_Rows;
		m_Columns = mRight.m_Columns;
		m_Matrix = new int[m_Rows * m_Columns];

		//Copy values to the matrix
		for (int i = 0; i < mRight.m_Rows; i++)
		{
			for (int j = 0; j < mRight.m_Columns; j++)
			{
				(*this)(i, j) = mRight(i, j);
			}
		}

	}

	return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(Matrix&& mRight) noexcept
{
	//Avoids self-assignment
	if (&mRight != this)
	{
		delete[] m_Matrix;

		m_Matrix = mRight.m_Matrix;
		m_Rows = mRight.m_Rows;
		m_Columns = mRight.m_Columns;

		mRight.m_Matrix = nullptr;
		mRight.m_Rows = 0;
		mRight.m_Columns = 0;
	}

	return *this;
}

//Overload operator() for index access
template <typename T>
int& Matrix<T>::operator()(const int row, const int column)
{
	size_t index = row * m_Columns + column;
	return m_Matrix[index];
}

//Overload operator() for index access for const objects
template <typename T>
int& Matrix<T>::operator()(const int row, const int column) const
{
	size_t index = row * m_Columns + column;
	return m_Matrix[index];
}

template <typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix& mRight)
{
	//If dimentions are not the same return an empty matrix
	if (!matrixCheckDimensionsSame(*this, mRight))
	{
		Matrix empty = Matrix();
		return empty;
	}

	for (int i = 0; i < this->m_Rows; i++)
	{
		for (int j = 0; j < this->m_Columns; j++)
		{
			(*this)(i, j) = (*this)(i, j) + mRight(i, j);
		}
	}

	return *this;
}

template <typename T>
const Matrix<T> Matrix<T>::operator+(const Matrix& mRight)
{
	Matrix output = *this;

	//Use the overloaded compount assignment += to sum the values
	output += mRight;

	return output;
}

template <typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix& mRight)
{
	//If dimentions are not the same return an empty matrix
	if (!matrixCheckDimensionsSame(*this, mRight))
	{
		Matrix empty = Matrix();
		return empty;
	}

	for (int i = 0; i < this->m_Rows; i++)
	{
		for (int j = 0; j < this->m_Columns; j++)
		{
			(*this)(i, j) = (*this)(i, j) - mRight(i, j);
		}
	}

	return *this;
}

template <typename T>
const Matrix<T> Matrix<T>::operator-(const Matrix& mRight)
{
	Matrix output = *this;

	//Use the overloaded compount assignment -= to sum the values
	output -= mRight;

	return output;
}

template <typename T>
Matrix<T>& Matrix<T>::operator*=(int scalar)
{
	for (int i = 0; i < this->m_Rows; i++)
	{
		for (int j = 0; j < this->m_Columns; j++)
		{
			(*this)(i, j) = (*this)(i, j) * scalar;
		}
	}

	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*=(const Matrix& mRight)
{
	if (!matrixCheckDimensionsMultiplication(*this, mRight))
	{
		Matrix empty = Matrix();
		return empty;
	}

	Matrix output(this->m_Rows, mRight.m_Columns);

	for (int i = 0; i < this->m_Rows; i++)
	{
		for (int j = 0; j < mRight.m_Columns; j++)
		{
			for (int k = 0; k < this->m_Columns; k++)
			{
				output(i, j) += (*this)(i, k) * mRight(k, j);
			}
		}
	}

	return output;
}

template <typename T>
const Matrix<T> Matrix<T>::operator*(int scalar)
{
	Matrix output = *this;

	//Use the overloaded compount assignment *= to multiply the values
	output *= scalar;

	return output;
}

template <typename T>
const Matrix<T> Matrix<T>::operator*(const Matrix& mRight)
{
	return operator*=(mRight);
}

template <typename T>
bool Matrix<T>::operator==(const Matrix& mRight)
{
	if (!matrixCheckDimensionsSame(*this, mRight))
	{
		return false;
	}

	for (int i = 0; i < this->m_Rows; i++)
	{
		for (int j = 0; j < this->m_Columns; j++)
		{
			if (!((*this)(i, j) == mRight(i, j)))
			{
				return false;
			}
		}
	}

	return true;
}

template <typename T>
bool Matrix<T>::operator!=(const Matrix& mRight)
{
	return !(*this == mRight);
}

template <typename T>
const Matrix<T> Matrix<T>::transpose()
{
	Matrix output(this->m_Columns, this->m_Rows);

	for (int i = 0; i < this->m_Columns; i++)
	{
		for (int j = 0; j < this->m_Rows; j++)
		{
			output(i, j) = (*this)(j, i);
		}
	}

	return output;
}

template <typename T>
bool Matrix<T>::matrixCheckDimensionsSame(const Matrix& mLeft, const Matrix& mRight)
{
	bool isSame = false;

	if (mLeft.m_Rows == mRight.m_Rows && mLeft.m_Columns == mRight.m_Columns)
	{
		isSame = true;
	}

	return isSame;
}

template <typename T>
bool Matrix<T>::matrixCheckDimensionsMultiplication(const Matrix& mLeft, const Matrix& mRight)
{
	bool isSame = false;

	if (mLeft.m_Columns == mRight.m_Rows)
	{
		isSame = true;
	}

	return isSame;
}

template <typename T>
void Matrix<T>::matrixPopulateUniform(int number)
{
	for (int i = 0; i < m_Rows; i++)
	{
		for (int j = 0; j < m_Columns; j++)
		{
			(*this)(i, j) = number;
		}
	}
}

template <typename T>
void Matrix<T>::matrixPrint()
{
	for (int i = 0; i < m_Rows; i++)
	{
		for (int j = 0; j < m_Columns; j++)
		{
			cout << (*this)(i, j) << " ";
		}

		cout << endl;
	}

	cout << endl;
}