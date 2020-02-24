/*
 * songTester.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: Alex Fabiano
 *      Lab01 in cs112 at Calvin U
 */
using namespace std;
#include "songTester.h"
#include <iostream>
#include <cassert>

#include "Song.h"
#include <fstream>

void SongTester::runTests() {
	cout << "Testing class Song..." << endl;
	testConstructors();
	testReadFrom();
	testWriteTo();
	testSongCompare();
	cout << "All tests passed!" << endl;
}
void SongTester::testSongCompare() {
	cout << "- Comparing ... " << flush;
	Song s111;
	Song s112;
	assert( s111.getTitle() == s112.getTitle());
	assert( s111.getArtist() == s112.getArtist());
	assert( s111.getYear() == s112.getYear());
	//cout << " 0 " << flush;
	Song s113("Saturday Night's Alright For Fighting", "Elton John", 1973);
	Song s114("The Boys Are Back in Town", "Thin Lizzy", 1976);
	Song s115("Sbabaturday Night's Alright For Fighting", "Elton John", 1973);
	//different title than 113
	Song s116("Saturday Night's Alright For Fighting", "Elbow John", 1973);
	//different artist
	Song s117("Saturday Night's Alright For Fighting", "Elton John", 0001);
	//different year
	if (s113 == s113){
		cout << " true " << flush;
	}
	else {
		cout << " false " << flush;
	}
	if (s113 == s115){
		cout << " true " << flush;
	}
	else {
		cout << " false " << flush;
	}
	if (s113 == s116){
		cout << " true " << flush;
	}
	else {
		cout << " false " << flush;
	}
	if (s113 == s117){
		cout << " true " << flush;
	}
	else {
		cout << " false " << flush;
	}
	//if all goes well, order is true false false false, testing against every different
	//part of a song that could be different when compared
	cout << "Passed!" << endl;
}
void SongTester::testConstructors() {
    cout << "- constructors ... " << flush;
    // default constructor
    Song s;
    assert( s.getTitle() == "" );
    assert( s.getArtist() == "" );
    assert( s.getYear() == 0 );
    cout << " 0 " << flush;
    // explicit constructor
    Song s1("Badge", "Cream", 1969);
    assert( s1.getTitle() == "Badge" );
    assert( s1.getArtist() == "Cream" );
    assert( s1.getYear() == 1969 );
    //test that the song we created has the values we sent it.
    cout << " 1 " << flush;

    cout << " Passed!" << endl;
}
void SongTester::testReadFrom() {
   cout << "- readFrom()... " << flush;
   ifstream fin("testSongs.txt");
   assert( fin.is_open() );
   Song s;
   string separator;

   // read first song and separator in test playlist
   s.readFrom(fin);
   getline(fin, separator);
   assert( s.getTitle() == "Call Me Maybe" );
   assert( s.getArtist() == "Carly Rae Jepsen" );
   assert( s.getYear() == 2012 );
   cout << " 0 " << flush;

   // read second song and separator in test playlist
   s.readFrom(fin);
   getline(fin, separator);
   assert( s.getTitle() == "Let It Be" );
   assert( s.getArtist() == "The Beatles" );
   assert( s.getYear() == 1967 );
   cout << " 1 " << flush;

   // read third song and separator in test playlist
   s.readFrom(fin);
   getline(fin, separator);
   assert( s.getTitle() == "Let It Be" );
   assert( s.getArtist() == "Joan Baez" );
   assert( s.getYear() == 1971 );
   cout << " 2 " << flush;

   fin.close();
   cout << "Passed!" << endl;
}
void SongTester::testWriteTo() {
   cout << "- writeTo()... " << flush;

   // declare three songs
   Song s1("Badge", "Cream", 1969);
   Song s2("Godzilla", "Blue Oyster Cult", 1977);
   Song s3("Behind Blue Eyes", "The Who", 1971);

   // write the three songs to an output file
   ofstream fout("testSongOutput.txt");
   assert( fout.is_open() );
   s1.writeTo(fout);
   fout << "---\n";
   s2.writeTo(fout);
   fout << "---\n";
   s3.writeTo(fout);
   fout << "---\n";
   fout.close();

   // use readFrom() to see if writeTo() worked
   ifstream fin("testSongOutput.txt");
   assert( fin.is_open() );
   Song s4, s5, s6;
   string separator;

   // read and check the first song
   s4.readFrom(fin);
   getline(fin, separator);
   assert( s4.getTitle() == "Badge" );
   assert( s4.getArtist() == "Cream" );
   assert( s4.getYear() == 1969 );
   cout << " 0 " << flush;

   // read and check the second song
   s5.readFrom(fin);
   getline(fin, separator);
   assert( s5.getTitle() == "Godzilla" );
   assert( s5.getArtist() == "Blue Oyster Cult" );
   assert( s5.getYear() == 1977 );
   cout << " 1 " << flush;

   // read and check the third song
   s6.readFrom(fin);
   getline(fin, separator);
   assert( s6.getTitle() == "Behind Blue Eyes" );
   assert( s6.getArtist() == "The Who" );
   assert( s6.getYear() == 1971 );
   cout << " 2 " << flush;

   fin.close();
   cout << " Passed!" << endl;
}




