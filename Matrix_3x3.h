#ifndef MATRIX_3X3_H_
#define MATRIX_3X3_H_


#include <math.h>


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


#endif
