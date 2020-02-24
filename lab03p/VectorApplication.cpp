/*
 * VectorApplication.cpp
 *
 *  Created on: Sep 27, 2019
 *      Author: aaf25
 */

#include "VectorApplication.h"
#include "Vec.h"
#include <cmath>

VectorApplication::VectorApplication() {
}

void VectorApplication::runApp() const {
	while (true) {
		cout << "Please enter a number of dimensions for your vector." << endl;
		double valInput;
		getInput(valInput);
		valInput = trunc(valInput);  //makes sure the cin does not have decimal value, having an unsigned here
		Vec startingPoint(valInput); //instead of double would make the program crash if it got a double here
		cout << "Please enter a value for your first dimension." << endl;
		double cinDimension;
		getInput(cinDimension);
	//this bit right here is largely redundant, but it makes it so the program doesn't ask
	// you for your next value despite you having not entered one yet. Just a grammatical thing.
		startingPoint[0] = cinDimension;
		for (unsigned i = 1; i < valInput; ++i) {
			cout << "Please enter a dimension." << endl;
			getInput(cinDimension);
			startingPoint[i] = cinDimension;
		}
		cout << "Please enter a number of vectors you would like "
				"to modify your original vector by." << endl;
		double numberVectors;
		getInput(numberVectors);
		valInput = trunc(valInput);
		for (unsigned i = 0; i < numberVectors; ++i) { //intakes the number of vectors the person wants
			Vec addTo(valInput);					          //to enter, loops through that many times
			for (unsigned f = 0; f < valInput; ++f) {  //loops through times the amount of dimensions
				cout << "Please enter a dimension." << endl;
				getInput(cinDimension);
				//puts all the dimensions in order into a temporary vector
				addTo[f] = cinDimension;
			} 	//adds all the values to their counterparts in the starting vector, addTo is reset.
			cout << "Vector finished, adding to starting vector." << endl;
			startingPoint = startingPoint + addTo;
		}
		cout << "Here is your starting point with the vectors of "
				"distance from that point added to it." << endl;
		startingPoint.writeTo(cout);
	}
}

void VectorApplication::getInput(double& storeIn) const {
	cin >> storeIn;
	while (!cin) {	//makes sure the given value is not a string.
		cout << "Please enter number!" << endl;
		cin.clear();
		cin.ignore();
		cin >> storeIn;
	}
}
