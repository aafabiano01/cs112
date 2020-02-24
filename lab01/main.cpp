/*
 * main.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: Alex Fabiano
 *      Lab01 in cs112 at Calvin U
 */

#include "songTester.h"
#include "PlayListTester.h"
#include "Application.h"

	int main() {
		SongTester sTester;
		sTester.runTests();
		PlayListTester plTester;
		plTester.runTests();
		Application app;
		app.runApp();
	}


