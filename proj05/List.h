/* List.h declares and defines methods
 * Student Names: Benedict Jojo Arthur (TM 1) & ALexander Fabiano (TM 2)
 * Date:10/14/2019
 * Proj 05
 *
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <stdexcept>
#include <cassert>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>

using namespace std;
typedef  double Item;
template <class Item>

class List {
public:

	List();
	unsigned getSize() const;
	Item getFirst() const;
	Item getLast() const;
	void append(Item it);
	~List();
	List(const List<Item>& original);
	List<Item>& operator=(const List<Item>& l2);

	bool operator==(const List<Item>& l2);
	void readFrom(istream& cin);
	void writeTo(const string& fileName);
	void prepend(Item it);
	void insert(Item it, int index);

	bool operator!=(const List& original) const;
	void writeTo(ostream& out, string separate) const;
	void readFrom(const string fileName);
	int getIndexOf(const Item lookingFor) const;
	Item remove(unsigned index);


private:

	unsigned mySize;

	struct Node {
		Node();
		Node(Item it, Node* next);
		Item myItem;
		Node* myNext;

		~Node();
	};
	Node* myFirst;
	Node* myLast;
	friend class ListTester;
};

template <class Item>
List<Item>::List() {
	mySize = 0;
	myFirst = NULL;
	myLast = NULL;
}

template <class Item>
List<Item>::Node::Node() {
	myItem = 0;
	myNext = NULL;
}


template <class Item>
List<Item>::Node::Node(Item it, Node* next) {
	myItem = it;
	myNext = next;
}

template <class Item>
unsigned List<Item>::getSize() const {
	return mySize;
}

template <class Item>
Item List<Item>::getFirst() const {
	if (mySize != 0) {
		return myFirst->myItem;
	} else {
		throw underflow_error("Cannot access values because list is empty");
	}
}

template <class Item>
Item List<Item>::getLast() const {
	if (mySize != 0) {
		return myLast->myItem;
	} else {
		throw underflow_error("Cannot access values because list is empty");
	}
}


template <class Item>
void List<Item>::append(Item it) {
	List::Node* newNodePtr = new List::Node(it, NULL);
	if (mySize == 0) {
		myFirst = newNodePtr;
	} else {
		myLast->myNext = newNodePtr;
	}
	myLast = newNodePtr;
	mySize++;
}

template <class Item>
List<Item>::Node::~Node() {
	delete myNext;
}

template <class Item>
List<Item>::~List() {
	delete myFirst;
	myFirst = myLast = NULL;
	mySize = 0;
}

template <class Item>
List<Item>::List(const List& original) {
	myFirst = myLast = NULL;
	mySize = 0;
	if (original.mySize > 0) {
		Node* oPtr = original.myFirst;
		while (oPtr != NULL) {
			append(oPtr->myItem);
			oPtr = oPtr->myNext;
		}
	}
}

template <class Item>
List<Item>& List<Item>::operator=(const List& original) {
	if (this != &original) {
		delete myFirst;
		mySize = 0;
		myFirst = myLast = NULL;
		if (original.mySize != 0) {
			Node* oPtr = original.myFirst;
			while (oPtr != NULL) {
				append(oPtr->myItem);
				oPtr = oPtr->myNext;
			}
		}
	}
	return *this;
}



/* Equality
 * @params: l2(const List<Item>)
 * Postcondition: Returns true if list objects are the same
 * Done By: Benedict Jojo Arthur
 */


template <class Item>
bool List<Item>::operator==(const List<Item>& l2) {
	if (mySize != l2.mySize) {
		return false;
	} else {
		Node* myPtr = myFirst;
		Node* l2Ptr = l2.myFirst;
		while (myPtr != NULL) {
			if (myPtr->myItem != l2Ptr->myItem) {
				return false;
			}
			l2Ptr = l2Ptr->myNext;
			myPtr = myPtr->myNext;
		}
		return true;
	}
}

/* Stream Input
 * @params: cin (istream)
 * Postcondition: Reads users values and appends to a lists
 * Done By: Benedict Jojo Arthur
 */


template <class Item>
void List<Item>::readFrom(istream& cin) {
	string line;
	getline(cin, line);
	stringstream streamLine(line);
	Item user;
	while (streamLine >> user) {
		append(user);
	}

}


/* File Output
 * @params: fileName (const string)
 * Postcondition: Outputs values in a list to a file
 * Done By: Benedict Jojo Arthur
 */

template <class Item>
void List<Item>::writeTo(const string& fileName) {
	ofstream fout(fileName.c_str());
	Node* myPtr = myFirst;
	for (unsigned i = 0; i < mySize; i++) {
		fout << myPtr->myItem << endl;
		myPtr = myPtr->myNext;
	}
	fout.close();
}


/* Prepend
 * @params: it (Item)
 * Postcondition: Inserts it at the beginning of aList
 * Done By: Benedict Jojo Arthur
 */

template <class Item>
void List<Item>::prepend(Item it) {
	Node* newNodePtr = new List<Item>::Node(it, NULL);
	if (mySize == 0) {
		myLast = newNodePtr;
	} else {
		newNodePtr->myNext = myFirst;
	}
	myFirst = newNodePtr;
	mySize++;
}


/* Insertion
 * @params: it (Item), index (int)
 * Postcondition: insert item it into aList at index index
 * Done By: Benedict Jojo Arthur
 */


template <class Item>
void List<Item>::insert(Item it, int index) {
	if (index <= 0 || mySize == 0) {
		prepend(it);
	} else if (index >= mySize) {
		append(it);
	} else {
		Node* tempPtr = myFirst;
		for (unsigned i = 0; i < index-1; ++i) {
			tempPtr = tempPtr->myNext;
		}
		Node* newNodePtr = new List<Item>::Node(it, tempPtr->myNext);
		tempPtr->myNext = newNodePtr;
		mySize++;
	}

}

/*
 * operator!=() determines whether or not two lists are equal.
 * param: List to compare to other list.
 * precondition: none.
 * return: true or false, true if they are not equal, false if equal.
 * postcondition: neither lists are changed.
 * Made by Alex Fabiano
 */


template <class Item>
bool List<Item>::operator!=(const List& original) const {
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

template <class Item>
void List<Item>::writeTo(ostream& out, string separate) const {
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

template <class Item>
void List<Item>::readFrom(const string fileName) {
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

template <class Item>
int List<Item>::getIndexOf(const Item lookingFor) const {
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

template <class Item>
Item List<Item>::remove(unsigned index) {
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
#endif /* LIST_H_ */
