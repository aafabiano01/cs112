/*
 * playlistTester.h
 *
 *  Created on: Sep 10, 2019
 *      Author: Alex Fabiano
 *      Lab01 in cs112 at Calvin U
 */

#ifndef PLAYLISTTESTER_H_
#define PLAYLISTTESTER_H_

#include <string>
using namespace std;

class PlayListTester {
public:
    void runTests();
    void testConstructors();
    void testSearchByArtist();
    void testSearchByYear();
    void testSearchByPhrase();
    void testAddSong();
    void testRemoveSong();
    void testSave();
};

#endif /* PLAYLISTTESTER_H_ */
