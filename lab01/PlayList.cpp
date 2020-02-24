/*
 * playlist.cpp
 *  Created on: Sep 10, 2019
 *      Author: Alex Fabiano
 *      Lab01 in cs112 at Calvin U
 */

/* PlayList.cpp ...
 * ...
 */

#include "PlayList.h"
#include <fstream>      // ifstream
#include <cassert>      // assert()
using namespace std;

//any changes you made to the mySongs playlist will now be changed on a text file named saved.
//no parameters
void PlayList::save() const {
	ofstream fout("saved.txt");
	for (unsigned i = 0; i < mySongs.size(); i++) {
		Song s1 = mySongs[i];
		s1.writeTo(fout);
		fout << "---\n";
	}
	fout.close();

}
/* PlayList constructor
 * @param: fileName, a string
 * Precondition: fileName contains the name of a playlist file.
 */
PlayList::PlayList(const string& fileName) {
   // open a stream to the playlist file
   ifstream fin( fileName.c_str() );
   assert( fin.is_open() );

   // read each song and append it to mySongs
   Song s;
   string separator;
   while (true) {
       s.readFrom(fin);
       if ( !fin ) { break; }
       getline(fin, separator);
       mySongs.push_back(s);
   }

   // close the stream
   fin.close();
}
/* Retrieve length of the playlist
 * Return: the number of songs in the playlist.
 */
unsigned PlayList::getNumSongs() const {
   return mySongs.size();
}
vector<Song> PlayList::searchByYear(unsigned year) {
	  vector<Song> v;

	   for (unsigned i = 0; i < mySongs.size(); i++) {
	      if ( mySongs[i].getYear() == year ) {
	         v.push_back( mySongs[i] );
	      }
	   }

	   return v;
	}
//send a string to this method and receive a vector filled with any songs that contain
//that phrase in their title
//param: title phrase, a string
vector<Song> PlayList::searchByTitlePhrase(const string& phrase) {
	vector<Song> v;
	for (unsigned i = 0; i < mySongs.size(); i++) {
		if ( mySongs[i].getTitle().find(phrase) != string::npos) {
			v.push_back( mySongs[i] );
	    }
	}
	return v;
}
//send this method a song, and it will tag it on to the back of mySongs, but return nothing
//param: Song, a Song object
void PlayList::addSong(const Song& newSong){
	mySongs.push_back( newSong );
}
/* Search by artist
 * @param: artist, a string.
 * Return: a vector containing all the Songs in mySongs by artist.
 */
vector<Song> PlayList::searchByArtist(const string& artist) const {
	vector<Song> v;
	for (unsigned i = 0; i < mySongs.size(); i++) {
		if ( mySongs[i].getArtist().find(artist) != string::npos ) {
			v.push_back( mySongs[i] );
		}
    }
    return v;
}
//send this method a song, and it will search for and remove that song from mySongs, returns nothing
//param: Song, a Song object
void PlayList::removeSong(const Song& aSong) {
	for (unsigned i = 0; i <= mySongs.size(); ++i) {
		if (aSong == mySongs[i]) {
			mySongs.erase(mySongs.begin() + i);
		}
	}
}





