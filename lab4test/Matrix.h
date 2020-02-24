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
	Matrix();
	unsigned getRows() const {return myRows;}
	unsigned getColumns() const {return myColumns;}
	Matrix(unsigned rows, unsigned columns);
	const Vec<Item>& operator[](unsigned index) const;
	Vec<Item>& operator[](unsigned index);
	const bool operator==(const Matrix& m2) const;
	const bool operator!=(const Matrix& m2) const;
	void readFrom(istream& in);
	Matrix operator+(const Matrix& v2) const;
	void writeTo(const string& fileName) const;
	void readFrom(const string& fileName);
	void writeTo(ostream& out) const;
	Matrix operator-(const Matrix& m2) const;
private:
    unsigned         myRows;
    unsigned         myColumns;
    Vec< Vec<Item> > myVec;
    friend class MatrixTester;
};

#endif
