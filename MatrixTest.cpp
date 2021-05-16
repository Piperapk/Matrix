#include <iostream>
#include <string>
#include "Source/matrix.h"
#include "Test/TestFunction.h"
using namespace std;

int main()
{
	string selection;

	while (selection != "test" && selection != "help")
	{
		cout << "Type \"help\" to see a list of all commands; Type \"test\" to run a diagnostic test of class Matrix." << endl;
		getline(cin, selection);
	} 

	if (selection == "test")
	{
		cout << "Does class Matrix<int> work? " << boolalpha << matrixTest<int>() << endl;
	}
	else if(selection == "help")
	{
		cout << "Initialise Matrix: " << endl;
		cout << "Matrix(size_t rows, size_t columns); //Initialise empty matrix with a certain size (m x n)." << endl;
		cout << "Matrix(size_t rows, size_t columns, const T fillValue); //Initialise matrix with a certain size (m x n) and with an uniform value." << endl;
		cout << "Matrix(size_t rows, size_t columns, const vector<T>&fillVector); //Initialise matrix with a certain size (m x n) via a vector. The size of the vector must match the size of the matrix." << endl;
		cout << "Matrix m1 = m2; //Initalisation by assignment." << endl;
		cout << endl;
		cout << "Element access:" << endl;
		cout << "m1(0, 0); //Access (m x n) elements." << endl;
		cout << endl;
		cout << "Matrix operations:" << endl;
		cout << "m1 = m2; //Assignment operator." << endl;
		cout << "m1 *= 4; //Scalar matrix multiplication." << endl;
		cout << "m2 = m1 * 4; //Scalar matrix multiplication." << endl;
		cout << "m1 *= m2; //Matrix multiplication." << endl;
		cout << "m2 = m1 * m2; //Matrix multiplication." << endl;
		cout << "m1 == m2; //Comparison operator equal to." << endl;
		cout << "m1 != m2; //Comparison operator not equal to." << endl;
		cout << "m1 + m2; //Addition operator." << endl;
		cout << "m1 =+ m2; //Addition operator." << endl;
		cout << "m1 - m2; //Subtraction operator." << endl;
		cout << "m1 =- m2; //Subtraction operator." << endl;
		cout << "m1.transpose(); //Matrix transpose." << endl;
		cout << "m1.matrixPopulateUniform(T number); //Populate the matrix with an uniform value." << endl;
		cout << "m1.matrixPopulateVector(const vector<T>&fillVector); //Populate the matrix via a vector. The size of the vector must match the size of the matrix." << endl;
		cout << "m1.matrixPrint(); //Print the matrix ina an m x n form." << endl;
		cout << "m1.getRows(); //Get the size of the matrix's rows." << endl;
		cout << "m1.getColumns(); //Get the size of the matrix's columns." << endl;
	}
}