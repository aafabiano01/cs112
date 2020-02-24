/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 * Student Name:
 * Date:
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "Vec.h"

typedef double Item;

class Matrix {
public:

private:
	unsigned myRows;
	unsigned myColumns;
	Vec < Vec<Item> > myVec;
};

#endif
