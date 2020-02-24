/* RPTester.h declares a test-class for the ReversePoem class.
 * CS 112 at Calvin University.
 * Student Name: Alex Fabiano
 * Date: 31 Oct, 2019
 */

#ifndef RPTESTER_H_
#define RPTESTER_H_

#include "ReversePoem.h"
#include "Stack.h"
class RPTester {
public:
	void runTests();
	void testReversed();
	void testConstructorandGetTitleAuthorBody();
	void runApp();
};

#endif /*RPTESTER_H_*/
