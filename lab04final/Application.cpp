/* Application.cpp defines Application class methods.
 * Student Name: Zachary Clark and Alexander Fabiano
 * Date: 10/5/2019
 * Begun by: Us for CS 112 Project 4
 */

#include "Application.h"
#include <iostream>

/* Application run method
 */
void Application::run() {
	// Declare the variables we will use throughout the application.
	unsigned option;
	Matrix mat1, mat2;
	while(true) {
		showOptions();
		cin >> option;

		// Choose what to do based on the input option
		switch(option) {

		// Addition
		case 1:
			mat1 = inputFile(1);
			mat2 = inputFile(2);
			mat1 += mat2;
			break;

		// Subtraction
		case 2:
			mat1 = inputFile(1);
			mat2 = inputFile(2);
			mat1 -= mat2;
			break;

		// Transposition
		case 3:
			mat1 = inputFile(1);
			mat1 = mat1.getTranspose();
			break;

		// Exit
		case 0:
			exit(0);
		}
		// Write the output to the console.
		mat1.writeTo(cout);
	}
}

/* Write the available options to the console
 */
void Application::showOptions() {
	cout << "Please choose an operation:" << endl;
	cout << "		1 - Addition" << endl;
	cout << "		2 - Subtraction" << endl;
	cout << "		3 - Transposition" << endl;
	cout << "		0 - Exit" << endl;
}

/* Ask the user to input a filename and create a matrix from it.
 * @param: matNumber, the matrix number to be displayed when asking for a filename
 * Returns: A Matrix generated from the input fileName.
 */
Matrix Application::inputFile(unsigned matNumber) {
	string fileName = "";
	cout << "Please input a filename for Matrix " << matNumber << ": " << flush;
	cin >> fileName;
	Matrix mat;
	mat.readFrom(fileName);
	return mat;
}
