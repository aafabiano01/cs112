/* array.cpp defines "C style" array operations
 *  Created on: Sep 20, 2019
 *      Author: Alex Fabiano
 *      Lab01 in cs112 at Calvin U
 */
 
#include "array.h"
#include <fstream>
#include <iostream>
using namespace std;
#include <cassert>
#include <string>

void initialize(double *a, unsigned size) {
	int val = 0;
	for (unsigned i = 0; i < size; i++) {
		val = i+1;
		a[i] = val;
	}
}
//print outputs every value in an array it is sent of given size
//returns nothing
//requires an array of doubles and a size of type unsigned
void print(double *a, unsigned size) {
	for (unsigned i = 0; i < size; i++) {
		cout << *a << '\t';
		a++;
	}
}		
//average adds together every value in an array, a, of given size, size, then divides that number by size
//returns the average value of all the numbers in the array in type double
//requires an array of doubles and a size of type unsigned
double average(double *a, unsigned size) {
	double averageOfGiven = 0;
	for (unsigned i = 0; i < size; i++) {
		averageOfGiven += *a;
		a++;
	}
	averageOfGiven /= size;
	return averageOfGiven;
}
//sum adds together every value in an array, a, of given size, size
//returns a double containing the sum of all the values of the array combined
//requires an array of doubles and a size of type unsigned
double sum(double *a, unsigned size) {
	double sumOfGiven = 0;
	for (unsigned i = 0; i < size; i++) {
		sumOfGiven += *a;
		a++;
	}
	return sumOfGiven;
}
//read reads values from an istream into the array given, a
//returns nothing
//requires an istream, an array of doubles, and a size of type unsigned
void read(istream& in, double *a, unsigned size) {
	for (unsigned i = 0; i < size; i++) {
		string toNumValues;
		getline(in, toNumValues);
		a[i] = stoul(toNumValues, nullptr, 0);
	}
}
//fill opens an fstream to the filename given, reads the first value as the size of the array it will create, then stores the rest of the values in that array
//fill stores the address of the array in a
//returns nothing
//requires the string of a filename, an array of doubles, and an unsigned
void fill(const string& fileName, double *&a, unsigned &numValues) {
	fstream inFileStr(fileName.c_str(), ios::in);
	assert(inFileStr.is_open());
	string toNumValues;
	getline(inFileStr, toNumValues);
	numValues = stoul(toNumValues, nullptr, 0);
	double* arrayThatCanExpand = nullptr;
	delete[] arrayThatCanExpand;
	arrayThatCanExpand = new double[numValues];
	a = *&arrayThatCanExpand;
	double storageForExpand;
	for (unsigned i = 0; i < numValues; i++) {
		getline(inFileStr, toNumValues);
		storageForExpand = stoul(toNumValues, nullptr, 0);
		arrayThatCanExpand[i] = storageForExpand;
	}
	inFileStr.close();
}
//resize creates a new array given an old array. if the size of the new array is larger than the old one, it takes all the values from the old array and sets any extra
//values to 0. if the new array is smaller than the old array, any values beyond the size of the new array are deleted.
//returns nothing
//requires an array and 2 unsigned sizes
void resize(double *&a, unsigned oldSize, unsigned newSize) {
	double * arrayThatCanExpand = nullptr;
	delete [] arrayThatCanExpand;
	arrayThatCanExpand = a;
	arrayThatCanExpand = new double[newSize];

	if (newSize > oldSize)
	{
		for (unsigned i = 0; i < oldSize; i++) {
			arrayThatCanExpand[i] = a[i];
		}
		for (unsigned i = oldSize; i < newSize; i++) {
			arrayThatCanExpand[i] = 0;
		}
	}
	else if (newSize < oldSize)
	{
		for (unsigned i = 0; i < newSize; i++) {
			arrayThatCanExpand[i] = a[i];
		}
	}
	delete [] a;
	a = arrayThatCanExpand;
}
//concat adds the first 2 arrays together into a dynamically allocated third array.
//returns nothing
//requires 3 arrays of doubles and 3 unsigned sizes.
void concat(double *a1, unsigned size1, double *a2, unsigned size2, double *&a3, unsigned &size3) {
	delete[] a3;
	size3 = size1 + size2;
	a3 = new double[size3];
	for (unsigned i = 0; i < size1; i++) {
		a3[i] = a1[i];
	}
	unsigned a2Counter = 0;
	for (unsigned i = size1; i < size3; i++) {
		a3[i] = a2[a2Counter];
		++a2Counter;
	}
}
