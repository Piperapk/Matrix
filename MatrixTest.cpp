#include <iostream>
#include "Source/matrix.h"
#include "Test/TestFunction.h"
using namespace std;

int main()
{
	cout << "Does class Matrix<int> work? " << boolalpha << matrixTest<int>() << endl;
}