#include "matrixmultiply.hpp"
#include "iostream"
#include <vector>




#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/extensions/HelperMacros.h>
using namespace std;

/*!
*	EPSILON value
*/
#define EPS 1e-5


/*!
*  Class extends TestFixture to setup test cases
*/
class MatrixUnitTests : public CppUnit::TestFixture { 
private:

	/// \cond DO_NOT_DOCUMENT
	Matrix aMatrix, bMatrix, productMatrix, transposeMatrix,
		   aMatrix1, bMatrix1, productMatrix1, transposeMatrix1;
	/// /endcond


public:

	/// \cond DO_NOT_DOCUMENT
	static CppUnit::TestResult result;
	/// \endcond

	/*!
  	*	setUp method called before each test case is executed.
	*/
	void setUp()
	{
		int a_height = 3;
		int a_width = 2;
		aMatrix = Matrix_Multiply_h::Matrix(3,2);
		
		std::vector<float> a_matrix = {1.0,3.0,4.0,5.0,4.0,5.0};
		aMatrix.setMatrix(a_matrix);
		
		
		int b_height = 2;
		int b_width = 2;
		bMatrix = Matrix_Multiply_h::Matrix(2,2);
		
		std::vector<float> b_matrix = {3.0,2.0,1.5,3.5};
		bMatrix.setMatrix(b_matrix);

		

		productMatrix = Matrix_Multiply_h::Matrix(3,2);
		
		std::vector<float> product_matrix = {7.5,12.5,19.5,25.5,19.5,25.5};
		productMatrix.setMatrix(product_matrix);


		int a1_height = 5;
		int a1_width = 5;
		aMatrix1 = Matrix_Multiply_h::Matrix(5,5);
		
		
		std::vector<float> a1_matrix = {5.4,34,30,23,2.45,3.89,2.1,4.5,98,32,4.09,12,324,12,43,23,90,21,43,5.45,3.2,4.32,4.23,0.98,8.09};
		aMatrix1.setMatrix(a1_matrix);
		
		
		int b1_height = 5;
		int b1_width = 5;
		bMatrix1 = Matrix_Multiply_h::Matrix(5,5);
		
		std::vector<float> b1_matrix = {2.32,4.53,2.1,4.234,5.435,2.45,9.09,87.9,93.2,344.2,4.432,34.43,4.32,54.34,34.3,32.2,3.2,1.43,54.3,54.2,23.1,23.1,45.2,21.2,45.9};
		bMatrix1.setMatrix(b1_matrix);

		

		productMatrix1 = Matrix_Multiply_h::Matrix(5,5);
		
		std::vector<float> product1_matrix = {1025.98,1496.62,3273.17,6122.7,14120.2,3928.91,1244.45,1798.74,6456.52,7678.71,2854.56,12314.6,4423.83,20305.1,17889.9,
											1877.43,1908.82,8357.85,12077,34404.1,255.19,389.419,771.791,870.753,2073.87};
		productMatrix1.setMatrix(product1_matrix);

		transposeMatrix1 = Matrix_Multiply_h::Matrix(5,5);
		std::vector<float> transpose_matrix = {1025.98, 3928.91, 2854.56, 1877.43, 255.19, 1496.62, 1244.45, 12314.6, 1908.82, 389.419, 3273.17, 1798.74, 4423.83,
													8357.85, 771.791, 6122.7, 6456.52, 20305.1, 12077, 870.753, 14120.2, 7678.71, 17889.9, 34404.1, 2073.87};

		transposeMatrix1.setMatrix(transpose_matrix);
	}

	/*!
  	*	tearDown method called after each test case is executed.
	*/
	void tearDown()
	{
		//delete 
	}

	
	/*!
  		test case used for testing multiplication for floating numbers
	*/
  	void testMultiplication1()
	{
		cout << " Happy Flow" << endl;
		Matrix resultMatrix = aMatrix.multiplyMatrix(bMatrix);
		
		
		std::vector<float> productMatrixArray = productMatrix.getMatrix();
		std::vector<float> resultMatrixArray = resultMatrix.getMatrix();

		
		CPPUNIT_ASSERT_MESSAGE("Error in Multiplication",std::equal(productMatrixArray.begin(),productMatrixArray.end(),resultMatrixArray.begin()));
	}

	/*!
  	*	test case used for testing multiplication for floating numbers
	*/
	void testMultiplication2()
	{
		cout << " Happy Flow" << endl;
		Matrix resultMatrix = aMatrix1.multiplyMatrix(bMatrix1);
		
		
		std::vector<float> productMatrixArray = productMatrix1.getMatrix();
		std::vector<float> resultMatrixArray = resultMatrix.getMatrix();

		
			

		for(int i =0;i<25;i++)
		{
			
			CPPUNIT_ASSERT_MESSAGE("Error in Multiplication",!(std::abs(productMatrixArray[i] - resultMatrixArray[i]) > EPS * std::abs(productMatrixArray[i])));
			
		}

		
	}

	/*!
  	*	test case used for testing that two matrices with unequal columns in Matrix A and rows in Matrix B are not multiplied.
	*/
  	void testMultiplication3()
	{
		cout << " Unequal columns and rows" << endl;
		Matrix resultMatrix = aMatrix.multiplyMatrix(aMatrix);
		
		std::vector<float> productMatrixArray = productMatrix.getMatrix();
		std::vector<float> resultMatrixArray = resultMatrix.getMatrix();

		
		
		CPPUNIT_ASSERT_MESSAGE("Error in Multiplication with Unequal number of columns in A and rows in B",resultMatrixArray.size() == 0);
	}

	/*!
  	*	test case used for testing transpose of non-floating matrix
	*/
	void testTranspose1()
	{
		cout << endl << " Transpose of a matrix" << endl;
		Matrix resultMatrix = aMatrix.transpose();

		std::vector<float> transposeMatrixArray = transposeMatrix.getMatrix();
		std::vector<float> resultMatrixArray = resultMatrix.getMatrix();

		CPPUNIT_ASSERT_MESSAGE("Error in Transpose",std::equal(transposeMatrixArray.begin(),transposeMatrixArray.end(),resultMatrixArray.begin()));
	}

	/*!
  	*	test case used for testing transpose of floating matrix
	*/
	void testTranspose2()
	{
		cout << endl << " Transpose of a matrix" << endl;
		Matrix resultMatrix = productMatrix1.transpose();

		std::vector<float> transposeMatrixArray = transposeMatrix1.getMatrix();
		std::vector<float> resultMatrixArray = resultMatrix.getMatrix();

		for(int i =0;i<25;i++)
		{
			CPPUNIT_ASSERT_MESSAGE("Error in Transpose",!(std::abs(transposeMatrixArray[i] - resultMatrixArray[i]) > EPS * std::abs(transposeMatrixArray[i])));
			
		}
	}

/// \cond DO_NOT_DOCUMENT
CPPUNIT_TEST_SUITE(MatrixUnitTests);
CPPUNIT_TEST(testMultiplication1);
CPPUNIT_TEST(testMultiplication2);
CPPUNIT_TEST(testMultiplication3);
CPPUNIT_TEST(testTranspose1);
CPPUNIT_TEST(testTranspose2);
CPPUNIT_TEST_SUITE_END();

CPPUNIT_TEST_SUITE_REGISTRATION( MatrixUnitTests );

/// \endcond
};