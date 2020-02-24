/* ReversePoem.cpp defines the methods that will reverse a poem.
 * CS 112 at Calvin University.
 * Student Name: Alex Fabiano
 * Date: 31 Oct, 2019
 */

#include "RPTester.h"
#include <cassert>

void RPTester::runApp() {
	while(true) {
		string name;
		cout << "Enter the name of the poem file:" << flush;
		cin >> name;
		ReversePoem rp (name);
		cout << "\n" << rp.getTitle() << "\n" << rp.getAuthor() << "\n\n" << rp.getBody() << "\n" << " *** Bottom-To-Top *** " << "\n\n" << rp.getBodyReversed() << endl;
	}
}

void RPTester::runTests() {
	cout << "Testing ReversePoem class..." << endl;
	testConstructorandGetTitleAuthorBody();
	testReversed();
	cout << "All tests passed!" << endl;
}

void RPTester::testConstructorandGetTitleAuthorBody() {
	cout << "- Testing getTitleAuthorBody()... " << flush;
	ReversePoem rp ("poems/a.txt");
	assert (rp.getTitle() == "T t");
	cout << " 0 " << flush;
	assert (rp.getAuthor() == "A a");
	cout << " 1 " << flush;
	assert(rp.getBody() == "L 1\nl 2\n");
	cout << " 2 " << flush;
	cout << " Passed!" << endl;
}

void RPTester::testReversed() {
	cout << "- Testing getBodyReversed()... " << flush;
	ReversePoem rp ("poems/a.txt");
	assert(rp.getBodyReversed() == "l 2\nL 1\n");
	cout << " Passed!" << endl;
}
