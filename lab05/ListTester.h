/* ListTester.h declares the test-class for class List.
 * Oct 12, 2019 by Alex Fabiano
 * Joel Adams, for CS 112 at Calvin University.
 */

#ifndef LISTTESTER_H_
#define LISTTESTER_H_

class ListTester {
public:
	void runTests();
	void testDefaultConstructor();
	void testNodeDefaultConstructor();
	void testNodeExplicitConstructor();
	void testAppend();
	void testDestructor();
	void testCopyConstructor();
	void testAssignment();
	void testEquality();
	void testInequality();
	void testWriteToStream();
	void testReadFromString();
	void testGetIndexOf();
	void testRemove();
};

#endif /*LISTTESTER_H_*/
