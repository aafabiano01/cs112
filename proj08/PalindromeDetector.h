/*
 * PalindromeDetector.h declares a class that combines stacks and queues to
 * determine if a string is a palindrome.
 * Student name: Alex Fabiano
 * Date: 18 Nov, 2019
 */

#ifndef PALINDROMEDETECTOR_H_
#define PALINDROMEDETECTOR_H_

#include "ArrayQueue.h"
#include "Stack.h"

class PalindromeDetector {
public:
	PalindromeDetector();
	PalindromeDetector(const string filename);
	void detectPalindromes();
	void runApp();
private:
	string myFile;
	friend class PDTester;
};


#endif /* PALINDROMEDETECTOR_H_ */
