/* ArrayQueue.h declares a Queue class using a dynamic array.
 * Begun by: Joel Adams, for CS 112 at Calvin University.
 * Student name: Alex Fabiano
 * Date: 18 Nov, 2019
 * 
 * Class Invariant: 
 *    mySize == 0 ||
 *    mySize > 0 && myArray[myFirst] == getFirst()
 *               && myArray[myLast] == getLast().
 * 
 *  (When I am not empty:
 *     myFirstIndex is the index of my oldest value;
 *     myLastIndex is the index of my newest value.)
 */

#ifndef ARRAY_QUEUE_H_
#define ARRAY_QUEUE_H_

#include "QueueException.h"
#include <cstring>
#include <cassert>

//typedef int Item;
template<class Item>
 
class ArrayQueue {
public:
	ArrayQueue(const unsigned n);
	ArrayQueue(const ArrayQueue& original);
	virtual ~ArrayQueue();
	ArrayQueue& operator=(const ArrayQueue& original);
	unsigned getSize() const;
	unsigned getCapacity() const;
	bool isEmpty() const;
	bool isFull() const;
	Item getFirst() const;
	Item getLast() const;
	void append(const Item& it);
	Item remove();
	void setCapacity(const unsigned newCapacity);
protected:
	virtual void makeCopyOf(const ArrayQueue& original);
private:
	unsigned mySize;       // number of items I contain
	unsigned myCapacity;   // how many items I can store
	unsigned myFirstIndex; // index of oldest item (if any)
	unsigned myLastIndex;  // index of newest item (if any)
	Item*    myArrayPtr;   // dynamic array of items

	friend class ArrayQueueTester;
};

template<class Item>
ArrayQueue<Item>::ArrayQueue(const unsigned n) {
	if (n == 0) {
		throw QueueException("constructor()", " = 0");
	}
	myCapacity = n;
	mySize = myFirstIndex = 0;
	myLastIndex = n -1;
	myArrayPtr = new Item[n];
}

/* copy constructor
 * @param: original, the ArrayQueue to be copied.
 * Postcondition: I am a deep copy of original.
 */
template<class Item>
ArrayQueue<Item>::ArrayQueue(const ArrayQueue& original) { // @suppress("Class members should be properly initialized")
	makeCopyOf(original);
}

/* utility method to build copies
 * @param: original, the ArrayQueue to be copied.
 * Postcondition: I am a deep copy of original.
 */
template<class Item>
void ArrayQueue<Item>::makeCopyOf(const ArrayQueue& original) {
	mySize = original.mySize;
	myCapacity = original.myCapacity;
	myFirstIndex = original.myFirstIndex;
	myLastIndex = original.myLastIndex;
	myArrayPtr = new Item[myCapacity];
	memcpy(myArrayPtr, original.myArrayPtr, myCapacity*sizeof(Item) );
}

/* destructor
 * Postcondition: my dynamic array has been deallocated.
 */
template<class Item>
ArrayQueue<Item>::~ArrayQueue() {
	delete [] myArrayPtr;
	myArrayPtr = NULL;
	mySize = myFirstIndex = myLastIndex = 0;
}

/* assignment operator
 * @param: aQueue, an ArrayQueue/
 * @return: myself.
 * Postcondition: I am a deep copy of aQueue.
 */
template<class Item>
ArrayQueue<Item>& ArrayQueue<Item>::operator=(const ArrayQueue& aQueue) {
	if (this != &aQueue) {
		delete [] myArrayPtr;
		makeCopyOf(aQueue);
	}
	return *this;
}

/* Am I empty?
 * @return: true if I am empty, false othewise.
 */
template<class Item>
bool ArrayQueue<Item>::isEmpty() const {
	return mySize == 0;
}

/* Am I full?
 * @return: true if I am full, false othewise.
 */
template<class Item>
bool ArrayQueue<Item>::isFull() const {
	return getSize() == myCapacity;
}

/* accessor for myCapacity
 * @return myCapacity.
 */
template<class Item>
unsigned ArrayQueue<Item>::getCapacity() const {
	return myCapacity;
}

/* accessor for mySize
 * @return mySize.
 */
template<class Item>
unsigned ArrayQueue<Item>::getSize() const {
	return mySize;
}
/* accessor for myFirst
 * @return myFirst.
 */
template<class Item>
Item ArrayQueue<Item>::getFirst() const {
	if (mySize == 0) {
		throw EmptyQueueException("getFirst()");
	}
	return myArrayPtr[myFirstIndex];
}
/* accessor for myLast
 * @return myLast.
 */
template<class Item>
Item ArrayQueue<Item>::getLast() const {
	if (mySize == 0) {
		throw EmptyQueueException("getLast()");
	}
	return myArrayPtr[myLastIndex];
}
/*
 * append() adds an item to the end of a queue.
 * param: item to append.
 * precondition: none.
 * return: nothing.
 * postcondition: queue size +1, item added to last index.
 * requires that size != 0.
 */
template<class Item>
void ArrayQueue<Item>::append(const Item& it) {
	if (mySize == myCapacity) {
		throw FullQueueException("append()");
	}
	myLastIndex = (myLastIndex + 1) % myCapacity;
	myArrayPtr[myLastIndex] = it;
	mySize++;
}
/*
 * remove() removes an item at the start of a queue.
 * param: item to remove.
 * precondition: none.
 * return: nothing.
 * postcondition: queue size -1, item removed at first index.
 * requires that size != 0.
 */
template<class Item>
Item ArrayQueue<Item>::remove() {
	if (mySize == 0) {
		throw EmptyQueueException("remove()");
	}
	Item result = myArrayPtr[myFirstIndex];
	myFirstIndex = (myFirstIndex + 1) % myCapacity;
	mySize--;
	return result;
}
/*
 * setCapacity allows the capacity of an arrayqueue to change during runtime.
 * param: new capacity to change to.
 * precondition: none.
 * return: nothing.
 * postcondition: capacity is now new capacity.
 * requires that new size is not 0 or less than the amount of items in the queue.
 */
template<class Item>
void ArrayQueue<Item>::setCapacity(const unsigned newCapacity) {
	if (newCapacity <= 0) {
		throw QueueException("setCapacity()"," newCapacity less than or equal to 0");
	}
	if (newCapacity < getSize()) {
		throw QueueException("setCapacity()"," newCapacity less than number of items in array currently");
	}
	Item* temp = new Item[newCapacity];

	for (unsigned i = 0; i < mySize; i++) {
		int myIndex = (myFirstIndex + i) % myCapacity;
		temp[i] = myArrayPtr[myIndex];
	}
	myFirstIndex = 0;
	myLastIndex = mySize - 1;
	myCapacity = newCapacity;
	delete [] myArrayPtr;
	myArrayPtr = temp;

}

#endif /*ARRAY_QUEUE_H_*/
