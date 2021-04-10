#include <iostream>
#include "Source/matrix.h"
#include "Test/TestFunction.h"
using namespace std;

int main()
{
	Matrix<int> aMatrixInt;
	cout << "Does class Matrix<int> work? " << boolalpha << matrixTest<int>();
}