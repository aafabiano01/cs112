/*
 * Application.cpp
 *
 *  Created on: Sep 13, 2019
 *      Author: Alex Fabiano
 *      Lab01 in cs112 at Calvin U
 */

#include "Application.h"
#include "PlayList.h"
#include <iostream>
#include "Song.h"
#include <string>
#include <cassert>
//#include "stdlib.h"

Application::Application() {

}
void Application::runApp() const {
	while (true){

		string textInput;
		PlayList pList("saved.txt");
		vector<Song> v;
		cout << "Welcome to the PlayList Manager! \n"
				"Please enter: \n"
				"1 - to search the playlist for songs by a given artist \n"
				"2 - to search the playlist for songs from a given year \n"
				"3 - to search the playlist for songs with a given phrase in their title \n"
				"4 - to add a new song to the playlist \n"
				"5 - to remove a song from the playlist \n"
				"6 - to save the playlist \n"
				"0 - to quit \n"
				"--->" << flush;
		unsigned userInput = 0;
		cin >> userInput;
		if (userInput == 1) {
			cout << "Enter phrase to search for..." << endl;
			cin.ignore();
			getline (cin, textInput);
			v = pList.searchByArtist(textInput);	//v is the playlist used to make sure that
			if (v.size() > 0) {						//it doesnt loop over a vector of size 0
				for (unsigned i = 0; i < v.size(); i++) {
					Song s1 = v[i];
					cout << s1.getTitle() << endl;
					cout << s1.getArtist() << endl;
					cout << s1.getYear() << endl;
			}
			}
			else {
				cout << "No songs by given artist." << endl;
			}

		}
		else if (userInput == 2) {
			cout << "Enter year to search for..." << endl;
			unsigned valInput;
			cin >> valInput;
			while (!cin) {	//makes sure the given value is not a string.
				cout << "Please enter number!" << endl;
				cin.clear();
				cin.ignore();
				cin >> valInput;
			}
			v = pList.searchByYear(valInput);	//stops looping over empty vector
			if (v.size() > 0 ) {
				for (unsigned i = 0; i < v.size(); i++) {
					Song s1 = v[i];
					cout << s1.getTitle() << endl;
					cout << s1.getArtist() << endl;
					cout << s1.getYear() << endl;
			}
			}
			else {
				cout << "No songs from given year." << endl;
			}

		}
		else if (userInput == 3) {
			cout << "Enter phrase to search for..." << endl;
			cin.ignore();
			getline (cin, textInput);
			v = pList.searchByTitlePhrase(textInput);	//stops looping over empty vector
			if (v.size() > 0) {
				for (unsigned i = 0; i < v.size(); i++) {
					Song s1 = v[i];
					cout << s1.getTitle() << endl;
					cout << s1.getArtist() << endl;
					cout << s1.getYear() << endl;
			}
			}
			else {
				cout << "No songs with given phrase in title." << endl;
			}
		}
		else if (userInput == 4) {
				cout << "Enter song title." << endl;
				string givenTitle;
				cin.ignore();
				getline (cin, givenTitle);
				cout << "Enter song artist." << endl;
				string givenArtist;
				getline (cin, givenArtist);
				cout << "Enter the year the song was made." << endl;
				unsigned givenYear;
				cin >> givenYear;
				while (!cin) {	//makes sure the given value is not a string.
					cout << "Please enter number!" << endl;
					cin.clear();
					cin.ignore();
					cin >> givenYear;
				}
				Song s1(givenTitle, givenArtist, givenYear);
				pList.addSong(s1);
		}
		else if (userInput == 5) {
			cout << "Enter song title." << endl;
			string givenTitle;
			cin.ignore();
			getline (cin, givenTitle);
			cout << "Enter song artist." << endl;
			string givenArtist;
			getline (cin, givenArtist);
			cout << "Enter the year the song was made." << endl;
			unsigned givenYear;	//these three variables take in the three components needed to build song
			cin >> givenYear;
			while (!cin) {	//makes sure the given value is not a string.
				cout << "Please enter number!" << endl;
				cin.clear();
				cin.ignore();
				cin >> givenYear;
			}
			vector<Song> testsIfNoSongExists;
			testsIfNoSongExists = pList.searchByYear(givenYear);
			if (testsIfNoSongExists.size() == 0){		//stops error caused by deleting a non existant
				cout << "Song by given specifications does not exist." << endl;					//song
			}
			else {
				Song s1(givenTitle, givenArtist, givenYear);
				pList.removeSong(s1);
				cout << "Song removed." << endl;
			}

		}
		else if (userInput == 6) {
			pList.save();
			cout << "Saved!" << endl;
		}
		else if (userInput == 0) {
			cout <<"Goodbye." << endl;
			break;
		}
		else {
			cout << "Please enter a value between 0 and 6." << endl;
		}
	}

}

