#include "com/braincorp/linalglib/matrixmultiplication/matrixmultiply.hpp"
#include "iostream"
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

/*!
*	Test the execution 5 times.
*/
int main()
{
	srand( 1); 
	random_device rnd_device;
	mt19937 mersenne_engine {rnd_device()};  
	uniform_int_distribution<int> dist {1, 100};

	 auto gen = [&dist, &mersenne_engine](){
                   return dist(mersenne_engine);
               };
    long duration1Total = 0;
    long duration2Total = 0;
    long duration3Total = 0;
    long duration4Total = 0;

    for (int i = 0;i<5;i++)
    {
	    Matrix a1_matrix = Matrix_Multiply_h::Matrix(100,100);
		Matrix b1_matrix = Matrix_Multiply_h::Matrix(100,100);

		std::vector<float> v2(10000);
		std::vector<float> v3(10000);

		generate(v2.begin(), v2.end(), gen);
		generate(v3.begin(), v3.end(), gen);

		a1_matrix.setMatrix(v2);
		b1_matrix.setMatrix(v3);

		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		Matrix c1 = a1_matrix.multiplyMatrix(b1_matrix);
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		auto duration1 = duration_cast<microseconds>( t2 - t1 ).count();
		duration1Total += duration1;
		

		// Transpose of C1
		high_resolution_clock::time_point t3 = high_resolution_clock::now();
		Matrix transposeOfC1 = c1.transpose();
		high_resolution_clock::time_point t4 = high_resolution_clock::now();
		auto duration2 = duration_cast<microseconds>( t4 - t3 ).count();
		duration2Total += duration2;
		


		Matrix a2_matrix = Matrix_Multiply_h::Matrix(1000,1000);
		Matrix b2_matrix = Matrix_Multiply_h::Matrix(1000,1000);

		std::vector<float> v(1000000);
		std::vector<float> v1(1000000);

		generate(v.begin(), v.end(), gen);
		generate(v1.begin(), v1.end(), gen);

		a2_matrix.setMatrix(v);
		b2_matrix.setMatrix(v1);

		high_resolution_clock::time_point t5 = high_resolution_clock::now();
		Matrix c2 = a2_matrix.multiplyMatrix(b2_matrix);
		high_resolution_clock::time_point t6 = high_resolution_clock::now();

		auto duration3 = duration_cast<microseconds>( t6 - t5 ).count();
		duration3Total += duration3;
		

		// Transpose of C1
		high_resolution_clock::time_point t7 = high_resolution_clock::now();
		Matrix transposeOfC2 = c2.transpose();
		high_resolution_clock::time_point t8 = high_resolution_clock::now();
		auto duration4 = duration_cast<microseconds>( t8 - t7 ).count();
		duration4Total += duration4;
		
	}

	cout << "average time for size 100 matrix multiplication over 5 runs in microseconds:::" << duration1Total/5 <<endl;
	cout << "average time for size 100 matrix transpose over 5 runs in microseconds:::" << duration2Total/5 <<endl;
	cout << "average time for size 1000 matrix multiplication over 5 runs in microseconds:::" << duration3Total/5 << endl;
	cout << "average time for size 1000 matrix transpose over 5 runs in microseconds:::" << duration4Total/5 <<endl;

}