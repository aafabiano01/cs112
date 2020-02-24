/* ReversePoem.h provides a definitions for methods to reverse poems that can be read both ways.
 * CS 112 at Calvin University.
 * Student Name: Alex Fabiano
 * Date: 31 Oct, 2019
 */

#ifndef REVERSEPOEM_H_
#define REVERSEPOEM_H_

#include "Stack.h"
#include <iostream>
#include <fstream>
using namespace std;
#include <bits/stdc++.h>

class ReversePoem {
public:
	ReversePoem(const string& fileName);
	string getTitle();
	string getAuthor();
	string getBody();
	string getBodyReversed();
private:
	string myTitle;
	string myAuthor;
	vector<string> myBody;
	Stack <string> myBodyReversed;
	friend class RPTester;
};

#endif /* REVERSEPOEM_H_ */
