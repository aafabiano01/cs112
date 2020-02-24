/* BST.cpp defines binary search tree methods.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Name:
 * Date:
 */
 
#include "BST.h"
#include <stdexcept> //remove later

BST::BST() {
	myRoot = nullptr;
	myNumItems = 0;
}

BST::~BST() {
	delete myRoot;
	myRoot = NULL;
	myNumItems = 0;
}

BST::Node::Node(const Item& it) {
   myItem = it;
   myLeft = NULL;
   myRight = NULL;
}

BST::Node::~Node() {
	delete myLeft;
	delete myRight;
}

bool BST::isEmpty() const {
	return myNumItems == 0;
}

unsigned BST::getNumItems() const {
	return myNumItems;
}

void BST::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

void BST::Node::traversePreorder() {
	processItem();
	if (myLeft != NULL) {
		myLeft->traversePreorder();
	}
	if (myRight != NULL) {
		myRight->traversePreorder();
	}
}

void BST::Node::processItem() {
		cout << ' ' << myItem;
}

void BST::Node::traversePostorder() {
	if (myLeft != NULL) {
		myLeft->traversePostorder();
	}
	if (myRight != NULL) {
		myRight->traversePostorder();
	}
	processItem();
}

void BST::insert(const int n) {
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

void BST::Node::insert(const int n) {
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

bool BST::contains(const int n) const {
	if (isEmpty()) {
		return false;
	} else {
		return myRoot->contains(n);
	}
}

bool BST::Node::contains(const int n) const { // @suppress("No return")
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

void BST::traversePostorder() {
	if ( !isEmpty() ) {
		myRoot->traversePostorder();
	}
}

void BST::traverseInorder() {
	if ( !isEmpty() ) {
		myRoot->traverseInorder();
	}
}

void BST::Node::traverseInorder() {
	if (myLeft != NULL) {
		myLeft->traverseInorder();
	}
	processItem();
	if (myRight != NULL) {
		myRight->traverseInorder();
	}
}
