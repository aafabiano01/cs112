/* ListTester.cpp defines the test methods for class List.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Names: Benedict Jojo Arthur (TM 1) & ALexander Fabiano (TM 2)
 * Date:10/14/2019
 * Proj 05
 */


#include "ListTester.h" // ListTester
#include "List.h"       // List
#include <iostream>     // cin, cout
#include <cassert>      // assert()
#include <cstdlib>      // exit()
#include <stdexcept>    // underflow_error
using namespace std;

void ListTester::runTests() {
	cout << "Running List tests..." << endl;
	testDefaultConstructor();
	testNodeDefaultConstructor();
	testNodeExplicitConstructor();
	testAppend();
	testDestructor();
	testCopyConstructor();
	testAssignment();
    testEquality();
    testReadFromStream();
    testWriteToString();
    testPrepend();
    testInsert();
    testInequality();
    testWriteToStream();
    testReadFromString();
    testGetIndexOf();
    testRemove();
	cout << "All tests passed!" << endl;
}

void ListTester::testDefaultConstructor() {
	cout << "Testing List default constructor... " << flush;
	List<double> aList;
	assert( aList.mySize == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << "Passed!" << endl;
}

void ListTester::testNodeDefaultConstructor() {
	cout << "Testing Node default constructor... " << flush;
	List<double>::Node aNode;
	assert( aNode.myItem == Item() );
	assert( aNode.myNext == NULL );
	cout << "Passed!" << endl;
}

void ListTester::testNodeExplicitConstructor() {
	cout << "Testing Node explicit constructor... " << flush;
	List<double>::Node n1(11, NULL);
	assert( n1.myItem == 11 );
	assert( n1.myNext == NULL );
	cout << " 1 " << flush;

	List<double>::Node *n3 = new List<double>::Node(33, NULL);
	List<double>::Node n2(22, n3);
	assert( n2.myItem == 22 );
	assert( n2.myNext == n3 );
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testAppend() {
	cout << "Testing append()... " << flush;
	// empty List
	List<double> aList;
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	try {
		aList.getFirst();
		cerr << "getFirst() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0a " << flush;
	}
	try {
		aList.getLast();
		cerr << "getLast() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0b " << flush;
	}
	// append to empty list
	aList.append(11);
	assert( aList.getSize() == 1 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast == aList.myFirst );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 11 );
	assert( aList.myFirst->myNext == NULL );
	cout << " 1 " << flush;
	// append to a list containing 1 Item
	aList.append(22);
	assert( aList.getSize() == 2 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast != NULL );
	assert( aList.myFirst != aList.myLast );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 22 );
	assert( aList.myFirst->myNext != NULL );
	assert( aList.myLast->myNext == NULL );
	cout << " 2 " << flush;
	// append to a list containing 2 Items
	aList.append(33);
	assert( aList.getSize() == 3 );
	assert( aList.myFirst != NULL );
	assert( aList.myLast != NULL );
	assert( aList.getFirst() == 11 );
	assert( aList.getLast() == 33 );
	assert( aList.myFirst->myNext->myItem == 22 );
	assert( aList.myLast->myNext == NULL );
	cout << " 3 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testDestructor() {
	cout << "Testing destructor... " << flush;
	List<double> aList;
	aList.~List();
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << " 1 " << flush;

	aList.append(11);
	aList.append(22);
	aList.append(33);
	aList.~List();
	assert( aList.getSize() == 0 );
	assert( aList.myFirst == NULL );
	assert( aList.myLast == NULL );
	cout << " 2 " << flush;
	cout << "Passed!  But double-check for memory leaks!" << endl;
}

void ListTester::testCopyConstructor() {
	cout << "Testing copy constructor... " << flush;
	// copy empty list
	List<double> list1;
	List<double> list2(list1);
	assert( list2.getSize() == 0 );
	assert( list2.myFirst == NULL );
	assert( list2.myLast == NULL );
	cout << " 1 " << flush;

	// copy nonempty list
	List<double> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List<double> list4(list3);
	assert( list4.getSize() == 3 );
	assert( list4.getFirst() == 11 );
	assert( list4.getLast() == 33 );
	assert( list4.myFirst->myNext->myItem == 22 );
	assert( list4.myFirst != list3.myFirst );
	assert( list4.myLast != list3.myLast );
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testAssignment() {
	cout << "Testing assignment... " << flush;
	// empty to empty assignment
	List<double> list1;
	List<double> list2;
	list2 = list1;
	assert( list2.getSize() == 0 );
	assert( list2.myFirst == NULL );
	assert( list2.myLast == NULL );
	cout << " 1 " << flush;

	// non-empty to empty assignment
	List<double> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List<double> list4;
	list4 = list3;
	assert( list4.getSize() == 3 );
	assert( list4.getFirst() == 11 );
	assert( list4.getLast() == 33 );
	assert( list4.myFirst->myNext->myItem == 22 );
      // check that nodes are distinct
	assert( list4.myFirst != list3.myFirst );
	assert( list4.myFirst->myNext != list3.myFirst->myNext );
	assert( list4.myLast != list3.myLast );
	cout << " 2 " << flush;

	// equal-sized non-empty to non-empty assignment
	List<double> list5;
	list5.append(44);
	list5.append(55);
	list5.append(66);
	list5 = list3;
	assert( list5.getSize() == 3 );
	assert( list5.getFirst() == 11 );
	assert( list5.getLast() == 33 );
	assert( list5.myFirst->myNext->myItem == 22 );
      // check that nodes are distinct
	assert( list5.myFirst != list3.myFirst );
	assert( list5.myFirst->myNext != list3.myFirst->myNext );
	assert( list5.myLast != list3.myLast );
	cout << " 3 " << flush;

	// empty to non-empty assignment
	List<double> list6;
	list6.append(44);
	list6.append(55);
	list6.append(66);
	List<double> list7;
	list6 = list7;
	assert( list6.getSize() == 0 );
	assert( list6.myFirst == NULL );
	assert( list6.myLast == NULL );
	cout << " 4 " << flush;

	// unequal-sized non-empty to non-empty assignment
	List<double> list8;
	list8.append(44);
	list8.append(55);
	list8.append(66);
	list8.append(77);
	list8 = list3;
	assert( list8.getSize() == 3 );
	assert( list8.getFirst() == 11 );
	assert( list8.getLast() == 33 );
	assert( list8.myFirst->myNext->myItem == 22 );
      // check that nodes are distinct
	assert( list8.myFirst != list3.myFirst );
	assert( list8.myFirst->myNext != list3.myFirst->myNext );
	assert( list8.myLast != list3.myLast );
	cout << " 5 " << flush;

	// assignment chaining
	List<double> list9;
	list9.append(44);
	list9.append(55);
	list9.append(66);
	list9.append(77);
	List<double> list10;
	list10 = list9 = list8;
	assert( list10.getSize() == 3 );
	assert( list10.getFirst() == 11 );
	assert( list10.getLast() == 33 );
	assert( list10.myFirst->myNext->myItem == 22 );
	cout << " 6 " << flush;

	// self-assignment (stupid, but possible)
	List<double> list11;
	list11.append(11);
	list11.append(22);
	list11.append(33);
	list11 = list11; // @suppress("Assignment to itself")
	assert( list11.getSize() == 3 );
	assert( list11.getFirst() == 11 );
	assert( list11.getLast() == 33 );
	assert( list11.myFirst->myNext->myItem == 22 );
	cout << " 7 " << flush;

	cout << "Passed!  But double-check for memory leaks!" << endl;


}

void ListTester::testEquality() {
	cout << "Testing equality... " << flush;
	List<double> list0;
	List<double> list1;
	List<double> list3;

	//both empty
	assert( list0 == list1);
	cout << " 0 " << flush;
	for (unsigned i = 0; i < 3; ++i) {
		list0.append(i+1);
	}
	//one empty list one list with items
	assert( !(list0 == list1) );
	cout << " 1 " << flush;

	//both with items and equal
	for (unsigned i = 0; i < 3; ++i) {
		list1.append(i+1);
	}
	assert( list0 == list1 );
	cout << " 2 " << flush;

	//Equal size different values
	for (unsigned i = 0; i < 3; ++i) {
		list3.append(i+10);
	}
	assert( !(list1 == list3) );
	cout << " 3 " << flush;

	cout << "Passed!" << endl;
}

void ListTester::testReadFromStream() {
	cout << "Testing readFrom(istream)... " << flush;

	ifstream fin("ListTest1.txt");
	assert( fin.is_open() );

	List<double> list0;
	List<double> list1;
	list0.readFrom(fin);
	list1.readFrom(fin);

	List<double>::Node* l0Ptr = list0.myFirst;
	List<double>::Node* l1Ptr = list1.myFirst;

	for (unsigned i = 1; i < 6; i++) {
		assert( l0Ptr->myItem == i );
		assert( l1Ptr->myItem == (2*i) );
		l0Ptr = l0Ptr->myNext;
		l1Ptr = l1Ptr->myNext;
	}
	fin.close();
	cout << " 0 " << flush;

	cout << "Passed!" << endl;
}


void ListTester::testWriteToString() {
	cout << "Testing writeTo(string)... " << flush;

	List<double> list0;
	List<double> list1;
	for (unsigned i = 1; i < 6; i++) {
		list0.append(i);
		list1.append(i*2);
	}
	list0.writeTo("ListTestWrite1.txt");
	list1.writeTo("ListTestWrite2.txt");

	ifstream fin1("ListTestWrite1.txt");
	ifstream fin2("ListTestWrite2.txt");

	double list1Item, list2Item;

	for (unsigned i = 1; i < 6; i++) {
		fin1 >> list1Item;
		fin2 >> list2Item;
		assert( list1Item == i );
		assert( list2Item == i*2 );
	}


	fin1.close();
	fin2.close();

	cout << "Passed!" << endl;
}


void ListTester::testPrepend() {
	cout << "Testing prepend()... " << flush;
	// The empty case
	List<double> list0;
	list0.prepend(1);
	assert( list0.myFirst != NULL );
	assert( list0.myLast != NULL );
	assert( list0.myFirst == list0.myLast );
	assert( list0.myFirst->myItem == 1 );
	assert( list0.myFirst->myNext == NULL);
	cout << " 0 " << flush;

	// Non-empty case
	list0.prepend(3);
	assert( list0.myFirst != NULL );
	assert( list0.myLast != NULL );
	assert( list0.myFirst != list0.myLast );
	assert( list0.myFirst->myItem == 3 );
	assert( list0.myFirst->myNext == list0.myLast);
	assert( list0.myFirst->myNext->myItem == list0.myLast->myItem );
	assert( list0.myLast->myItem == 1);
	assert( list0.myLast == list0.myFirst->myNext );
	cout << " 1 " << flush;

	cout << "Passed!" << endl;
}


void ListTester::testInsert() {
	cout << "Testing insert()..." << flush;
	// Empty case
	List<double> list;
	list.insert(5, 0);
	assert( list.myFirst != NULL );
	assert( list.myLast != NULL );
	assert( list.myFirst == list.myLast );
	assert( list.myFirst->myItem == 5 );
	assert( list.myFirst->myNext == NULL);
	assert( list.mySize == 1);
	cout << " 0 " << flush;

	// Non-empty index too large
	list.insert(6, 2000);
	assert( list.myFirst != list.myLast );
	assert( list.myFirst->myItem == 5 );
	assert( list.myLast->myItem == 6 );
	assert( list.myFirst->myNext == list.myLast);
	assert( list.myFirst->myNext->myItem == 6 );
	assert( list.myFirst->myNext->myNext == NULL );
	assert( list.mySize == 2);
	cout << " 1 " << flush;

	// Non-empty index negative
	list.insert(4, -1000);
	assert( list.myFirst->myItem == 4 );
	assert( list.myLast->myItem == 6 );
	assert( list.myFirst->myNext->myNext == list.myLast);
	assert( list.myFirst->myNext->myItem == 5 );
	assert( list.myFirst->myNext->myNext->myItem == 6 );
	assert( list.myFirst->myNext->myNext->myNext == NULL );
	assert( list.mySize == 3);
	cout << " 2 " << flush;

	// Non-empty index 0
	list.insert(3,0);
	assert( list.myFirst->myItem == 3 );
	assert( list.myLast->myItem == 6 );
	assert( list.myFirst->myNext->myNext->myNext == list.myLast);
	assert( list.myFirst->myNext->myItem == 4 );
	assert( list.myFirst->myNext->myNext->myItem == 5 );
	assert( list.myFirst->myNext->myNext->myNext->myItem == 6 );
	assert( list.myFirst->myNext->myNext->myNext->myNext == NULL );
	assert( list.mySize == 4);
	cout << " 3 " << flush;

	// Non-empty in range index
	list.insert(20, 2);
	assert( list.myFirst->myItem == 3 );
	assert( list.myLast->myItem == 6 );
	assert( list.myFirst->myNext->myNext->myNext->myNext == list.myLast);
	assert( list.myFirst->myNext->myItem == 4 );
	assert( list.myFirst->myNext->myNext->myItem == 20 );
	assert( list.myFirst->myNext->myNext->myNext->myItem == 5 );
	assert( list.myFirst->myNext->myNext->myNext->myNext->myItem == 6 );
	assert( list.myFirst->myNext->myNext->myNext->myNext->myNext == NULL );
	assert( list.mySize == 5);
	cout << " 4 " << flush;

	cout << "Passed!" << endl;
}



void ListTester::testInequality() {
    cout << "Testing Inequality... " << flush;
    //Work on empty?
    List<double> l1;
    List<double> l2;
    assert (!( l1 != l2 ));
    cout << " 0 " << flush;
    //Works on same? (Using not not equal to.)
    l1.append(11);
    l1.append(22);
    l1.append(33);
    l2.append(11);
    l2.append(22);
    l2.append(33);
    assert (!( l1 != l2 ));
    cout << " 1 " << flush;
    //Works on different sizes?
    l2.append(33);
    assert ( l1 != l2 );
    cout << " 2 " << flush;
    cout << "Passed! " << endl;
}

void ListTester::testWriteToStream() {
    cout << "Testing writeTo(ostream)... " << flush;
    //Works normally?
    List<double> l1;
    l1.append(11);
    l1.append(22);
    l1.append(33);
    ofstream fout("lab05CoutTest.txt");
    assert( fout.is_open() );
    l1.writeTo(fout, "\t");
    fout.close();
    fstream fin("lab05CoutTest.txt");
    assert( fin.is_open() );
    string testLine;
    getline(fin, testLine);
    cout<<testLine<<endl;
    assert (testLine == "11	22	33	");
    fin.close();
    cout << " 0 " << flush;
    //Works with newlines?
    List<double> l2;
    l2.append(5);
    l2.append(67);
    l2.append(103);
    ofstream bout("lab05CoutTest.txt");
    assert( bout.is_open() );
    l2.writeTo(bout, "\n");
    bout.close();
    fstream bin("lab05CoutTest.txt");
    assert( bin.is_open() );
    getline(bin, testLine);
    assert (testLine == "5");
    getline(bin, testLine);
    assert (testLine == "67");
    getline(bin, testLine);
    assert (testLine == "103");
    bin.close();
    cout << " 1 " << flush;
    //Works on empty lists?
    List<double> l3;
    ofstream hout("lab05CoutTest.txt");
    assert( hout.is_open() );
    l3.writeTo(hout, "\t");
    hout.close();
    fstream hin("lab05CoutTest.txt");
    assert( hin.is_open() );
    getline(hin, testLine);
    assert (testLine == "");
    hin.close();
    cout << " 2 " << flush;
    cout << "Passed! " << endl;
}


void ListTester::testReadFromString() {
    cout << "Testing readFrom(string)... " << flush;
    //Works on regular cases?
    List<double> l1;
    l1.append(11);
    l1.append(22);
    l1.append(33);
    l1.append(44);
    ofstream fout("lab05ReadStringTest.txt");
    assert( fout.is_open() );
    l1.writeTo(fout, "\t");
    List<double> l2;
    fout.close();
    l2.readFrom("lab05ReadStringTest.txt");
    assert(!(l1 != l2));
    cout << " 0 " << flush;
    //Works with empty lists?
    List<double> l3;
    ofstream bout("lab05ReadStringTest.txt");
    l3.writeTo(bout, "\t");
    List<double> l4;
    bout.close();
    l4.readFrom("lab05ReadStringTest.txt");
    assert(!(l3 != l4));
    cout << " 1 " << flush;
    //Works with newlines?
    List<double> l5;
    l1.append(3);
    l1.append(46);
    l1.append(369);
    ofstream hout("lab05ReadStringTest.txt");
    l5.writeTo(hout, "\n");
    List<double> l6;
    hout.close();
    l6.readFrom("lab05ReadStringTest.txt");
    assert(!(l5 != l6));
    cout << " 2 " << flush;
    cout << "Passed! " << endl;
}



void ListTester::testGetIndexOf() {
    cout << "Testing getIndexOf()... " << flush;
    //Works on regular cases?
    List<double> l1;
    l1.append(11);
    l1.append(22);
    l1.append(33);
    assert(l1.getIndexOf(22) == 1);
    cout << " 0 " << flush;
    //Works on size 0?
    List<double> l2;
    assert(l2.getIndexOf(22) == -1);
    cout << " 1 " << flush;
    //Works when value not found?
    assert(l1.getIndexOf(44) == -1);
    cout << " 2 " << flush;
    cout << "Passed! " << endl;
}

void ListTester::testRemove() {
    cout << "Testing testRemove()... " << flush;
    //Works on size 1?
    List<double> l5, l6;
    l5.append(11);
    //Test that remove also returns the value of Item deleted.
    assert(l5.remove(1) == 11);
    assert(!(l5 != l6));
    cout << " 0 " << flush;
    //Works on first value?
    List<double> l1;
    l1.append(11);
    l1.append(22);
    l1.append(33);
    l1.append(44);
    List<double> l2;
    l2.append(22);
    l2.append(33);
    l2.append(44);
    assert(l1.remove(0) == 11);
    assert(!(l1 != l2));
    cout << " 1 " << flush;
    //Works on last value?
    List<double> l3;
    l3.append(11);
    l3.append(22);
    l3.append(33);
    l3.append(44);
    List<double> l4;
    l4.append(11);
    l4.append(22);
    l4.append(33);
    assert(l3.remove(4) == 44);
    assert(!(l3 != l4));
    cout << " 2 " << flush;
    //Works on point in the middle that is not first, nor last, nor the only value in list?
    List<double> l7;
    l7.append(1); //index = 0
    l7.append(2); //index = 1
    l7.append(3); //index = 2
    l7.append(4); //index = 3, to be removed.
    l7.append(5); //index = 4
    l7.append(6); //index = 5
    List<double> l8;
    l8.append(1);
    l8.append(2);
    l8.append(3);
    l8.append(5);
    l8.append(6);
    assert(l7.remove(3) == 3);
    assert(!(l7 != l8));
    cout << " 3 " << flush;
    //Works on size 0?
    List<double> l9;
    List<double> l10;
    l9.writeTo(cout, " ");
    l10.writeTo(cout, " ");
    assert(l9.remove(100) == -1);
    assert(!(l9 != l10));
    cout << " 4 " << flush;
    cout << "Passed! " << endl;
}
