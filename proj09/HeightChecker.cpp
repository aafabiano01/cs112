/*
 * HeightChecker.cpp defines the methods that the .h will use to calculate the height
 * of the chosen file.
 * CS112 Calvin U
 *  Created on: Nov 21, 2019
 *      Author: aaf25
 */

#include "HeightChecker.h"
#include <iostream>
#include <fstream>
#include <cassert>

void HeightChecker::runApp() {
	while(true) {
		string in = "";
		cout << "Please enter file name (ie: /home/cs/112/proj/09/randomInts10.txt), the directory is already assumed." << endl;
//		for (unsigned i = 0; i < 10; ++i) { //for the sake of my time, ive included a for loop to automate the entering process.
//			cout << "Now calculating for file located at: ";
//			in.append("/home/cs/112/proj/09/randomInts");
//			if (i < 10) { //pesky 0
//				in.append("0");
//				in.append(std::to_string(i));
//			} else {
//				in.append(std::to_string(i));
//			}
//			in.append(".txt");
//			cout << in << endl;
//		}
		cin >> in;
		processFile(in);
	}
}

void HeightChecker::processFile(const string fileName) {
	string results;
	BST <long> fileOut;
	ifstream fin;
	unsigned errorCounter = 0;
	long oneLong;

	fin.open(fileName);
	assert(fin.is_open());
	while(!fin.eof()) {
		fin >> oneLong;
		try {
			fileOut.insert(oneLong);
		} catch (const Exception& e) {
			errorCounter++;
		}
	}
	cout << "Height of tree: " << fileOut.getHeight() << endl;
	cout << "Number of repeated values: " << errorCounter << endl;
}
