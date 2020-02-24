/*
 * song.h
 *
 *  Created on: Sep 10, 2019
 *      Author: Alex Fabiano
 *      Lab01 in cs112 at Calvin U
 */

#ifndef SONG_H_
#define SONG_H_
#include <string>
using namespace std;

class Song {
public:
	Song();
	Song(const string& title, const string& artist, unsigned year);
	string getTitle() const;
	string getArtist() const;
	unsigned getYear() const;
	void readFrom(istream& in);
	void writeTo(ostream& out) const;
	bool operator==(const Song& song2) const;
private:
	string myTitle;
	string myArtist;
	unsigned myYear;
};

#endif /* SONG_H_ */
