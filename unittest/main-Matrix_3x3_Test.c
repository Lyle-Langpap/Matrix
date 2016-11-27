#include <stdio.h>

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

	// Cramer's Rule
	Matrix_3x3_Init(&matrix, 
		 2, -1,  6, 
		-3,  4, -5, 
		 8, -7, -9);

	struct Matrix_3x1 matrix2;
	Matrix_3x1_Init(&matrix2, 10, 11, 12);

	struct Matrix_3x1 solution = Matrix_3x3_Cramers_Rule(&matrix, &matrix2);

	Test_Range_Float("Cramer's Rule X", Matrix_3x1_Element(&solution, 1, 1), 1499.0f / 141.0f, 0.1f);
	Test_Range_Float("Cramer's Rule Y", Matrix_3x1_Element(&solution, 2, 1), 1492.0f / 141.0f, 0.1f);
	Test_Range_Float("Cramer's Rule Z", Matrix_3x1_Element(&solution, 3, 1), -16.0f / 141.0f, 0.01f);

	// Cramer's Rule
	Matrix_3x3_Init(&matrix, 
		 2, -1,  6, 
		-3,  4, -5, 
		 8, -7, -9);

	float denominator = Matrix_3x3_Determinant(&matrix);

	Matrix_3x3_Init(&matrix, 
		10, -1,  6, 
		11,  4, -5, 
		12, -7, -9);

	float x = Matrix_3x3_Determinant(&matrix) / denominator;

	Matrix_3x3_Init(&matrix, 
		 2, 10,  6, 
		-3, 11, -5, 
		 8, 12, -9);

	float y = Matrix_3x3_Determinant(&matrix) / denominator;

	Matrix_3x3_Init(&matrix, 
		 2, -1, 10, 
		-3,  4, 11, 
		 8, -7, 12);

	float z = Matrix_3x3_Determinant(&matrix) / denominator;

	Test_Range_Float("Cramer's Rule X - the long way", x, 1499.0f / 141.0f, 0.1f);
	Test_Range_Float("Cramer's Rule Y - the long way", y, 1492.0f / 141.0f, 0.1f);
	Test_Range_Float("Cramer's Rule Z - the long way", z, -16.0f / 141.0f, 0.01f);

	return 0;
}