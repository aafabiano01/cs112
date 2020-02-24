/* ReversePoem.cpp defines the methods that will reverse a poem.
 * CS 112 at Calvin University.
 * Student Name: Alex Fabiano
 * Date: 31 Oct, 2019
 */

#include "ReversePoem.h"

ReversePoem::ReversePoem(const string& fileName) : myBodyReversed(1){
	ifstream inFile(fileName.c_str());
	assert(inFile.is_open());
	string line;
	getline(inFile, myTitle);
	getline(inFile, myAuthor);
	getline(inFile, line);
	while(inFile.good()) {
		getline(inFile, line);
		try {
			myBodyReversed.push(line);
		} catch (const StackException& se) {
			myBodyReversed.setCapacity(myBodyReversed.getCapacity() * 2);
			myBodyReversed.push(line);
		}
		myBody.push_back(line);
	}
	inFile.close();
}

string ReversePoem::getTitle() {
	return myTitle;
}

string ReversePoem::getAuthor() {
	return myAuthor;
}

string ReversePoem::getBody() {
	string body;
	for (unsigned i = 0; i < myBody.size(); ++i) {
		body += myBody[i] += "\n";
	}
	return body;
}

string ReversePoem::getBodyReversed() {
	string body;
	for (unsigned i = 0; i < myBodyReversed.getSize() + 1; ++i) {
		body += myBodyReversed.pop() += "\n";
	}
	return body;
}
