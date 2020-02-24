/* Vec.h provides a simple vector class named Vec.
 * Student Name:
 * Date:
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
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
	Vec(unsigned);
	virtual ~Vec();
	Vec(const Vec<Item>&);
	Vec<Item>& operator=(const Vec<Item>&);
	unsigned getSize() const { return mySize; }
	void setItem(unsigned, const Item&);
	Item& getItem(unsigned) const;
	void setSize(unsigned);
	bool operator==(const Vec<Item>&) const;
	void writeTo(ostream&) const;
	void readFrom(istream&);
	Item& operator[](unsigned);
	const Item& operator[](unsigned) const;
	bool operator!=(const Vec<Item>&) const;
	Vec<Item> operator+(const Vec<Item>&);
	Vec<Item> operator-(const Vec<Item>&);
	Item operator*(const Vec<Item>&);
	void readFrom(const char*);
	void writeTo(const char*) const;

private:
	unsigned mySize;
	Item * myArray;
	friend class VecTester;
};

template<class Item>
Vec<Item>::Vec() {
	mySize = 0;
	myArray = NULL;
}

template<class Item>
Vec<Item>::Vec(unsigned size) {
	mySize = size;
	if(size == 0) { myArray = NULL; }
	else { myArray = new Item[size](); }
}

template<class Item>
Vec<Item>::Vec(const Vec& original) {
  mySize = original.mySize;

  // deal with a size 0 array
  if(mySize == 0) { myArray = NULL; }

  // make a new array, and copy the elements
  else {
	  myArray = new Item[mySize]();

  	  for(unsigned i = 0; i < mySize; i++) {
  		  myArray[i] = original.myArray[i];
  	  }
  }
}

template<class Item>
Vec<Item>::~Vec() {
	if(mySize > 0) {
		for(unsigned i = 0; i < mySize; i++) {
			myArray[i] = 0;
		}
	}
	delete [] myArray;
	myArray = NULL;
	mySize = 0;
}

template<class Item>
Vec<Item>& Vec<Item>::operator=(const Vec<Item>& original) {
	// deal with the case that it is myself
	if(&original == this) {
		//cout << "idiotic test case" << endl;
		return *this;
	}

	// otherwise, re-create the vec
	mySize = original.mySize;
	if(mySize == 0) { myArray = NULL; }
	else {
		myArray = new Item[mySize]();
		for(unsigned i = 0; i < mySize; i++) {
			myArray[i] = original.myArray[i];
		}
	}

	return *this;
}

template<class Item>
void Vec<Item>::setItem(unsigned index, const Item& it) {
  if(index >= mySize) {
	  throw range_error("index out of bounds");
//	  return;
  }

  if(mySize == 0) {
	  throw range_error("vec has no size");
  }

  // else set it
  myArray[index] = it;
}

template<class Item>
Item& Vec<Item>::getItem(unsigned index) const {
	if(index >= mySize || mySize == 0) {
		throw range_error("index out of bounds");
	}
	return myArray[index];
}

template<class Item>
void Vec<Item>::setSize(unsigned newSize) {
  // case 1 - size is empty
  if(newSize == 0) {
	  mySize = newSize;

	  delete [] myArray;
	  myArray = NULL;
	  return;
  }

  // case 2 - size is the same
  if(mySize == newSize) { return; }

  // case 3 - newSize is bigger than oldSize
  if(newSize > mySize) {
    Item * newPtr = new Item[newSize]();
    for(unsigned i = 0; i < mySize; i++) {
    	newPtr[i] = myArray[i];
    }

    // cleanup old array
    delete [] myArray;

    // assignments
    mySize = newSize;
    myArray = newPtr;
    return;
  }

  // case 4 - newSize is smaller than oldSize
  if(newSize < mySize) {
	 Item * newPtr = new Item[newSize]();
	 for(unsigned i = 0; i < newSize; i++) {
		 newPtr[i] = myArray[i];
	 }

	 // cleanup old array
	 delete [] myArray;

	 // assignments
	 mySize = newSize;
	 myArray = newPtr;
  }
}

template<class Item>
bool Vec<Item>::operator==(const Vec<Item>& v2) const {
  // size differentials is false
  if(v2.getSize() != mySize) { return false; }

  // size of zero is true
  if(v2.getSize() == 0 && mySize == 0) { return true; }

  // size is the same, check element values
  for(unsigned i = 0; i < mySize; i++) {
	 if(v2.getItem(i) != myArray[i]) { return false; }
  }

  // default is true
  return true;
}

template<class Item>
void Vec<Item>::writeTo(ostream& out) const {
  for(unsigned i = 0; i < mySize; i++) {
	  out << myArray[i] << " " << flush;
  }
}

template<class Item>
void Vec<Item>::readFrom(istream& in) {
  for(unsigned i = 0; i < mySize; i++) {
	  in >> myArray[i];
  }
}

template<class Item>
Item& Vec<Item>::operator[](unsigned index) {
	if(index >= mySize) {
		throw range_error("index out of bounds");
	}
	return myArray[index];
}

template<class Item>
const Item& Vec<Item>::operator[](unsigned index) const {
	if(index >= mySize) {
		throw range_error("index out of bounds");
	}
	return myArray[index];
}

template<class Item>
bool Vec<Item>::operator!=(const Vec<Item>& v2) const {
	if(*this == v2) { return false; }
	return true;
}

template<class Item>
Vec<Item> Vec<Item>::operator+(const Vec<Item>& v2) {
	if(v2.getSize() != mySize) {
		throw invalid_argument("vec sizes are not the same");
	}

	Vec<Item> addVec(mySize);
	for(unsigned i = 0; i < mySize; i++) {
		addVec[i] = myArray[i] + v2[i];
	}

	return addVec;
}

template<class Item>
Vec<Item> Vec<Item>::operator-(const Vec& v2) {
	if(v2.getSize() != mySize) {
		throw invalid_argument("vec sizes are not the same");
	}

	Vec<Item> subVec(mySize);
	for(unsigned i = 0; i < mySize; i++) {
		subVec[i] = myArray[i] - v2[i];
	}

	return subVec;
}

template<class Item>
Item Vec<Item>::operator*(const Vec<Item>& v2) {
	if(v2.getSize() != mySize) {
		throw invalid_argument("vec sizes are not the same");
	}

	double result = 0;
	for(unsigned i = 0; i < mySize; i++) {
		result += (myArray[i] * v2[i]);
	}
	return result;
}

template<class Item>
void Vec<Item>::readFrom(const char* fileName) {
	ifstream fin(fileName);
	assert( fin.is_open() );

	unsigned readSize;
	fin >> readSize;

	if(readSize != mySize) {
		setSize(readSize);
	}

	readFrom(fin);
	fin.close();
}

template<class Item>
void Vec<Item>::writeTo(const char* fileName) const {
	ofstream fout(fileName);
	assert( fout.is_open() );

	fout << mySize << endl;
	for(unsigned i = 0; i < mySize; i++) {
		fout << myArray[i] << endl;
	}
	fout << endl;
	fout.close();
}

#endif /*VEC_H_*/
