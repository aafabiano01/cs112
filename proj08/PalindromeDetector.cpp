/*
 * PalindromeDetector.cpp declares the methods for PalindromeDetector.h
 * Student name: Alex Fabiano
 * Date: 18 Nov, 2019
 */

#include "PalindromeDetector.h"
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <stdio.h>

PalindromeDetector::PalindromeDetector(){

}

void PalindromeDetector::runApp() {
	cout << "Please enter a file name to read palindromes from." << endl;
	cin >> myFile;
	detectPalindromes();
	cout << "Check palindromeout.txt for results." << endl;
}

PalindromeDetector::PalindromeDetector(const string filename) {
	myFile = filename;
	detectPalindromes();
}

void PalindromeDetector::detectPalindromes() {
	ifstream fin;
	fin.open(myFile);
	ofstream fout;
	fout.open("palindromeout.txt");
	assert(fin.is_open());
	string line;
	Stack <char> s1(1);
	ArrayQueue <char> a1(1);
	while(fin.good()) {
		getline(fin, line); //one line at a time
		fout << line; //we can do anything we want to line now that its already output
		if (line.size() > 0) {
			for (unsigned i = 0; i < line.size(); ++i) { //loop through entire string as if array
				if (isalpha(line[i])) { //make sure it is letter, if not, it is skipped
					if (isupper(line[i])) { //make sure it is lowercase
						line[i] = tolower(line[i]);
					}
					char singleletter = line[i];
					try {
						s1.push(singleletter);
					} catch (const StackException& se) {
						s1.setCapacity(s1.getCapacity() * 2);
						s1.push(singleletter);
					}
					try {
						a1.append(singleletter);
					} catch (const FullQueueException& fqe) {
						a1.setCapacity(a1.getCapacity() * 2);
						a1.append(singleletter);
					}
				}
			}
			string ch1;
			string ch2;
			unsigned count = s1.getSize(); //because s1's size will constantly decrease
			for (unsigned i = 0; i < count; ++i) {

				ch1 += s1.pop();

				ch2 += a1.remove();
			}
			if (ch1 == ch2) {
				fout << " ***" << endl;
			} else { //prevents the next line from riding up on the previous one
				fout << "\n";
			}
		} else { //preserves line spacing
			fout << "\n";
		}
	}
	fin.close();
	fout.close();
}
