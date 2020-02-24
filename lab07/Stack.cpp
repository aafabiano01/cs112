///* Stack.cpp defines the dynamically allocated (array-based ) Stack operations.
// * Started by Joel Adams, for CS 112 at Calvin University.
// * Student Name: Alex Fabiano
// * Date: 31 Oct, 2019
// */
//
//#include "Stack.h"
//
///* explicit-value constructor
// * Parameter: capacity, an unsigned value.
// * Precondition: capacity > 0.
// * Postcondition: mySize == 0 && myCapacity == capacity
// *              && myArray contains the address of a dynamic array of 'capacity' entries.
// */
//Stack::Stack(unsigned capacity) {
//	if (capacity == 0) {
//		throw StackException("Stack(capacity)", "capacity must be positive!");
//	}
//   mySize = 0;
//   myCapacity = capacity;
//   myArray = new Item[capacity];
//}
//
///* copy constructor
// * Parameter: original, a Stack (const reference).
// * Postcondition: I am a copy of original.
// */
//Stack::Stack(const Stack& original) {
//	makeCopyOf(original);
//}
//
///* utility method containing code refactored from
// *  the copy constructor and operator=.
// * Parameter: original, a Stack (const reference).
// * Precondition: original.myCapacity > 0.
// * Postcondition: I am a copy of original.
// */
//void Stack::makeCopyOf(const Stack& original) {
//	myCapacity = original.myCapacity;
//	myArray = new Item[myCapacity];
//
//	for (unsigned i = 0; i < myCapacity; i++) {
//		myArray[i] = original.myArray[i];
//	}
//	mySize = original.mySize;
//}
//
///* destructor
// * Postcondition: myCapacity == 0 && mySize == 0
// *             && myArray has been deallocated.
// */
//Stack::~Stack() {
//	delete [] myArray;
//	myArray = NULL;
//	myCapacity = 0;
//	mySize = 0;
//}
//
///* assignment operator
// * Parameter: original, a Stack (const reference).
// * Postcondition: I am a copy of original
// *              && I have been returned.
// */
//Stack& Stack::operator=(const Stack& original) {
//	if (this != &original) {
//		delete [] myArray;
//		makeCopyOf(original);
//	}
//	return *this;
//}
//
//bool Stack::isEmpty() const {
//	if (mySize == 0) {
//		return true;
//	}
//	return false;
//}
//
//bool Stack::isFull() const {
//	if (mySize == myCapacity) {
//		return true;
//	}
//	return false;
//}
//
//Item Stack::peekTop() const {
//   if ( isEmpty() ) {
//      throw StackException("peekTop()", "stack is empty!");
//   }
//   return myArray[mySize - 1];
//}
//
//void Stack::push(const Item& it) {
//	if ( isFull() ) {
//		throw StackException("push()", "stack is full!");
//	}
//	myArray[mySize] = it;
//	mySize++;
//}
//
//Item& Stack::pop() {
//	if ( isEmpty() ) {
//		throw StackException("pop()", "stack is empty!");
//	}
//	mySize--;
//	return myArray[mySize];
//}
//
//unsigned Stack::getSize() {
//	/*
//	 * My thinking is that the method can save some time by short cutting the loop counter
//	 * by knowing the value of a full or empty stack without having to loop through it.
//	 */
//	if ( isFull() ) {
//		return (mySize);
//	} else if ( isEmpty() ) {
//		return 0;
//	} else {
//		unsigned i;
//		for (i = 0; i < mySize; ++i) {
//			if (myArray[i + 1] == NULL) {
//				return myArray[i];
//			}
//		}
//	}
//}
//
//unsigned Stack::getCapacity() {
//	return (myCapacity - getSize());
//}
//
//void Stack::setCapacity(unsigned newCapacity) {
//	if (newCapacity == 0 || newCapacity < getSize()) {
//		throw StackException("setCapacity", "newCapacity too small!");
//	}
//	if (newCapacity != myCapacity) {
//		unsigned size = getSize();
//		Item *bigArray = new Item [newCapacity];
//		for (unsigned i = 0; i < size; ++i) {
//			bigArray[i] = myArray[i];
//		}
//		delete[] myArray;
//		myCapacity = newCapacity;
//		for (unsigned i = 0; i < size; ++i) {
//			 myArray[i] = bigArray[i];
//		}
//		//myCapacity = getCapacity();
//		delete[] bigArray;
//	}
//}
