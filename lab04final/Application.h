/* Application.h declares Application class methods.
 * Student Name: Zachary Clark and Alexander Fabiano
 * Date: 10/5/2019
 * Begun by: Us for CS 112 Project 4
 */

#include <string>
#include "Matrix.h"

using namespace std;

#ifndef APPLICATION_H_
#define APPLICATION_H_

class Application {
public:
	void run();
	void showOptions();
	Matrix inputFile(unsigned matNumber);
};

#endif /* APPLICATION_H_ */
