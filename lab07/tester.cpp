/* tester.cpp is a "driver" to run the tests in the StackTester class.
 * Joel Adams, for CS 112 at Calvin University.
 */
 
#include "StackTester.h"
#include "ReversePoem.h"
#include "RPTester.h"

int main() {
//	StackTester st;
//	st.runTests();
	RPTester rpt;
	rpt.runTests();
	rpt.runApp();
}

