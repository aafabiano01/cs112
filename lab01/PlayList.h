/*
 * playlist.h
 *
 *  Created on: Sep 10, 2019
 *      Author: Alex Fabiano
 *      Lab01 in cs112 at Calvin U
 */

#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include <string>
using namespace std;
#include "Song.h"
#include <vector>	//STL Vector



class PlayList {
public:
	PlayList(const string& fileName);
	unsigned getNumSongs() const;
	vector<Song> searchByArtist(const string& artist) const;
	vector<Song> searchByYear(unsigned year);
	vector<Song> searchByTitlePhrase(const string& phrase);
	void addSong(const Song& newSong);
	void removeSong(const Song& aSong);
	void save() const;
private:
	vector<Song> mySongs;
};

#endif /* PLAYLIST_H_ */
