#include "Matrix_3x3.h"


/// Given three linear equations like this:
/// a1 * x + b1 * y + c1 * z = d1
/// a2 * x + b2 * y + c2 * z = d2
/// a3 * x + b3 * y + c3 * z = d3
/// We can represent them with metrices like this:
/// [a1 b1 c1][x] = [d1]
/// [a2 b2 c2][y] = [d2]
/// [a3 b3 c3][z] = [d3]
/// param	matrix1	a 3x3 matrix with the values for a1->3, b1->3, and c1->3
/// param	matrix2	a 3x1 matrix with the values for d1, d2, and d3
/// returns	a 3x1 matrix with the values xyz
struct Matrix_3x1 Matrix_3x3_Cramers_Rule(const struct Matrix_3x3 *matrix1, const struct Matrix_3x1 *matrix2)
{
	float denominator = Matrix_3x3_Determinant(matrix1);

	struct Matrix_3x3 temp;

	Matrix_3x3_Init(&temp, 
		Matrix_3x1_Element(matrix2, 1, 1), Matrix_3x3_Element(matrix1, 1, 2), Matrix_3x3_Element(matrix1, 1, 3), 
		Matrix_3x1_Element(matrix2, 2, 1), Matrix_3x3_Element(matrix1, 2, 2), Matrix_3x3_Element(matrix1, 2, 3), 
		Matrix_3x1_Element(matrix2, 3, 1), Matrix_3x3_Element(matrix1, 3, 2), Matrix_3x3_Element(matrix1, 3, 3));

	float x = Matrix_3x3_Determinant(&temp) / denominator;

	Matrix_3x3_Init(&temp, 
		Matrix_3x3_Element(matrix1, 1, 1), Matrix_3x1_Element(matrix2, 1, 1), Matrix_3x3_Element(matrix1, 1, 3), 
		Matrix_3x3_Element(matrix1, 2, 1), Matrix_3x1_Element(matrix2, 2, 1), Matrix_3x3_Element(matrix1, 2, 3), 
		Matrix_3x3_Element(matrix1, 3, 1), Matrix_3x1_Element(matrix2, 3, 1), Matrix_3x3_Element(matrix1, 3, 3));

	float y = Matrix_3x3_Determinant(&temp) / denominator;

	Matrix_3x3_Init(&temp, 
		Matrix_3x3_Element(matrix1, 1, 1), Matrix_3x3_Element(matrix1, 1, 2), Matrix_3x1_Element(matrix2, 1, 1), 
		Matrix_3x3_Element(matrix1, 2, 1), Matrix_3x3_Element(matrix1, 2, 2), Matrix_3x1_Element(matrix2, 2, 1), 
		Matrix_3x3_Element(matrix1, 3, 1), Matrix_3x3_Element(matrix1, 3, 2), Matrix_3x1_Element(matrix2, 3, 1));

	float z = Matrix_3x3_Determinant(&temp) / denominator;

	struct Matrix_3x1 result;
	Matrix_3x1_Init(&result, x, y, z);
	return result;
}
