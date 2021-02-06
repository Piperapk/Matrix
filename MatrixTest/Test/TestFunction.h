#include "../Source/matrix.h"
using namespace std;

template <typename T>
bool matrixTest()
{
	bool hasPassed = false;

	cout << "Starting martix test." << endl;

	cout << "Creating Matrix 1" << endl;
	Matrix<T> m1(3, 3);
	m1.matrixPopulateUniform(1);
	m1.matrixPrint();

	cout << "Creating Matrix 2" << endl;
	Matrix<T> m2(3, 3);
	m2.matrixPopulateUniform(2);
	m2.matrixPrint();

	cout << "Creating Matrix 3" << endl;
	Matrix<T> m3(2, 3);
	m3.matrixPopulateUniform(5);
	m3.matrixPrint();

	//Check if dimensions are the same
	cout << "TEST - Checking dimensions sameness." << endl;
	bool dimensionTest = m1.matrixCheckDimensionsSame(m1, m2);

	if (dimensionTest)
	{
		cout << "Dimentions check works." << endl << endl;
	}
	else
	{
		cout << "Dimentions check fails." << endl << endl;
	}

	//Check addition
	cout << "TEST - Checking addition." << endl;
	bool additionTest = true;
	Matrix<T> addition = m1 + m2;
	cout << "Sum of Matrix 1 and Matrix 2." << endl;
	addition.matrixPrint();

	for (size_t i = 0; i < addition.getRows() && additionTest == true; i++)
	{
		for (size_t j = 0; j < addition.getColumns(); j++)
		{
			if (addition(i, j) != 3)
			{
				additionTest = false;

				break;
			}
		}
	}

	if (additionTest)
	{
		cout << "Addition works." << endl << endl;
	}
	else
	{
		cout << "Addition fails." << endl << endl;
	}

	//Check subtraction
	cout << "TEST - Checking subtraction." << endl;
	bool subractionTest = true;
	Matrix<T> subraction = m1 - m2;
	cout << "Difference of Matrix 1 and Matrix 2." << endl;
	subraction.matrixPrint();

	for (size_t i = 0; i < subraction.getRows() && subractionTest == true; i++)
	{
		for (size_t j = 0; j < subraction.getColumns(); j++)
		{
			if (subraction(i, j) != -1)
			{
				subractionTest = false;

				break;
			}
		}
	}

	if (subractionTest)
	{
		cout << "Subtraction works." << endl << endl;
	}
	else
	{
		cout << "Subtraction fails." << endl << endl;
	}

	//Check scalar multiplication
	cout << "TEST - Checking scalar multiplication." << endl;
	bool scalarMultiplicationTest = true;
	Matrix<T> scalar = m1 * 2;
	cout << "Product of Matrix 1 * 2." << endl;
	scalar.matrixPrint();

	for (size_t i = 0; i < scalar.getRows() && scalarMultiplicationTest == true; i++)
	{
		for (size_t j = 0; j < scalar.getColumns(); j++)
		{
			if (scalar(i, j) != 2)
			{
				scalarMultiplicationTest = false;

				break;
			}
		}
	}

	if (scalarMultiplicationTest)
	{
		cout << "Scalar multiplication works." << endl << endl;
	}
	else
	{
		cout << "Scalar multiplication fails." << endl << endl;
	}

	//Check multiplication
	cout << "TEST - Checking multiplication." << endl;
	bool multiplicationTest = true;
	Matrix<T> multiplication = m3 * m1;
	cout << "Product of Matrix 1 * Matrix 3." << endl;
	multiplication.matrixPrint();

	for (size_t i = 0; i < multiplication.getRows() && multiplicationTest == true; i++)
	{
		for (size_t j = 0; j < multiplication.getColumns(); j++)
		{
			if (multiplication(i, j) != 15)
			{
				multiplicationTest = false;

				break;
			}
		}
	}

	if (multiplicationTest)
	{
		cout << "Multiplication works." << endl << endl;
	}
	else
	{
		cout << "Multiplication fails." << endl << endl;
	}

	//Check transposition
	cout << "TEST - Checking transposition." << endl;
	bool transpositionTest = true;
	Matrix<T> transposition = m3;
	transposition = transposition.transpose();
	cout << "Transpose of Matrix 3." << endl;
	transposition.matrixPrint();

	if (transposition.getRows() != 3 || transposition.getColumns() != 2)
	{
		transpositionTest = false;
	}

	for (size_t i = 0; i < transposition.getRows() && transpositionTest == true; i++)
	{
		for (size_t j = 0; j < transposition.getColumns(); j++)
		{
			if (transposition(i, j) != 5)
			{
				transpositionTest = false;

				break;
			}
		}
	}

	if (transpositionTest)
	{
		cout << "Transposition works." << endl << endl;
	}
	else
	{
		cout << "Transposition fails." << endl << endl;
	}


	//Check assignment
	cout << "TEST - Checking assignment." << endl;
	bool assignmentTest = true;
	Matrix<T> assignment = m2;
	cout << "Result of New Matrix = Matrix 2." << endl;
	assignment.matrixPrint();

	for (size_t i = 0; i < assignment.getRows() && assignmentTest == true; i++)
	{
		for (size_t j = 0; j < assignment.getColumns(); j++)
		{
			if (assignment(i, j) != m2(i, j))
			{
				assignmentTest = false;

				break;
			}
		}
	}

	if (assignmentTest)
	{
		cout << "Assignment works." << endl << endl;
	}
	else
	{
		cout << "Assignment fails." << endl << endl;
	}

	//Check equality
	cout << "TEST - Checking equality." << endl;
	Matrix<T> tempEquality = m2;
	bool equalityTest = tempEquality == m2;
	if (equalityTest)
	{
		cout << "Equality works." << endl << endl;
	}
	else
	{
		cout << "Equality fails." << endl << endl;
	}

	//Check inequality
	cout << "TEST - Checking inequality." << endl;
	Matrix<T> tempInequality = m2;
	bool inequalityTest = tempInequality != m2;
	inequalityTest = !inequalityTest; //Reverse result for consistency of checks;
	if (inequalityTest)
	{
		cout << "Inequality works." << endl << endl;
	}
	else
	{
		cout << "Inequality fails." << endl << endl;
	}

	hasPassed = dimensionTest && additionTest && subractionTest && assignmentTest && scalarMultiplicationTest && multiplicationTest && transpositionTest && equalityTest && inequalityTest;

	if (hasPassed)
	{
		cout << "All test passed!" << endl;
	}

	cout << endl;	

	return hasPassed;
}
