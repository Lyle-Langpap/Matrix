#include "Matrix_3x3.h"
#include "Test.h"


int main(int argc, char **argv)
{
	struct Matrix_3x3 matrix;

	Matrix_3x3_Init(&matrix, 
		1,  2,  3, 
		0, -4,  1, 
		0,  3, -1);

	Test_Range_Float(
		"Determinant test 1",
		Matrix_3x3_Determinant(&matrix),
		1.0f,
		0.1f
		);

	Matrix_3x3_Init(&matrix, 
		5, -2,  1, 
		0,  3, -1, 
		2,  0,  7);

	Test_Range_Float(
		"Determinant test 2",
		Matrix_3x3_Determinant(&matrix),
		103.0f,
		0.1f
		);

	return 0;
}