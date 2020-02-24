/* Stack.h provides a (dynamic-array-based) Stack class.
 * Started by Joel Adams, for CS 112 at Calvin University.
 * Student Name: Alex Fabiano
 * Date: 31 Oct, 2019
 * 
 * Invariant: mySize == 0 && isEmpty() && !isFull()
 *         || mySize == myCapacity && !isEmpty() && isFull()
 *         || mySize > 0 && mySize < myCapacity && !isEmpty() && !isFull().
 * Notes: 
 * 1. Member mySize always contains the index of the next empty space in myArray
 *        (the index of the array element into which the next pushed item will be placed).
 * 2. Sending push() to a full Stack throws the exception Stack::Overflow.
 * 3. Sending pop() or peekTop() to an empty Stack throws the exception Stack::Underflow.
 */

#ifndef STACK_H_
#define STACK_H_

#include "StackException.h"
#include <string>
#include <iostream>
using namespace std;

//typedef int Item;
template<class Item>

class Stack {
public:
	Stack(unsigned capacity);
	Stack(const Stack& original);
	~Stack();
	Stack& operator=(const Stack& original);
	bool isEmpty() const;
	bool isFull() const;
	Item peekTop() const;
	void push(const Item& it);
	Item& pop();
	unsigned getSize() const;
	unsigned getCapacity();
	void setCapacity(unsigned newCapacity);

protected:
	void makeCopyOf(const Stack& original);
	
private:
	unsigned myCapacity;
	unsigned mySize;
	Item*    myArray;
	friend class StackTester;
};

/* explicit-value constructor
 * Parameter: capacity, an unsigned value.
 * Precondition: capacity > 0.
 * Postcondition: mySize == 0 && myCapacity == capacity
 *              && myArray contains the address of a dynamic array of 'capacity' entries.
 */
template<class Item>
Stack<Item>::Stack(unsigned capacity) {
	if (capacity == 0) {
		throw StackException("Stack(capacity)", "capacity must be positive!");
	}
   mySize = 0;
   myCapacity = capacity;
   myArray = new Item[capacity];
}

/* copy constructor
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original.
 */
template<class Item>
Stack<Item>::Stack(const Stack& original) { // @suppress("Class members should be properly initialized")
	makeCopyOf(original);
}

/* utility method containing code refactored from
 *  the copy constructor and operator=.
 * Parameter: original, a Stack (const reference).
 * Precondition: original.myCapacity > 0.
 * Postcondition: I am a copy of original.
 */
template<class Item>
void Stack<Item>::makeCopyOf(const Stack& original) {
	myCapacity = original.myCapacity;
	myArray = new Item[myCapacity];

	for (unsigned i = 0; i < myCapacity; i++) {
		myArray[i] = original.myArray[i];
	}
	mySize = original.mySize;
}

/* destructor
 * Postcondition: myCapacity == 0 && mySize == 0
 *             && myArray has been deallocated.
 */
template<class Item>
Stack<Item>::~Stack() {
	delete [] myArray;
	myArray = NULL;
	myCapacity = 0;
	mySize = 0;
}

/* assignment operator
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original
 *              && I have been returned.
 */
template<class Item>
Stack<Item>& Stack<Item>::operator=(const Stack<Item>& original) {
	if (this != &original) {
		delete [] myArray;
		makeCopyOf(original);
	}
	return *this;
}
/*
 * isEmpty() determines whether a stack is empty or not.
 * Param: Requires a stack to operate on.
 * Return: Boolean true or false, true if empty, false if otherwise.
 * Post: Stack is unchanged.
 */
template<class Item>
bool Stack<Item>::isEmpty() const {
	if (mySize == 0) {
		return true;
	}
	return false;
}
/*
 * isFull() determines whether a stack is empty or not.
 * Param: Requires a stack to operate on.
 * Return: Boolean true or false, true if full, false if otherwise.
 * Post: Stack is unchanged.
 */
template<class Item>
bool Stack<Item>::isFull() const {
	if (mySize == myCapacity) {
		return true;
	}
	return false;
}
/*
 * peekTop() returns the item at the top of a stack.
 * Conditions: Stack is not empty.
 * Param: A stack to operate on.
 * Return: The item at the top of the stack/ end the array.
 * Post: Stack is unchanged.
 */
template<class Item>
Item Stack<Item>::peekTop() const {
   if ( isEmpty() ) {
      throw StackException("peekTop()", "stack is empty!");
   }
   return myArray[mySize - 1];
}
/*
 * push() appends an item to the top of a stack if it is not full.
 * Conditions: Stack is not full.
 * Param: Stack to operate on, item to append to stack.
 * Return: Nothing.
 * Post: Stack now has 1 more item and size is incremented by 1.
 */
template<class Item>
void Stack<Item>::push(const Item& it) {
	if ( isFull() ) {
		throw StackException("push()", "stack is full!");
	}
	myArray[mySize] = it;
	mySize++;
}
/*
 * pop() takes the item from the top of the stack.
 * Conditions: Stack is not empty.
 * Param: Stack to operate on.
 * Return: Item from top of stack.
 * Post: Stack has 1 less item, size decreased by 1.
 */
template<class Item>
Item& Stack<Item>::pop() {
	if ( isEmpty() ) {
		throw StackException("pop()", "stack is empty!");
	}
	mySize--;
	return myArray[mySize];
}
/*
 * getSize() returns the size of the stack it is called on.
 * Param: Stack to operate on.
 * Return: Size of the stack.
 * Post: Stack is unchanged.
 */
template<class Item>
unsigned Stack<Item>::getSize() const {
//	if ( isFull() ) {
//		return (mySize);
//	} else if ( isEmpty() ) {
//		return 0;
//	} else {
//		unsigned i;
//		for (i = 0; i < mySize; ++i) {
//			if (myArray[i + 1] == NULL) {
//				return i;
//			}
//		}
//	}
	return mySize;
}
/*
 *
 */
template<class Item>
unsigned Stack<Item>::getCapacity() {
//	return (myCapacity - getSize());
	return myCapacity;
}
/*
 * setCapacity() sets a new capacity for a stack.
 * Conditions: The new capacity for the stack must not be 0 or less than the
 * size of the stack.
 * Param: Stack to operate on, capacity to change to.
 * Return: Nothing.
 * Post: Stack's capacity is set to the amount specified.
 */
template<class Item>
void Stack<Item>::setCapacity(unsigned newCapacity) {
	if (newCapacity == 0 || newCapacity < getSize()) {
		throw StackException("setCapacity", "newCapacity too small!");
	}
	if (newCapacity != myCapacity) {
		unsigned size = getSize();
		Item *bigArray = new Item [newCapacity];
		for (unsigned i = 0; i < size; ++i) {
			bigArray[i] = myArray[i];
		}
		delete[] myArray;
		myCapacity = newCapacity;
//		for (unsigned i = 0; i < size; ++i) {
//			 myArray[i] = bigArray[i];
//		}
		myArray = bigArray;
//		delete[] bigArray;
	}
}

#endif
