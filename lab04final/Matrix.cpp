/* Matrix.cpp defines Matrix class methods.
 * Student Name: Zachary Clark and Alexander Fabiano
 * Date: 10/5/2019
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 */

#include "Matrix.h"

/* Default constructor
 */
Matrix::Matrix() {
	myRows = myColumns = 0;
}

/* Explicit constructor
 * Creates a Matrix with rows rows and columns columns
 * @param rows, columns: the number of rows and columns in the new Matrix.
 */
Matrix::Matrix(unsigned rows, unsigned columns) {
	myRows = rows;
	myColumns = columns;
	myVec.setSize(rows);
	for (unsigned i = 0; i < rows; i++) {
		myVec[i].setSize(columns);
	}
}

/* Assignment subscript operator
 * @param: index, the index of the Vector which can be modified
 * Returns: the Vector which corresponds to row index.
 */
Vec<Item>& Matrix::operator[](unsigned index) {
	if ( index < myRows ) {
		return myVec[index];
	} else {
		throw std::range_error("Index out of range!");
	}
}

/* Retrieval subscript operator
 * @param: index, the index of the Vector which will be retrieved
 * Returns: the Vector which corresponds to row index.
 */
const Vec<Item>& Matrix::operator[](unsigned index) const {
	if ( index < myRows ) {
		return myVec[index];
	} else {
		throw std::range_error("Index out of range!");
	}
}

/* Equality operator
 * @param: m2, a Matrix which will be compared to this matrix
 * Returns: Whether or not the two matrices are equal
 */
bool Matrix::operator==(const Matrix& m2) const {
	if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
		return false;
	} else {
		return myVec == m2.myVec;
	}
}

/* Inequality operator
 * @param: m2, the matrix which will be compared to this matrix
 * Returns: The opposite of (this vector == m2).
 *
 * Written by Alexander Fabiano
 */
const bool Matrix::operator!=(const Matrix& m2) const {
    return !(*this == m2);
}

/* Read from an istream
 * @param: in, an istream
 * Precondition: Our matrix already has the proper number of rows and columns
 * Postcondition: Our matrix has been populated with the data from in
 *
 * Written by Alexander Fabiano
 */
void Matrix::readFrom(istream& in) {
    for (unsigned i = 0; i < myRows; i++) {
        for (unsigned j = 0; j < myColumns; j++) {
            in >> myVec[i][j];
        }
    }
}

/* Read from a filename
 * @param: fileName, the name of the file which we will use to read in data
 * Precondition: fileName contains matrix data where the first line contains the number of rows and columns
 * Postcondition: myRows and myColumns have been set according to the first line of the file, and the Matrix has been populated with the remained of the data
 *
 * Written by Zachary Clark
 */
void Matrix::readFrom(const string fileName) {

	ifstream fin(fileName);
	assert( fin.is_open() );

	fin >> myRows >> myColumns;
	myVec.setSize(myRows);

	for (unsigned i = 0; i < myRows; i++) {
		myVec[i].setSize(myColumns);
	}

	readFrom(fin);
	fin.close();
}

/* Write the Matrix to an ostream
 * @param: out, an ostream
 * Postcondition: Our matrix's data has been written to the ostream
 *
 * Written by Zachary Clark
 */
void Matrix::writeTo(ostream& out) const {
	for (unsigned i = 0; i < myRows; i++) {
		for (unsigned j = 0; j < myColumns; j++) {
			out << myVec[i][j] << "\t" << flush;
		}
		out << "\n" << flush;
	}
}

/* Write the Matrix to a file of name fileName
 * @param: fileName, the string which refers to the file we should write.
 * Postcondition: myRows and myColumns have been written to the first line of the file, and the remainder of the data has been written to the latter part of the file
 *
 * Written by Alexander Fabiano
 */
void Matrix::writeTo(const string& fileName) const {
    ofstream fout(fileName);
    fout << myRows << "\t" << myColumns << endl;
    for (unsigned i = 0; i < myRows; i++) {
        for (unsigned f = 0; f < myColumns; f++) {
            fout << myVec[i][f] << "\t";
        }
        //writeTo(fout);
        fout << "\n";
    }
    fout.close();
}

/* Addition operator
 * @param: m2, the Matrix which will be added to our matrix
 * Returns: A matrix in which each element of m2 has been added to the corresponding element of this matrix.
 *
 * Written by Alexander Fabiano
 */
Matrix Matrix::operator+(const Matrix& m2) const {
    if ( myRows != m2.getRows() || myColumns != m2.getColumns() ) {
        throw invalid_argument("bruh");
    }
    Matrix m3(myRows, myColumns);
    for (unsigned i = 0; i < myRows; i++) {
        for (unsigned j = 0; j < myColumns; j++) {
            m3.myVec[i][j] = myVec[i][j] + m2.myVec[i][j];
        }
    }
    return m3;
}

/* Subtraction operator
 * @param: mat2, the Matrix which will be subtracted from our matrix
 * Returns: A matrix in which each element of mat2 has been subtracted fom the corresponding element of this matrix.
 *
 * Written by Zachary Clark
 */
Matrix Matrix::operator-(const Matrix& mat2) const {
	Matrix diff(myRows, myColumns);

	if ( myRows != mat2.getRows() || myColumns != mat2.getColumns() ) {
		throw invalid_argument("Matrices are not the same size!");
	} else {
		for (unsigned i = 0; i < myRows; i++) {
			for (unsigned j = 0; j < myColumns; j++) {
				diff[i][j] = myVec[i][j] - mat2[i][j];
			}
		}

	}

	return diff;
}

/* Addition assignment operator
 * @param: mat2, the matrix which will be added to this matrix
 * Postcondition: Each element of mat2 has been added to the corresponding element of this matrix
 *
 * Written by Zachary Clark because we were lazy in the application portion
 */
void Matrix::operator+=(const Matrix& mat2) {
	*this = *this + mat2;
}

/* Subtraction assignment operator
 * @param: mat2, the matrix which will be subtracted from this matrix
 * Postcondition: Each element of mat2 has been subtracted from the corresponding element of this matrix
 *
 * Written by Zachary Clark because we were lazy in the application portion
 */
void Matrix::operator-=(const Matrix& mat2) {
	*this = *this - mat2;
}

/* Transposition operator
 * Precondition: Our matrix is, in fact, a matrix
 *
 * Written by Zachary Clark
 */
Matrix Matrix::getTranspose() const {
	Matrix transpose(myColumns, myRows);

	for (unsigned i = 0; i < myRows; i++) {
		for (unsigned j = 0; j < myColumns; j++) {
			transpose[j][i] = myVec[i][j];
		}
	}

	return transpose;
}


