/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 * Student Name: Zachary Clark and Alexander Fabiano
 * Date: 10/5/2019
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "Vec.h"

typedef double Item;

class Matrix {

public:
	Matrix();
	Matrix(unsigned rows, unsigned columns);
	Vec<Item>& operator[](unsigned index);
	const Vec<Item>& operator[](unsigned index) const;
	bool operator==(const Matrix& m2) const;
	const bool operator!=(const Matrix& m2) const;
	void readFrom(istream& in);
	void readFrom(const string fileName);
	void writeTo(ostream& out) const;
	void writeTo(const string& fileName) const;
	Matrix operator+(const Matrix& mat2) const;
	Matrix operator-(const Matrix& mat2) const;
	void operator+=(const Matrix& mat2);
	void operator-=(const Matrix& mat2);
	Matrix getTranspose() const;

	unsigned getRows() const { return myRows; }
	unsigned getColumns() const { return myColumns; }

private:
	unsigned myRows;
	unsigned myColumns;
	Vec< Vec<Item> > myVec;

	friend class MatrixTester;

};

#endif
