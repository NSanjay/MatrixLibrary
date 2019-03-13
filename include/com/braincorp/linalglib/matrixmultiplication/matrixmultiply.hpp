#include <vector>
#include "iostream"


#ifndef Matrix_Multiply_h

#define Matrix_Multiply_h

/*!
  An exception used if the vector size is not equal to the matrix dimensions.
*/
class OutOfBoundsException: public std::runtime_error
{
   public:
        /**
            \brief Returns error description.

            behaves like std::runtime_error::what().
        */
        const char *what( ) const noexcept override
        {
            return std::runtime_error::what( );
        }

        /**
            \brief Constructs an exception.

            \param cmessage The error description.
        */
        OutOfBoundsException( const char *cmessage ) :
            std::runtime_error( cmessage ) // std::runtime_error will store the original message
        {
            // Attempt to generate stacktrace
            
        }

    protected:
        
        std::string message; //!< Contains the user message.
};

/*!
  The class represents the the number of columns, and multiply and transpose operations of a matrix.
*/
class Matrix
{
public:

	/*!
		A constructor that creates a matrix given its height and width.
	*/
	Matrix(int height,int width) : matrix_height(height), matrix_width(width), matrix(height*width,0)
	{
		
	}

	/*!
		Default Constructor
	*/
	Matrix()
	{

	}

	/*!
		Getter method to retrieve the width (number of columns of a matrix)
		\return the width of the matrix
	*/
	inline int getWidth()
	{
		return matrix_width;
	}

	/*!
		Getter method to retrieve the height (number of rows of a matrix)
		\return the height of the matrix
	*/
	inline int getHeight()
	{
		return matrix_height;
	}

	/*!
		Setter method to set the width (number of columns of a matrix)
		\param width The width of the matrix
	*/
	inline void setWidth(int width)
	{
		matrix_width = width;
	}

	/*!
		Setter method to set the height (number of rows of a matrix)
		\param height The height of the matrix
	*/
	inline void setHeight(int height)
	{
		matrix_height = height;
	}

	/*!
		Getter method to get the matrix vector
		\return a std::vector<float> object
	*/
	inline std::vector<float> getMatrix()
	{
		
		return matrix;
	}

	/*!
		Setter method to set the matrix vector 
		\param a_mat The matrix vector
		Throws an OutOfBoundsException if size of the vector is not equal to the matrix dimensions.
	*/
	inline void setMatrix(std::vector<float> a_mat)
	{
		if(a_mat.size() != matrix_height*matrix_width)
		{
			throw OutOfBoundsException("size is not equal to the initial dimensions");
		}
		matrix = a_mat;
	}

	/*!
		Method to multiply a matrix with another matrix
		\param b The other matrix
		\return A Matrix denoting the result of the multiplication
	*/
	Matrix multiplyMatrix(Matrix b)
	{

		std::vector<float> matrixA = matrix;

		std::vector<float> matrixB = b.getMatrix();
		int returnHeight = getHeight();
		int returnWidth = b.getWidth();
		int common_width_height = getWidth();
		int height_of_b = b.getHeight();

		if(common_width_height != height_of_b)
		{
			
			Matrix invalidInput = Matrix(0, 0);
			return invalidInput;
		}

		Matrix returnedMatrixType = Matrix(returnHeight, returnWidth);
		
		std::vector<float> returnMatrix = returnedMatrixType.getMatrix();
		for(int i=0;i<returnHeight;i++)
		{
			for(int k=0;k<common_width_height;k++)
			{
				for(int j=0;j<returnWidth;j++)
				{
					
					returnMatrix[i*returnWidth+j] += matrixA[i*common_width_height+k] 
													* matrixB[k*returnWidth+j];
					
				}
			}
		}

		returnedMatrixType.setMatrix(returnMatrix);
		return returnedMatrixType;
	}

	
	/*!
		Method to multiply a matrix with another matrix
		\return A Matrix denoting the result of the transposition
	*/
	Matrix transpose()
	{
		std::vector<float> this_matrix = getMatrix();
		int transposeHeight = getHeight();
		int transposeWidth = getWidth();
		Matrix transposedMatrix = Matrix(transposeWidth,transposeHeight);
		std::vector<float> returnMatrix = transposedMatrix.getMatrix();
		for(int i=0;i<transposeHeight;i++)
		{
			for(int j=0;j<transposeWidth;j++)
			{
				returnMatrix[j*transposeHeight+i] = this_matrix[i*transposeWidth+j];
			}
		}
		transposedMatrix.setMatrix(returnMatrix);
		
		return transposedMatrix;
	}

private:
	/*!
		Field denoting the width of the matrix
	*/
	int matrix_width;
	/*!
		Field denoting the height of the matrix
	*/
	int matrix_height;
	/*!
		Field denoting the matrix vector
	*/
	std::vector<float> matrix;
	
};



#endif
