/* ListTester.h declares the test-class for class List.
 * Joel Adams, for CS 112 at Calvin University.
 * Student Names: Benedict Jojo Arthur (TM 1) & ALexander Fabiano (TM 2)
 * Date:10/14/2019
 * Proj 05
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
	void testReadFromStream();
	void testWriteToString();
	void testPrepend();
	void testInsert();

	void testInequality();
	void testWriteToStream();
	void testReadFromString();
	void testGetIndexOf();
	void testRemove();

	void testInsertAfter();
	void testInsertBefore();
	void testOutput();
};

#endif /*LISTTESTER_H_*/
