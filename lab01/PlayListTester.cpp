/*
 * playlistTester.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: Alex Fabiano
 *      Lab01 in cs112 at Calvin U
 */

#include <iostream>
#include <cassert>
#include "PlayListTester.h"
using namespace std;
#include "PlayList.h"


void PlayListTester::runTests() {
   cout << "\nTesting class PlayList..." << endl;
   testConstructors();
   testSearchByArtist();
   testSearchByYear();
   testSearchByPhrase();
   testAddSong();
   testRemoveSong();
   testSave();
   cout << "All tests passed!" << endl;
}
void PlayListTester::testConstructors() {
   cout << "- constructors..." << flush;
   PlayList pList("testSongs.txt");
   assert( pList.getNumSongs() == 4 );
   cout << " 0 " << flush;

   cout << " Passed!" << endl;
}
void PlayListTester::testAddSong() {
	cout << "- addSong()..." << flush;
	Song s111("h", "h" , 8 );
	PlayList toBeAddedTo("testSongs.txt");
	vector<Song> searched = toBeAddedTo.searchByTitlePhrase("h");
	assert (searched.size() == 0);
	cout << " 0 " << flush;
	toBeAddedTo.addSong(s111);
	searched = toBeAddedTo.searchByTitlePhrase("h");
	assert (searched.size() == 1);
	cout << " 1 " << flush;
	cout << " Passed! " << endl;
}
void PlayListTester::testRemoveSong() {
	cout << "- removeSong()..." << flush;
	Song s111("h", "h" , 8 );
	PlayList toBeAddedTo("testSongs.txt");
	vector<Song> searched = toBeAddedTo.searchByTitlePhrase("h");
	assert (searched.size() == 0);
	//verify playlist is empty
	toBeAddedTo.addSong(s111);
	searched = toBeAddedTo.searchByTitlePhrase("h");
	assert (searched.size() == 1);
	//verify playlist has the h song
	toBeAddedTo.removeSong(s111);
	searched = toBeAddedTo.searchByTitlePhrase("h");
	assert (searched.size() == 0);
	//verify the h song was removed
	cout << " 0 " << flush;
	cout << " Passed! " << endl;
}
void PlayListTester::testSave(){
	cout << "- testSave()..." << flush;
	PlayList pList("testSongs.txt");
	PlayList savedList("saved.txt");
	pList.save();
	cout << " 0 " << flush;
	vector<Song> songsContainingPhrase = savedList.searchByTitlePhrase("Call");
	assert( songsContainingPhrase.size() == 1);
	cout << " 1 " << flush;


	cout << " Passed! " << endl;
}
void PlayListTester::testSearchByPhrase() {
	cout << "- searchByTitlePhrase()..." << flush;
	PlayList pList("testSongs.txt");
	vector<Song> songsContainingPhrase = pList.searchByTitlePhrase("Call");
	assert( songsContainingPhrase.size() == 1);
	cout << " 0 " << flush;
	songsContainingPhrase = pList.searchByTitlePhrase("Let");
	assert( songsContainingPhrase.size() == 2);
	cout << " 1 " << flush;
	songsContainingPhrase = pList.searchByTitlePhrase("Irony");
	assert( songsContainingPhrase.size() == 0);
	cout << " 2 " << flush;

	cout << " Passed! " << endl;
}
void PlayListTester::testSearchByYear() {
	cout << "- searchByYear()..." << flush;
	PlayList pList("testSongs.txt");

	vector<Song> songsOfGivenYear = pList.searchByYear(2015);
	assert( songsOfGivenYear.size() == 0);
	//because there are no songs from 2015 in the testSongs.txt
	cout << " 0 " << flush;
	songsOfGivenYear = pList.searchByYear(2012);
	assert( songsOfGivenYear.size() == 1);
	//1 song from year 2012
	cout << " 1 " << flush;
	songsOfGivenYear = pList.searchByYear(1967);
	assert( songsOfGivenYear.size() == 2);
	//2 songs from year 1967
	cout << " 2 " << flush;

	cout << " Passed! " << endl;
}
void PlayListTester::testSearchByArtist() {
   cout << "- searchByArtist()... " << flush;
   // load a playlist with test songs
   PlayList pList("testSongs.txt");

   // empty case (0 artists)
   vector<Song> searchResult = pList.searchByArtist("Cream");
   assert( searchResult.size() == 0 );
   cout << " 0 " << flush;

   // case of 1 artist
   searchResult = pList.searchByArtist("Baez");
   assert( searchResult.size() == 1 );
   assert( searchResult[0].getTitle() == "Let It Be" );
   cout << " 1 " << flush;

   // case of 2 artists
   searchResult = pList.searchByArtist("Beatles");
   assert( searchResult.size() == 2 );
   assert( searchResult[0].getTitle() == "Let It Be" );
   assert( searchResult[1].getTitle() == "Penny Lane" );
   cout << " 2 " << flush;

   cout << " Passed!" << endl;
}


