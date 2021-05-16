# Matrix class and container for C++

Mathematical Matrix class with support of simple matrix operations.

## Initialise Matrix:
- Matrix(size_t rows, size_t columns); //Initialise empty matrix with a certain size (m x n).
- Matrix(size_t rows, size_t columns, const T fillValue); //Initialise matrix with a certain size (m x n) and with an uniform value.
- Matrix(size_t rows, size_t columns, const vector<T>&fillVector); //Initialise matrix with a certain size (m x n) via a vector. The size of the vector must match the size of the matrix.
- Matrix m1 = m2; //Initalisation by assignment.

## Element access:
- m1(0, 0); //Access (m x n) elements.

## Matrix operations:
- m1 = m2; //Assignment operator.
- m1 *= 4; //Scalar matrix multiplication.
- m2 = m1 * 4; //Scalar matrix multiplication.
- m1 *= m2; //Matrix multiplication.
- m2 = m1 * m2; //Matrix multiplication.
- m1 == m2; //Comparison operator equal to.
- m1 != m2; //Comparison operator not equal to.
- m1 + m2; //Addition operator.
- m1 =+ m2; //Addition operator.
- m1 - m2; //Subtraction operator.
- m1 =- m2; //Subtraction operator.
- m1.transpose(); //Matrix transpose.
- m1.matrixPopulateUniform(T number); //Populate the matrix with an uniform value.
- m1.matrixPopulateVector(const vector<T>&fillVector); //Populate the matrix via a vector. The size of the vector must match the size of the matrix.
- m1.matrixPrint(); //Print the matrix ina an m x n form.
- m1.getRows(); //Get the size of the matrix's rows.
- m1.getColumns(); //Get the size of the matrix's columns.