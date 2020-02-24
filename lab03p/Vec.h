/* Vec.h provides a simple vector class named Vec.
 * Student Name: Alex Fabiano
 * Date: 9/26/19
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
using namespace std;

typedef double Item;

class Vec {
public:
	Vec();
	Vec(unsigned size);
	virtual ~Vec();
	Vec(const Vec& original);
	Vec& operator=(const Vec& original);
	unsigned getSize() const;
	void setItem(unsigned index, const Item& it);
	Item getItem(unsigned index) const;
	void setSize(unsigned newSize);
	bool operator==(const Vec& v2) const;
	void writeTo(ostream& out) const;
	void readFrom(istream& in);
	const Item& operator[](unsigned index) const;
	Item& operator[](unsigned index);
	bool operator!=(const Vec& v2) const;
	Vec operator+(const Vec& v2) const;
	const Vec& operator -(const Vec& vec2) const;
	Item operator*(const Vec& v2) const;
	void readFrom(const string& fileName);
	void writeTo(const string& fileName) const;
private:
	unsigned mySize;
	Item * myArray;
	friend class VecTester;
};

#endif /*VEC_H_*/
