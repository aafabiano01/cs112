/* Vec.h provides a simple vector class named Vec.
 * Student Name: Zachary Clark and Alexander Fabiano
 * Date: 9-27-19
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

template<class Item>

class Vec {
public:
	Vec();
	Vec(unsigned size);
	Vec(const Vec& original);
	virtual ~Vec();
	Vec& operator=(const Vec& original);
	unsigned getSize() const { return mySize; }
	void setItem(unsigned index, const Item& it);
	Item getItem(unsigned index) const;
	void setSize(unsigned newSize);
	bool operator==(const Vec& v2) const;
	void writeTo(ostream& out) const;
	void readFrom(istream& in);
	const Item& operator[](unsigned index) const;
	Item& operator[](unsigned index);
	bool operator!=(const Vec& v2);
	void readFrom(const string fileName);
	void writeTo(const string fileName);
	Vec operator+(const Vec& v1);
	Vec operator-(const Vec& v1);
	double operator*(const Vec& v1);
	
private:
	unsigned mySize;
	Item* myArray;
	friend class VecTester;

};

template<class Item>
Vec<Item>::Vec() {
	mySize = 0;
	myArray = nullptr;
}

/* Explicit constructor
 * @param: size, an unsigned which will be the size of the vector
 * Returns a default vector of size size and with a pointer to its array.
 */
template<class Item>
Vec<Item>::Vec(unsigned size) {
	mySize = size;
	if ( size > 0 ) {
		myArray = new Item[size]();
	} else {
		myArray = nullptr;
	}
}

/* Copy constructor
 * @param: Original vector, which will be copied into the new vector.
 * Precondition: original is a vector which will be copied
 * Returns a deep copy of vector original.
 */
template<class Item>
Vec<Item>::Vec(const Vec& original) {
	mySize = original.mySize;
	if ( mySize > 0 ) {
		myArray = new Item[mySize];
		for ( unsigned i = 0; i < mySize; i++ ) {
			myArray[i] = original.myArray[i];
		}
	} else {
		myArray = nullptr;
	}
}

/* Vector destructor
 * Deallocates the memory used by the vector, and resets its size and pointer to 0 and nullptr, respectively.
 */
template<class Item>
Vec<Item>::~Vec() {
	delete [] myArray;
	myArray = nullptr;
	mySize = 0;
}

/* Assignment operator
 * @param: original is a vector, to which this vector will be "turned into"
 * Precondition: original is a vector
 * Returns a vector which has been "turned into" original.
 */
template<class Item>
Vec<Item>& Vec<Item>::operator=(const Vec& original) {
	if ( this != &original ) {

		if ( mySize != 0 && mySize != original.mySize ) {
			delete [] myArray;
			myArray = nullptr;
		}

		if ( original.mySize == 0 ) {
			myArray = nullptr;
			mySize = 0;
		}

		if ( mySize != original.mySize  ) {
			myArray = new Item[original.mySize];
			mySize = original.mySize;
		}

		for ( unsigned i = 0; i < mySize; i++ ) {
			myArray[i] = original.myArray[i];
		}
	}
	return *this;
}

/* Sets an item inside the vector
 * @param: index, the index of the item to change
 * @param: it, the item we will set the index to
 * Postcondition: The item at index index has been changed to Item it.
 */
template<class Item>
void Vec<Item>::setItem(unsigned index, const Item& it) {
	if ( index < mySize && myArray != nullptr ) {
		myArray[index] = it;
	} else {
		throw std::range_error("Index out of range!");
	}
}

/* Returns the item at index index
 * @param: index, the index of the item to retrieve
 */
template<class Item>
Item Vec<Item>::getItem(unsigned index) const {
	if ( index < mySize && myArray != nullptr ) {
		return myArray[index];
	} else {
		throw std::range_error("Index out of range!");
	}
}

/* Sets the size of the vector to newSize
 * @param: newSize, the size which the vector will be converted to.
 */
template<class Item>
void Vec<Item>::setSize(unsigned newSize) {

	// If they are not already newSize...
	if ( mySize != newSize ) {

		// Set to zero and deallocate memory if newSize is zero.
		if ( newSize == 0 ) {
			delete [] myArray;
			myArray = nullptr;
			mySize = 0;

		// Create a new array and copy the items into it
		} else {
			Item *newArray = new Item[newSize]();
			if ( mySize != 0 ) {
				for ( unsigned i = 0; i < mySize; i++ ) {
					newArray[i] = myArray[i];
					if ( i + 1 == newSize ) break;
				}
				delete [] myArray;
			}

			// Update the variables to reflect the changes.
			myArray = newArray;
			mySize = newSize;
		}
	}
}

/* Equality operator
 * @param: v2, the vector which will be compared to this vector
 * Returns whether or not all of v2's Items are equal to this vector's Items, as well as the sizes being equal.
 */
template<class Item>
bool Vec<Item>::operator==(const Vec& v2) const {
	if ( mySize != v2.mySize ) return false;

	for ( unsigned i = 0; i < mySize; i++ ) {
		if ( myArray[i] != v2.myArray[i] ) return false;
	}

	return true;
}

/* Write the vector to an ostream
 * @param: out, an ostream to which we will write the vector
 * Postcondition: Our vector has been written to out
 */
template<class Item>
void Vec<Item>::writeTo(ostream& out) const {
	for ( unsigned i = 0; i < mySize; i++ ) {
		out << myArray[i] << endl;
	}
}

/* Read a vector from an istream
 * @param: in, the istream from which we will read the vector
 * Postcondition: This vector has been set to the contents of the istream
 */
template<class Item>
void Vec<Item>::readFrom(istream& in) {
	for( unsigned i = 0; i < mySize; i++ ) {
		in >> myArray[i];
	}
}

/* Retrieval subscript operator
 * @param: index, the index of the Item to return
 * Returns the Item at index index
 *
 * Written by Christian Mutschler
 */
template<class Item>
const Item& Vec<Item>::operator[](unsigned index) const {
	if ( index < mySize && myArray != nullptr ) {
			return myArray[index];
		} else {
			throw std::range_error("Index out of range!");
		}
}

/* Assignment subscript operator
 * @param: index, the index to modify
 * Returns a reference to the item which will be modified.
 *
 * Written by Zachary Clark
 */
template<class Item>
Item& Vec<Item>::operator[](unsigned index) {
	if ( index < mySize && myArray != nullptr ) {
			return myArray[index];
		} else {
			throw std::range_error("Index out of range!");
		}
}

/* Inequality operator
 * @param: v2, a vector to check inequality against
 * Returns the opposite of equality operator
 *
 * Written by Zachary Clark
 */
template<class Item>
bool Vec<Item>::operator!=(const Vec& v2) {
	return !(*this == v2);
}

/* Read the vector in from fileName
 * @param: fileName, a string to which we will open an ifstream and read a vector from
 * Postcondition: The contents of our vector have been read in from the file, where the first line of the file becomes mySize.
 *
 * Written by Zachary Clark
 */
template<class Item>
void Vec<Item>::readFrom(const string fileName) {
	ifstream fin(fileName);
	assert( fin.is_open() );
	unsigned size = 0;
	fin >> size;
	setSize(size);
	readFrom(fin);
	fin.close();
}

/* Write the vector to fileName
 * @param: fileName, the name of the file which we will write the vector to
 * Precondition: mySize is the size of the vector we want to write, and myArray contains the values we want to write
 * Postcondition: fileName's first line is mySize, and subsequent lines are the elements of the vector
 *
 * Written by Christian Mutschler
 */
template<class Item>
void Vec<Item>::writeTo(const string fileName) {
	ofstream fin(fileName);
	assert( fin.is_open() );
	fin << mySize << endl;
	writeTo(fin);
	fin.close();
}

/* Addition operator
 * @param: v1, the vector which will be added to our vector
 * Returns a vector in which the elements of our vector and v1 have been added to each other
 *
 * Written by Zachary Clark
 */
template<class Item>
Vec<Item> Vec<Item>::operator+(const Vec& v1) {
	Vec sum(mySize);
	if ( mySize != v1.mySize ) {
		throw invalid_argument("Vectors are not the same size!");
	} else {
		for ( unsigned i = 0; i < mySize; i++ ) {
			sum[i] = myArray[i] + v1[i];
		}
	}
	return sum;
}

/* Subtraction operator
 * @param: v1, the vector which will be subtracted from our vector
 * Returns a vector in which the elements of our vector and v1 have been subtracted from each other
 *
 * Written by Christian Mutschler
 */
template<class Item>
Vec<Item> Vec<Item>::operator-(const Vec<Item>& v1) {
	Vec<Item> diff(mySize);
	if ( mySize != v1.mySize ) {
		throw invalid_argument("Vectors are not the same size!");
	} else {
		for ( unsigned i = 0; i < mySize; i++ ) {
			diff[i] = myArray[i] - v1[i];
		}
	}
	return diff;
}

/* Multiplication (dot product) operator
 * @param: v1, the vector we will multiply with this vector
 * Returns the dot product of our vector and v1
 *
 * Written by Christian Mutschler
 */
template<class Item>
double Vec<Item>::operator*(const Vec& v1) {
	double prod = 0;
	if ( mySize != v1.mySize ) {
		throw invalid_argument("Vectors are not the same size!");
	} else {
		for ( unsigned i = 0; i < mySize; i++ ) {
			prod += myArray[i] * v1[i];
		}
	}
	return prod;
}

#endif /*VEC_H_*/
