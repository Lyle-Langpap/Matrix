#ifndef MATRIX_3X3_H_
#define MATRIX_3X3_H_


#include <math.h>

#include "Matrix_3x1.h"


struct Matrix_3x3 {
	/// [0, 1, 2]
	/// [3, 4, 5]
	/// [6, 7, 8]
	float element [9];
};


static inline void Matrix_3x3_Init(
		struct Matrix_3x3 *matrix, 
		const float m11, const float m12, const float m13, 
		const float m21, const float m22, const float m23, 
		const float m31, const float m32, const float m33)
{
	matrix->element[0] = m11;
	matrix->element[1] = m12;
	matrix->element[2] = m13;
	matrix->element[3] = m21;
	matrix->element[4] = m22;
	matrix->element[5] = m23;
	matrix->element[6] = m31;
	matrix->element[7] = m32;
	matrix->element[8] = m33;
}


static inline float Matrix_3x3_Determinant(const struct Matrix_3x3 *matrix)
{
	const float *p = matrix->element;
	float result = p[0] * (p[4] * p[8] - p[5] * p[7]);
	result -= p[1] * (p[3] * p[8] - p[5] * p[6]);
	result += p[2] * (p[3] * p[7] - p[4] * p[6]);
	return result;
}


/// param	row	starting from 1, not zero, the row of the element to return
/// param	column	starting from 1, not zero, the column of the element to return
static inline float Matrix_3x3_Element(const struct Matrix_3x3 *matrix, const int row, const int column)
{
	int index = (row - 1) * 3 + (column - 1);
	return matrix->element[index];
}

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
struct Matrix_3x1 Matrix_3x3_Cramers_Rule(const struct Matrix_3x3 *matrix1, const struct Matrix_3x1 *matrix2);


#endif
