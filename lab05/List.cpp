/*
 * List.cpp defines the methods for class List.
 * Oct 12, 2019 by Alex Fabiano
 * for cs112 at Calvin U
 */

#include "List.h"
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include <cassert>
using namespace std;

List::List() {
	mySize = 0;
	myFirst = NULL;
	myLast = NULL;
}

List::Node::Node() {
	myNext = NULL;
	myItem = Item();
}

List::Node::Node(Item it, Node *next) {
	myItem = it;
	myNext = next;
}

Item List::getFirst() const {
	if (mySize <= 0 || myFirst == NULL) {
		throw std::underflow_error("List Item Null, or size is negative.");
	}
	return myFirst->myItem;
}

Item List::getLast() const {
	if (mySize <= 0 || myFirst == NULL) {
		throw std::underflow_error("List Item Null, or size is negative.");
	}
	return myLast->myItem;
}

void List::append(const Item& it) {
	Node *nNode = new Node(it, NULL);
	if (mySize == 0) {
		myFirst = nNode;
	} else {
		myLast->myNext = nNode;
	}
	myLast = nNode;
	mySize += 1;
}

List::~List() {
    delete myFirst;          // delete first node, invoking ~Node() (does nothing if myFirst == NULL)
    myFirst = myLast = NULL; // clear myFirst and myLast (optional)
    mySize = 0;              // clear mySize (optional)
}

List::Node::~Node() {
	//cout << "~Node() is deallocating the node containing item " << myItem << endl;

   delete myNext;       // delete the next node, invoking ~Node() in it
                        // (does nothing if myNext == NULL)
}

List::List(const List& original) {
   myFirst = myLast = NULL;       //  set pointers
   mySize = 0;                    //   and size to 'empty' values
   Node* oPtr = original.myFirst; //  start at the first node
   while (oPtr != NULL) {         //  while there are nodes to copy:
      append(oPtr->myItem);       //   append the item in that node
      oPtr = oPtr->myNext;        //   advance to next node
   }
}

List& List::operator=(const List& original) {
	if (myFirst == original.myFirst) {
		return *this;
	}
	delete myFirst;
	myFirst = myLast = NULL;       //  set pointers
	mySize = 0;                    //   and size to 'empty' values
	Node* oPtr = original.myFirst; //  start at the first node
	while (oPtr != NULL) {         //  while there are nodes to copy:
		append(oPtr->myItem);       //   append the item in that node
		oPtr = oPtr->myNext;        //   advance to next node
	}
	return *this;
}
/*
 * operator!=() determines whether or not two lists are equal.
 * param: List to compare to other list.
 * precondition: none.
 * return: true or false, true if they are not equal, false if equal.
 * postcondition: neither lists are changed.
 * Made by Alex Fabiano
 */
bool List::operator!=(const List& original) const {
	if (mySize != original.mySize) {
		return true;
	} else {
		Node *ogPointer = original.myFirst;
		Node *myPointer = myFirst;
		for (unsigned i = 0; i < mySize; ++i) {
			if (ogPointer->myItem != myPointer->myItem){
				return true;
			}
			ogPointer = ogPointer->myNext;
			myPointer = myPointer->myNext;
		}
	}
	return false;
}
/*
 * writeTo() writes a list to an ostream.
 * param: ostream to write to, separator between values.
 * precondition: ostream is already open.
 * return: nothing.
 * postcondition: the list is not changed, and it has now been printed
 * to the ostream given.
 * Made by Alex Fabiano
 */
void List::writeTo(ostream& out, string separate) const {
	Node *myPointer = myFirst;
	for (unsigned i = 0; i < mySize; ++i) {
		out << myPointer->myItem << separate;
		myPointer = myPointer->myNext;
	}
}
/*
 * readFrom() reads items from a file and makes a list out of them.
 * param: name of file with extension.
 * precondition: file exists.
 * return: nothing.
 * postcondition: the array readFrom() was enacted on is now a copy
 * of all the values in the file.
 * Made by Alex Fabiano
 */
void List::readFrom(const string fileName) {
	Item pickyAppend;
	/*
	 * I named the item pickyAppend because I was mad, now I can't even
	 * remember why I did.
	 */
	ifstream bin(fileName);
	assert( bin.is_open() );
	/*
	 * I open two streams, one acts as a counter, while the other takes in
	 * values.
	 * Because cin automatically increments to the next value, it can't be
	 * used as both the counter and the method by which values are stored.
	 */
	ifstream fin(fileName);
	assert( fin.is_open() );
	while ( bin >> pickyAppend ) {
		fin >> pickyAppend;
		append(pickyAppend);
	}
}
/*
 * getIndexOf() finds the index of a node given its item value.
 * param: Item to look for.
 * precondition: none.
 * return: The index of the item, or where it was first found if there are
 * more than one. -1 if the item was not found.
 * postcondition: the array is not changed.
 * Made by Alex Fabiano
 */
int List::getIndexOf(const Item lookingFor) const {
	int counter = 0;
	Node *myPointer = myFirst;
	for (unsigned i = 0; i < mySize; ++i) {
		if (lookingFor == myPointer->myItem) {
			return counter;
		}
		counter++;
		myPointer = myPointer->myNext;
	}
	return -1;
}
/*
 * remove() removes a node from a list of nodes.
 * param: index at which the node is to be removed.
 * precondition: none.
 * return: none.
 * postcondition: the array remove was enacted on has one less value
 * and whichever index was chosen is removed.
 * Made by Alex Fabiano
 */
Item List::remove(unsigned index) {
	if (mySize == 0) {
		/*
		 * If size of List is 0, return -1 as the item at the position of the deletion
		 * because nothing was there.
		 * Very important that this goes first, because trying to do normal methods
		 * on a completely null list causes some problems.
		*/
		return -1;
	}
	Item itemHolder = myFirst->myItem;
	Node *myPointer = myFirst;
	for (unsigned i = 0; i < index; i++) {
		/*
		 * Finds value to return for deleted Item.
		 * itemHolder will be the value at the index that was deleted.
		 */
		itemHolder = myPointer->myItem;
		myPointer = myPointer->myNext;
	}
	if (mySize == 1) {
		/*
		 * Deleting the only value in a list makes it an empty list.
		 * Outside of main if statement because its a special case.
		 */
		delete myFirst;
		myFirst = myLast = NULL;
		mySize = 0;
		return itemHolder;
	}
	Node *temp = new Node;
	if (index >= mySize) {
		//Deleting tail.
		Node *prev = myFirst;
		/*
		 * Always two steps ahead...
		 * Basically, the node prev will only advance if the value it will
		 * advance to, as well as that value's next value are both not null.
		 * If they are, because prev's next's next is null, it must mean
		 * prev's next is the last value in the list.
		 * So prev's next is "freed" (like a delete without calling the
		 * destructor) and prev's myNext pointer becomes null, showing that
		 * prev is now the last value in the list.
		 */
		while (prev->myNext->myNext != NULL) {
			prev = prev->myNext;
		}
		free(prev->myNext);
		prev->myNext = NULL;
	}
	else if (index == 0){
		//Deleting head.
		temp = myFirst;
		myFirst = myFirst->myNext;
		free(temp);
		/*
		 * Temp is a node, but also kind of an alias for the value at myFirst.
		 * Setting temp equal to myFirst sets temp as an alias to the node that
		 * is referenced by myFirst, so that way, when we change the pointer
		 * myFirst to be pointing to the second node in the list, we still have
		 * a way to get at the first value in the list and delete it so it is not
		 * leaked.
		 * 'Freeing' is a lot more important in this case, because if the
		 * destructor was called, it would destroy every node in the list.
		 */
	}
	else {
		//Deleting from random position.
		temp = myFirst;
		Node *post;
		for (unsigned i = 0; i < index -1; ++i) {
			temp = temp->myNext;
		}
		/*
		 * Temp is stopped one node before the node that is to be deleted.
		 * Post is set to the node to be deleted.
		 * Temp's myNext pointer is set to point to the node after post, the
		 * node to be deleted.
		 * Like before, post allows us to have a handle on a value that would
		 * otherwise be marooned.
		 * The value before post now points to the value after post.
		 * When we free post, the destructor is not called, and the memory leak
		 * is avoided.
		 */
		post = temp->myNext;
		temp->myNext = post->myNext;
		free(post);
	}
	mySize--;
	return itemHolder;
}
