#ifndef MATRIX_3X1_H_
#define MATRIX_3X1_H_


#include <math.h>


struct Matrix_3x1 {
	/// [0]
	/// [1]
	/// [2]
	float element [3];
};


static inline void Matrix_3x1_Init(
		struct Matrix_3x1 *matrix, 
		const float m11, const float m21, const float m31)
{
	matrix->element[0] = m11;
	matrix->element[1] = m21;
	matrix->element[2] = m31;
}


/// param	row	starting from 1, not zero, the row of the element to return
/// param	column	for a 3x1 matrix, this must always be one
static inline float Matrix_3x1_Element(const struct Matrix_3x1 *matrix, const int row, const int column)
{
	int index = (row - 1) + (column - 1);
	return matrix->element[index];
}


#endif
