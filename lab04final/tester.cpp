/* tester.cpp drives the testing of our Vec template and Matrix class.
 * Student Name: Zachary Clark and Alexander Fabiano
 * Date: 10/5/2019
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

//#include "VecTester.h"
#include "MatrixTester.h"
#include "Application.h"

int main() {
//	VecTester vt;
//	vt.runTests();
	MatrixTester mt;
	mt.runTests();
	Application app;
	app.run();
}
