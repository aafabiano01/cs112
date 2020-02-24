/* Vec.h provides a simple vector class named Vec.
 * Student Name: Alex Fabiano
 * Date: 9/26/19
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */


#include <cstdlib>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

#ifndef VEC_H_
#define VEC_H_

template <class Item>
class Vec {
public:
	Vec();
	Vec(unsigned size);
	virtual ~Vec();
	Vec(const Vec<Item>& original);
	Vec<Item>& operator=(const Vec<Item>& original);
	unsigned getSize() const;
	void setItem(unsigned index, const Item& it);
	Item& getItem(unsigned) const;
	void setSize(unsigned newSize);
	const bool operator==(const Vec<Item>& v2) const;
	void writeTo(ostream& out) const;
	void readFrom(istream& in);
	const Item& operator[](unsigned index) const;
	Item& operator[](unsigned index);
	bool operator!=(const Vec<Item>& v2) const;
	Vec<Item> operator+(const Vec<Item>& v2) const;
	Vec<Item> operator-(const Vec<Item>&);
	Item operator*(const Vec<Item>& v2) const;
	void readFrom(const string& fileName);
	void writeTo(const string& fileName) const;
private:
	unsigned mySize;
	Item * myArray;
	friend class VecTester;
};

/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name: Alex Fabiano
 * Date: 9/26/19
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */


//Default constructor, allows for the creation of a "Vec (name);" without any values provided.
template<class Item>
Vec<Item>::Vec(){
	mySize = 0;
	myArray = NULL;
}
//Destructor, makes sure the program does not leak memory in its methods by deleting the
//local Vecs when they are done being used.
template<class Item>
Vec<Item>::~Vec() {
	if(mySize > 0) {
		for(unsigned i = 0; i < mySize; i++) {
			myArray[i] = 0;
		}
	}
	delete [] myArray;
	mySize = 0;
	myArray = NULL;
}
//Explicit Value Constructor, allows for the creation of a Vec of specified size.
template<class Item>
Vec<Item>::Vec(unsigned size) {
	mySize = size;
	if (size == 0) { myArray = NULL; }
	else {
	  myArray = new Item[size]();
	}
}
//Copy Constructor, allows for the creation of deep copies.
template<class Item>
Vec<Item>::Vec(const Vec<Item>& original) {
	mySize = original.mySize;
	if (mySize == 0) {
		myArray = NULL;
	}

	else {
		myArray = new Item[mySize]();
		for(unsigned i = 0; i < mySize; i++) {
			myArray[i] = original.myArray[i];
		}
	}
}
//Assignment Operator, allows for the setting of Vecs to equal other Vecs,
//allows for operation chaining.
//Takes a Vec, does not change it.
//Returns your new Vec.
template<class Item>
Vec<Item>& Vec<Item>::operator=(const Vec<Item>& original) {
	if (myArray == original.myArray) {
		return *this;
	}
	delete [] myArray;
	mySize = original.mySize;
	if (original.mySize > 0) {
		myArray = new Item[mySize]();
		for (unsigned i = 0; i < mySize; ++i) {
			myArray[i] = original.myArray[i];
		}
	} else {
		myArray = NULL;
	}
	return *this;
}
//getSize returns the size of the Vec.
template<class Item>
unsigned Vec<Item>::getSize() const {
	return mySize;
}
//setItem allows for a single Item in the Vec of Items to have its value changed.
//Takes an index for the change to occur and the Item you want to replace it with.
//Returns nothing.
template<class Item>
void Vec<Item>::setItem(unsigned index, const Item& it) {
	if (myArray == NULL) {
		throw range_error("bruh");
	} else if (index >= mySize) {
		throw range_error("bruh");
	} else if (mySize == 0) {
		throw range_error("bruh");
	}
	else {
		myArray[index] = it;
	}
}
//getItem returns the value of the Vec it is used on at position index.
template<class Item>
Item& Vec<Item>::getItem(unsigned index) const {
	if (myArray == NULL) {
		throw range_error("bruh");
	} else if (index >= mySize) {
		throw range_error("bruh");
	} else if (mySize == 0) {
		throw range_error("bruh");
	}
	else {
		return myArray[index];
	}
}
//setSize either turns a Vec larger by making any values beyond it's original
//0, or makes it smaller by deleting any values past the newSize that it is sent.
//Takes a size to resize the Vec to.
//Returns nothing.
template<class Item>
void Vec<Item>::setSize(unsigned newSize) {
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
template<class Item>
const bool Vec<Item>::operator==(const Vec<Item>& v2) const {
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
template<class Item>
void Vec<Item>::writeTo(ostream& out) const {
		for (unsigned i = 0; i < mySize; i++) {
			out << myArray[i] << " ";
		}
		out << endl;
}
//readFrom reads values from an istream, like a file, and puts them into a Vec.
//Takes an istream to read from.
//Returns nothing.
template<class Item>
void Vec<Item>::readFrom(istream& in) {
	string turnToItem;
	for (unsigned i = 0; i < mySize; i++) {
		double value;
		in >> value;
		myArray[i] = value;
	}
}
//operator[] allows for the comparison of Vec[]s by finding the Item at the index
//by acting as the Item at that index.
//Takes an index for the operator to return.
//Returns the Item at that index.
template<class Item>
const Item& Vec<Item>::operator[](unsigned index) const {
	if (myArray == NULL) {
		throw range_error("bruh");
	} else if (index >= mySize) {
		throw range_error("bruh");
	} else {
		return myArray[index];
	}
}
//operator[] allows for Vec[]s to be set to a value by acting as the Item at that index.
//Takes an index for the operator to return.
//Returns the Item at that index.
template<class Item>
Item& Vec<Item>::operator[](unsigned index) {
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
template<class Item>
bool Vec<Item>::operator!=(const Vec<Item>& v2) const {
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
template<class Item>
Vec<Item> Vec<Item>::operator+(const Vec<Item>& v2) const{
	if (mySize != v2.mySize) {
		throw invalid_argument("bruh");
	}
	Vec<Item> v3(mySize);
	for (unsigned i = 0; i < mySize; i++) {
		v3[i] = myArray[i] + v2[i];
	}
	return v3;
}
//operator- allows 2 Vecs of equal size to be subtracted from each other. v1[1]-v2[1].
//Used on a Vec, takes a Vec.
//Returns second Vec subtracted from first Vec.
template<class Item>
Vec<Item> Vec<Item>::operator-(const Vec& v2) {
	if (mySize != v2.mySize) {
		throw invalid_argument("bruh");
	}
	Vec<Item> v3(mySize);
	for (unsigned i = 0; i < mySize; i++) {
		v3[i] = myArray[i] - v2[i];
	}
	return v3;
}
//operator* allows 2 Vecs of equal size to be multiplied together, then all of their
//values are added into one sum.
//Used on a Vec, takes a Vec.
//Returns a single Item of all the Items multiplied and added together.
template<class Item>
Item Vec<Item>::operator*(const Vec<Item>& v2) const{
	if (mySize != v2.mySize) {
		throw invalid_argument("bruh");
	}
	Item v3 = 0.0;
	for (unsigned i = 0; i < mySize; i++) {
		v3 += myArray[i] * v2.myArray[i];
	}
	return v3;
}
//readFrom is sent a filename, reads the first line in the file as a size, then
//reads the rest of the file's lines as values in a Vec.
//Takes a filename.
//Returns nothing.
template<class Item>
void Vec<Item>::readFrom(const string& fileName) {
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
//writeTo prints all the values in a Vec to a file. The first line in the file will be
//the size of the Vec.
//Takes a filename.
//Returns nothing.
template<class Item>
void Vec<Item>::writeTo(const string& fileName) const {
	ofstream fout(fileName);
	fout << mySize << endl;
	for (unsigned i = 0; i < mySize; i++) {
		fout << myArray[i] << endl;
	}
	fout.close();
}

#endif /*VEC_H_*/
