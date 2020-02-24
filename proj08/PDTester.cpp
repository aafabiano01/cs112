/*
 * PDTester.cpp declares the methods for PDTester.h
 * Student name: Alex Fabiano
 * Date: 18 Nov, 2019
 */

#include "PDTester.h"
#include <fstream>

void PDTester::runTests() {
	cout << "Testing class PalindromeDetector..." << endl;
	testConstructor();
	testDetect();
	cout << "All tests passed!\n" << endl;
}

void PDTester::testConstructor() {
	cout << " - testConstructor()..." << flush;
	PalindromeDetector pd("palindrome.txt");
	PalindromeDetector pd2;	//only used in my tester.cpp for my runapp that i didnt include
	assert(pd.myFile == "palindrome.txt");
	cout << " Passed!" << endl;
}

void PDTester::testDetect() {
	cout << " - testDetect()..." << flush;
	PalindromeDetector pd("palindrome.txt");
	ifstream fin;
	fin.open("palindromeout.txt");
	string line;
	getline(fin, line);
	assert(line == "Madam, I'm Adam. ***");
	fin.close();
	PalindromeDetector pd2("drawnonward.txt");
	ifstream bin;
	bin.open("palindromeout.txt");
	getline(bin, line);
	assert(line == "Drawn Onward ***");
	for (unsigned i = 0; i < 11; ++i) { //these lines are not palindromes
		getline(bin, line);
	}
	getline(bin, line);
	assert(line == "\"Madam, I'm Adam\" ***");
	for (unsigned i = 0; i < 5; ++i) { //these lines are not palindromes
		getline(bin, line);
	}
	getline(bin, line);
	assert(line == "\"Eve\" ***");
	bin.close();
	cout << " Passed!" << endl;
}

