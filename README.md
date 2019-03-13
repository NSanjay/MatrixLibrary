# Matrix Library C++ 11

A Linear Algebra consisting of Matrix Multiplication and Transpose operations.

## Getting Started

### File Structure

The package structure used in the project is:
.
├── ...
    ├── include                   	
    │   	├──com/braincorp/linalglib/matrixmultiplication                # Include headers
    ├── tests                   			
    │   	├──com/braincorp/linalglib/matrixmultiplication                # Test source files
    ├── doxygen                   	
    │   	├── ...								# dOxygen documentation
    ├── config_file                   						# dOxygen config file
    └── ..
  
  The package structure in the include file is
```
com/braincorp/linalglib/matrixmultiplication
```
The multiplication and transpose operations are present in the header file ```matrixmultiply.hpp```.

Since the matrix can be set using the ```setMatrix``` method, in order to enforce that the size of the vector corresponds to the current width and height of the matrix, A custom exception ```OutOfBoundsException``` is thrown if the sizes do not correspond.

The header file ```MatrixTest.hpp``` consists of the setup required for CppUnit Test cases.

The file ```main.cpp``` is used to run the tests using CppUnit.

Whereas the file ```MatrixTest.cpp``` can be used for checking the run time of operations for randomly generated matrices.

### High Level Class Overview of Matrix

```
class Matrix
{
	// Constructor
	Matrix(int height,int width) : matrix_height(height), matrix_width(width), matrix(height*width,0)
	Matrix()
	
	// Fields
	int width;
	int height;
	std::vector<float> matrix;
	
	// Methods
	Matrix multiplyMatrix(Matrix b)
	Matrix transpose()
};
```
### Prerequisites

Have ```g++``` in the system. Also the ```CppUnit``` testing framework. 

### Tests

The test suite consists of 5 tests.
1. Test matrix multiplication for two matrices , one of dimension - ```3x2``` and another ```2x2```.
2. Test matrix multiplication for two square matrices of dimension ```5x5```.
3. Test if multiplication can be performed on Matrix A and Matrix B whose columns and rows respectively are unequal.
4. Transpose on the result of test case 1.
5. Transpose on the result of test case 2.


### Command
Execute the following command to compile the test program in the parent directory.
```
g++ -O2 -Iinclude -Icppunit -std=c++11 tests/com/braincorp/linalglib/matrixmultiplication/main.cpp -lcppunit
```

If O2 optimization is not required, then remove the optimization flag. However, it runs a bit slower for higher matrix dimension.

Also execute the following command to check execution speeds.

```
g++ -O2 -Iinclude -Icppunit -std=c++11 tests/com/braincorp/linalglib/matrixmultiplication/MatrixTest.cpp -lcppunit
```
### Test Case Results

Check the ```cppTestBasicMathResults.xml``` file created in the parent directory and the terminal for the Unit test cases results. 

### Execution Speeds

Running the ```MatrixTest.cpp``` file returns the execution speeds.

#### With O2 Flag:
1. average time for size 100 matrix multiplication over 5 runs in microseconds:::646
2. average time for size 100 matrix transpose over 5 runs in microseconds:::13
3. average time for size 1000 matrix multiplication over 5 runs in microseconds:::465235
4. average time for size 1000 matrix transpose over 5 runs in microseconds:::4983

#### Without O2 Flag:
1. average time for size 100 matrix multiplication over 5 runs in microseconds:::7705
2. average time for size 100 matrix transpose over 5 runs in microseconds:::70
3. average time for size 1000 matrix multiplication over 5 runs in microseconds:::7509198
4. average time for size 1000 matrix transpose over 5 runs in microseconds:::11198

### Documentation
The documentation was generated from doxygen. The HTML and Latex files are present in the doxygen folder.
