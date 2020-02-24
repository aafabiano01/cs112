/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name: Alex Fabiano
 * Date: 9/26/19
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */
 
#include "Vec.h"
#include <cstdlib>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <string>
#include <cassert>
using namespace std;
//Default constructor, allows for the creation of a "Vec (name);" without any values provided.
//Made by Alex
Vec::Vec(){
	mySize = 0;
	myArray = NULL;
}
//Destructor, makes sure the program does not leak memory in its methods by deleting the
//local Vecs when they are done being used.
//Made by Alex
Vec::~Vec() {
	delete [] myArray;
	mySize = 0;
	myArray = NULL;
}
//Explicit Value Constructor, allows for the creation of a Vec of specified size.
//Made by Alex
Vec::Vec(unsigned size) {
	mySize = size;
	if (size > 0) {
		Item* newMyArray = nullptr;
		delete[] newMyArray;
		newMyArray = new Item[size]();
		myArray = newMyArray;
	} else {
		myArray = NULL;
	}
}
//Copy Constructor, allows for the creation of deep copies.
//Made by Alex
Vec::Vec(const Vec& original) {
	mySize = original.mySize;
	if (original.mySize > 0) {
		Item* newMyArray = nullptr;
		delete[] newMyArray;
		newMyArray = new Item[original.mySize]();
		for (unsigned i = 0; i < original.mySize; ++i) {
			newMyArray[i] = original.myArray[i];
		}
		myArray = newMyArray;
	} else {
		myArray = NULL;
	}
}
//Assignment Operator, allows for the setting of Vecs to equal other Vecs,
//allows for operation chaining.
//Takes a Vec, does not change it.
//Returns your new Vec.
//Made by Alex
Vec& Vec::operator=(const Vec& original) {
	if (myArray == original.myArray) {
		return *this;
	}
	delete [] myArray;
	mySize = original.mySize;
	if (original.mySize > 0) {
		Item* newMyArray = nullptr;
		delete[] newMyArray;
		newMyArray = new Item[original.mySize]();
		for (unsigned i = 0; i < original.mySize; ++i) {
			newMyArray[i] = original.myArray[i];
		}
		myArray = newMyArray;
	} else {
		myArray = NULL;
	}
	return *this;
}
//getSize returns the size of the Vec.
//Made by Alex
unsigned Vec::getSize() const {
	return mySize;
}
//setItem allows for a single Item in the Vec of Items to have its value changed.
//Takes an index for the change to occur and the Item you want to replace it with.
//Returns nothing.
//Made by Alex
void Vec::setItem(unsigned index, const Item& it) {
	if (myArray == NULL) {
		throw range_error("bruh");
	} else if (index >= mySize) {
		throw range_error("bruh");
	} else {
		myArray[index] = it;
	}
}
//getItem returns the value of the Vec it is used on at position index.
//Made by Alex
Item Vec::getItem(unsigned index) const {
	if (myArray == NULL) {
		throw range_error("bruh");
	} else if (index >= mySize) {
		throw range_error("bruh");
	} else {
		return myArray[index];
	}
}
//setSize either turns a Vec larger by making any values beyond it's original
//0, or makes it smaller by deleting any values past the newSize that it is sent.
//Takes a size to resize the Vec to.
//Returns nothing.
//Made by Alex
void Vec::setSize(unsigned newSize) {
	Item * arrayThatCanExpand = nullptr;
	delete [] arrayThatCanExpand;
	arrayThatCanExpand = new Item[newSize];
	if (newSize == 0)
	{
		delete [] myArray;
		myArray = 0;
		mySize = 0;
		return;
	} else if (newSize == mySize) {
		return;
	} else if (newSize < mySize) {
		for (unsigned i = 0; i < newSize; i++) {
			arrayThatCanExpand[i] = myArray[i];
		}
	} else if (newSize > mySize) {
		for (unsigned i = 0; i < mySize; i++) {
			arrayThatCanExpand[i] = myArray[i];
		}
		for (unsigned i = mySize; i < newSize; i++) {
			arrayThatCanExpand[i] = 0;
		}
	}
	mySize = newSize;
	delete [] myArray;
	myArray = arrayThatCanExpand;
}
//operator== allows for the comparison of 2 Vecs in a true false statement.
//Takes a Vec.
//Returns true or false.
//Made by Alex
bool Vec::operator==(const Vec& v2) const {
	if (mySize != v2.mySize) {
		return false;
	}
	for (unsigned i = 0; i < v2.getSize(); ++i) {
		if (myArray[i] != v2.myArray[i])
			return false;
	}
	return true;
}
//writeTo prints out all the values in a Vec it is sent to "out".
//Takes an ostream to print out to.
//Returns nothing.
//Made by Alex
void Vec::writeTo(ostream& out) const {
		for (unsigned i = 0; i < mySize; i++) {
			out << myArray[i] << " ";
		}
		out << endl;
}
//readFrom reads values from an istream, like a file, and puts them into a Vec.
//Takes an istream to read from.
//Returns nothing.
//Made by Alex
void Vec::readFrom(istream& in) {
	string turnToItem;
	for (unsigned i = 0; i < mySize; i++) {
		double value;
		in >> value;
		myArray[i] = value;
	}
}

/*
 * Written by David Reidsma
 * Get an Item at a specific index.
 * @param: index, an unsigned integer index.
 * Returns: The Item at the index.
 */
const Item& Vec::operator [](unsigned index) const {
	if (mySize == 0)
		throw range_error("Cannot get element in array of length 0");

	if (index > mySize - 1)
		throw range_error("Index out of bounds");

	return myArray[index];
}

//operator[] allows for Vec[]s to be set to a value by acting as the Item at that index.
//Takes an index for the operator to return.
//Returns the Item at that index.
//Made by Alex
Item& Vec::operator[](unsigned index) {
	if (myArray == NULL) {
		throw range_error("bruh");
	} else if (index >= mySize) {
		throw range_error("bruh");
	} else {
		return myArray[index];
	}
}
//operator=! allows for the comparison of 2 Vecs in a true false statement.
//Takes a Vec.
//Returns true or false.
bool Vec::operator!=(const Vec& v2) const {
	if (mySize != v2.mySize) {
		return true;
	}
	for (unsigned i = 0; i < v2.getSize(); ++i) {
		if (myArray[i] != v2.myArray[i])
			return true;
	}
	return false;
}
//operator+ allows 2 Vecs of equal size to be added together, each Item adding to
//its corresponding item. Like v1[1] + v2[1].
//Used on a Vec, takes a Vec.
//Returns the two Vecs added together.
Vec Vec::operator+(const Vec& v2) const{
	if (mySize != v2.mySize) {
		throw invalid_argument("bruh");
	}
	Vec v3(mySize);
	for (unsigned i = 0; i < mySize; i++) {
		v3.setItem(i, myArray[i] + v2.myArray[i]);
	}
	return v3;
}

/*
 * Written by David Reidsma
 * Get a Vec where every Item at index i equals the element in this Vec at i minus the value in the passed-in Vec at i.
 * @param: vec2, a vector to subtract from this vector.
 * Returns: a vector with subtracted values.
 */
const Vec& Vec::operator -(const Vec& vec2) const {
	if (mySize != vec2.mySize)
		throw invalid_argument("Cannot add vectors with different sizes");

	Vec *vec3 = new Vec(mySize);
	for (unsigned i = 0; i < mySize; i++) {
		Item item1 = myArray[i];
		Item item2 = vec2[i];
		Item item3 = item1 - item2;

		(*vec3)[i] = item3;
	}
	return *vec3;
}

/*
 * Written by David Reidsma
 * Get the dot product of this Vec and another.
 * @param: vec2, a vector to combine with to get a dot product.
 * Returns: the dot product of this Vec and a passed in Vec.
 */
double Vec::operator *(const Vec& v2) const {
	if (mySize != v2.mySize)
		throw invalid_argument("Cannot add vectors with different sizes");

	double dotProduct = 0;
	for (unsigned i = 0; i < mySize; i++) {
		Item item1 = myArray[i];
		Item item2 = v2[i];
		dotProduct += item1 * item2;
	}

	return dotProduct;
}

//readFrom is sent a filename, reads the first line in the file as a size, then
//reads the rest of the file's lines as values in a Vec.
//Takes a filename.
//Returns nothing.
void Vec::readFrom(const string& fileName) {
	fstream inFileStr(fileName.c_str(), ios::in);
	string toNumValues;
	getline(inFileStr, toNumValues);
	double size = std::stod (toNumValues);
	setSize(size);
	double storageForExpand;
	for (unsigned i = 0; i < size; i++) {
		getline(inFileStr, toNumValues);
		storageForExpand = stoul(toNumValues, nullptr, 0);
		setItem(i, storageForExpand);
	}
	inFileStr.close();
}

/*
 * Written by David Reidsma
 * Save data from this Vec to a file.
 * @param: fileName, the name of the file.
 */
void Vec::writeTo(const string& fileName) const {
	ofstream out(fileName);
	out << mySize << '\n';
	writeTo(out);
	out.close();
}
