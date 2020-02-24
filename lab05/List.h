/*
 * List.h declares the class List.
 * Oct 12, 2019 by Alex Fabiano
 * for cs112 at Calvin U
 */

#ifndef LIST_H_
#define LIST_H_

#include<iostream>
#include<fstream>

using namespace std;

typedef double Item;

class List {
public:
	List();
	unsigned getSize() const {return mySize;};
	Item getFirst() const;
	Item getLast() const;
	void append(const Item& it);
	~List();
	List(const List& original);
	List& operator=(const List& original);
	bool operator!=(const List& original) const;
	void writeTo(ostream& out, string separate) const;
	void readFrom(const string fileName);
	int getIndexOf(const Item lookingFor) const;
	Item remove(unsigned index);
private:
	struct Node {
		Item myItem;
		Node *myNext;
		Node();
		Node(Item it, Node *next);
		~Node();
	};
	unsigned mySize;
	Node *myFirst;
	Node *myLast;
	friend class ListTester;
};

#endif
