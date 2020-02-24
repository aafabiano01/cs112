/*
 * HeightChecker.h declares a class that will create a BST from the values in a file
 * and then find the height of that BST.
 * CS112 Calvin U
 *  Created on: Nov 21, 2019
 *      Author: aaf25
 */

#ifndef HEIGHTCHECKER_H_
#define HEIGHTCHECKER_H_
#include "BST.h"

class HeightChecker {
public:
	void runApp();
	void processFile(const string fileName);
};

#endif /* HEIGHTCHECKER_H_ */
