#include <iostream>
#include "Source/matrix.h"
#include "Test/TestFunction.h"
using namespace std;

int main()
{
	cout << "Does class Matrix<int> work? " << boolalpha << matrixTest<int>();

	Matrix<int> aMatrixInt{1, 3, 19};
	aMatrixInt.matrixPrint();
}