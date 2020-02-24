/* main.cpp is the driver for a Conga line simulation.
 *
 * @author: Joel Adams, for CS 112 at Calvin University.
 *
 * Based on an exercise by Marc LeBlanc from Wheaton College (MS).
 */
#include "ListTester.h"
#include "CongaLine.h"

int main() {
	ListTester lt;
	lt.runTests();
	CongaLine dance("Ann", "Bob");
	dance.run();
}
