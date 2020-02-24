/* LinkedQueue.cpp defines the methods for class LinkedQueue.
 * Joel Adams, for CS 112 at Calvin University.
 * Student name:
 * Date:
 */

#include "LinkedQueue.h"

LinkedQueue::LinkedQueue() {
	mySize = 0;
	myFirstPtr = myLastPtr = NULL;
}

LinkedQueue::LinkedQueue(const LinkedQueue& original) {
	makeCopyOf(original);
}

void LinkedQueue::makeCopyOf(const LinkedQueue& original) {
	mySize = original.mySize;
	if ( mySize == 0 ) {
		myFirstPtr = myLastPtr = NULL;
	} else {
		myFirstPtr = new Node(original.getFirst(), NULL);
		Node * temp0 = original.myFirstPtr->myNextPtr;
		Node * temp1 = myFirstPtr;
		while (temp0 != NULL) {
			temp1->myNextPtr = new Node(temp0->myItem, NULL);
			temp1 = temp1->myNextPtr;
			temp0 = temp0->myNextPtr;
		}
		myLastPtr = temp1;
	}
}

LinkedQueue::~LinkedQueue() {
	delete myFirstPtr;
	myFirstPtr = myLastPtr = NULL;
	mySize = 0;
}

LinkedQueue& LinkedQueue::operator=(const LinkedQueue& aQueue) {
	if (this != &aQueue) {
		delete myFirstPtr;    // invokes recursive ~Node()
		makeCopyOf(aQueue);
	}
	return *this;
}

Item LinkedQueue::getFirst() const {
	if (mySize == 0) {
		throw EmptyQueueException("getFirst()");
	}
	return myFirstPtr->myItem;
}

Item LinkedQueue::getLast() const {
	if (mySize == 0) {
		throw EmptyQueueException("getLast()");
	}
	return myLastPtr->myItem;
}

void LinkedQueue::append(const Item& it) {
	try {
		Node* nPtr = new Node(it,NULL);
	}  catch (std::bad_alloc& ba)
	{
		throw FullQueueException("Out of memory.");
	}
	Node* nPtr = new Node(it,NULL);
	if (mySize == 0) {
		myFirstPtr = nPtr;
	} else {
		myLastPtr->myNextPtr = nPtr;
	}
	myLastPtr = nPtr;
	mySize++;
}

Item LinkedQueue::remove() {
	if (mySize == 0) {
		throw EmptyQueueException("remove()");
	}
	Item result = myFirstPtr->myItem;
	Node* nPtr = myFirstPtr;
	myFirstPtr = myFirstPtr->myNextPtr;
	nPtr->myNextPtr = nullptr;
	delete nPtr;
	mySize--;
	return result;
}
