/* StackTester.h declares a test-class for a dynamically allocated (array) Stack.
 * Started by Joel Adams, for CS 112 at Calvin University.
 * Student Name: Alex Fabiano
 * Date: 31 Oct, 2019
 */

#ifndef STACKTESTER_H_
#define STACKTESTER_H_

#include "Stack.h"

class StackTester {
public:
	void runTests();
	void testConstructor();
	void testIsEmpty();
	void testPushPeekTopAndIsFull();
	void testPop();
	void testCopyConstructor();
	void testAssignment();
	void testDestructor();
	void testGetSize();
	void testGetCapacity();
	void testSetCapacity();
};

#endif /*STACKTESTER_H_*/

