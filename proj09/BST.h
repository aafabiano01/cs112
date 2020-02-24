/* BST.h declares a "classic" binary search tree of linked nodes.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name: Alex Fabiano
 * Date: 19 Nov 2019
 * 
 * Class Invariant:
 *   myNumItems == 0 && myRoot == NULL ||
 *   myNumItems > 0 && 
 *     myRoot stores the address of a Node containing an item &&
 *       all items in myRoot->myLeft are less than myRoot->myItem &&
 *       all items in myRoot->myRight are greater than myRoot->myItem.
 */

#ifndef BST_H_
#define BST_H_

#include "Exception.h"
#include <iostream>
using namespace std;

template<class Item>

class BST {
public:
	BST();
	virtual ~BST();
	bool isEmpty() const;
	unsigned getNumItems() const;
	void insert(const int n);
	bool contains(const int n) const;
	void traverseInorder();
	void traversePreorder();
	void traversePostorder();
	unsigned getHeight() const;
private:
	struct Node {
	    Node(const Item& it);
            virtual ~Node();
            void insert(const int n);
            bool contains(const int n) const;
            void traverseInorder();
            void traversePreorder();
            void traversePostorder();
            virtual void processItem();
            unsigned getHeight() const;
            Item myItem;
            Node* myLeft;
            Node* myRight;
	};
	
	Node* myRoot;
	unsigned myNumItems;
	friend class BST_Tester;
};
/* BST
 * BST constructor, allows for creation of new nodes.
 */
template<class Item>
BST<Item>::BST() {
	myRoot = nullptr;
	myNumItems = 0;
}
/* BST
 * BST destructor, allows for recursive deallocation.
 */
template<class Item>
BST<Item>::~BST() {
	delete myRoot;
	myRoot = NULL;
	myNumItems = 0;
}
/* Node
 * Node constructor, allows for creation of new nodes.
 */
template<class Item>
BST<Item>::Node::Node(const Item& it) {
   myItem = it;
   myLeft = NULL;
   myRight = NULL;
}
/* Node
 * Node destructor, allows for recursive deallocation.
 */
template<class Item>
BST<Item>::Node::~Node() {
	delete myLeft;
	delete myRight;
}
/* BST
 * isEmpty() returns whether or not a BST is empty.
 * param: none
 * precondition: none
 * return: true if empty, false if not.
 * postcondition: BST unchanged
 */
template<class Item>
bool BST<Item>::isEmpty() const {
	return myNumItems == 0;
}
/* BST
 * getNumItems() returns the amount of items in a BST.
 * param: none
 * precondition: none
 * return: myNumItems
 * postcondition: BST unchanged
 */
template<class Item>
unsigned BST<Item>::getNumItems() const {
	return myNumItems;
}
/* BST
 * traversePostorder() traverses BST in preorder
 * param: none
 * precondition: none
 * return: none
 * postcondition: BST unchanged
 */
template<class Item>
void BST<Item>::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}
/* Node
 * traversePostorder() traverses BST in preorder
 * param: none
 * precondition: none
 * return: none
 * postcondition: BST unchanged
 */
template<class Item>
void BST<Item>::Node::traversePreorder() {
	processItem();
	if (myLeft != NULL) {
		myLeft->traversePreorder();
	}
	if (myRight != NULL) {
		myRight->traversePreorder();
	}
}
/* Node
 * processItem() prints out the item in a node
 * param: none
 * precondition: none
 * return: none
 * postcondition: BST unchanged
 */
template<class Item>
void BST<Item>::Node::processItem() {
		cout << ' ' << myItem;
}
/* Node
 * traversePostorder() traverses BST in post order
 * param: none
 * precondition: none
 * return: none
 * postcondition: BST unchanged
 */
template<class Item>
void BST<Item>::Node::traversePostorder() {
	if (myLeft != NULL) {
		myLeft->traversePostorder();
	}
	if (myRight != NULL) {
		myRight->traversePostorder();
	}
	processItem();
}
/* BST
 * insert() adds an item to a BST
 * param: item to insert
 * precondition: none
 * return: nothing
 * postcondition: BST contains inserted value, unless it was already in the tree,
 * then it will throw an error.
 */
template<class Item>
void BST<Item>::insert(const int n) {
	if (isEmpty()) {
		Node * n1 = new Node(n);
		myRoot = n1;
	} else {
		try {
			myRoot->insert(n);
		} catch (const Exception& e) {
			throw Exception("Insert", "Failed to Insert.");
		}
	}
	myNumItems++;
}
/* Node
 * insert() adds an item to a BST
 * param: item to insert
 * precondition: none
 * return: nothing
 * postcondition: BST contains inserted value, unless it was already in the tree,
 * then it will throw an error.
 */
template<class Item>
void BST<Item>::Node::insert(const int n) {
	if (n > myItem) { //n bigger than root
		if (myRight == NULL) { //trivial right
			Node * n1 = new Node(n);
			myRight = n1;
		} else { //non trivial right, induction step
			myRight->insert(n);
		}
	} else if (n < myItem) { //n less than root
		if (myLeft == NULL) { //trivial left
			Node * n1 = new Node(n);
			myLeft = n1;
		} else { //non trivial left, induction step
			myLeft->insert(n);
		}
	} else if (n == myItem) {
		throw Exception("Insert", "Number already in tree.");
	}
}
/* BST
 * contains() displays whether or not a BST contains a value
 * param: item to search for
 * precondition: none
 * return: true if found, false if not
 * postcondition: BST unchanged
 */
template<class Item>
bool BST<Item>::contains(const int n) const {
	if (isEmpty()) {
		return false;
	} else {
		return myRoot->contains(n);
	}
}
/* Node
 * contains() displays whether or not a BST contains a value
 * param: item to search for
 * precondition: none
 * return: true if found, false if not
 * postcondition: BST unchanged
 */
template<class Item>
bool BST<Item>::Node::contains(const int n) const { // @suppress("No return")
	if (n > myItem) { //n bigger than root
		if (myRight == NULL) { //trivial right
			return false;
		} else if (myRight->myItem != n){ //non trivial right, induction step
			myRight->contains(n);
		}
	} else if (n < myItem) { //n less than root
		if (myLeft == NULL) { //trivial right
			return false;
		} else if (myLeft->myItem != n){ //non trivial right, induction step
			myLeft->contains(n);
		}
	} else if (n == myItem) {
		return true;
	}
}
/* BST
 * traversePostorder() traverses BST in post order
 * param: none
 * precondition: none
 * return: none
 * postcondition: BST unchanged
 */
template<class Item>
void BST<Item>::traversePostorder() {
	if ( !isEmpty() ) {
		myRoot->traversePostorder();
	}
}
/* BST
 * traversePostorder() traverses BST in order
 * param: none
 * precondition: none
 * return: none
 * postcondition: BST unchanged
 */
template<class Item>
void BST<Item>::traverseInorder() {
	if ( !isEmpty() ) {
		myRoot->traverseInorder();
	}
}
/* Node
 * traversePostorder() traverses BST in order
 * param: none
 * precondition: none
 * return: none
 * postcondition: BST unchanged
 */
template<class Item>
void BST<Item>::Node::traverseInorder() {
	if (myLeft != NULL) {
		myLeft->traverseInorder();
	}
	processItem();
	if (myRight != NULL) {
		myRight->traverseInorder();
	}
}
/* BST
 * getHeight() returns the height of a BST.
 * param: none
 * precondition: none
 * return: height of tree
 * postcondition: BST unchanged
 */
template<class Item>
unsigned BST<Item>::getHeight() const {
	if (isEmpty()) {
		return 0;
	}
	return myRoot->getHeight();
}
/* Node
 * getHeight() returns the height of a BST.
 * param: none
 * precondition: none
 * return: height of tree
 * postcondition: BST unchanged
 */
template<class Item>
unsigned BST<Item>::Node::getHeight() const {
    int heightLeft = 0;
    int heightRight = 0;
    if (myLeft != NULL) {
        heightLeft = myLeft->getHeight();
    }
    if (myRight != NULL) {
        heightRight = myRight->getHeight();
    }
    if (heightLeft > heightRight) {
        return heightLeft + 1;
    }
    else {
        return heightRight + 1;
    }
}

#endif /*BST_H_*/

