//
//  tile.h
//  2048
//
//  Created by Zach Zager on 5/14/15.
//  Copyright (c) 2015 Zach Zager. All rights reserved.
//

// Defines the tiles held in each index of the game board
// and functions to manipulate the contents of each 
// individual tile.

#ifndef TILE_H
#define TILE_H

#include <iostream>
//#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */

using namespace std;

class tile {
	public:
	    tile(); // constructor
	    ~tile(); // destructor
	    void doubleVal(); // doubles value
		bool makeZero(); // makes tile value 0
	    bool takeVal(int newVal); // assigns new value to tile
	    int getVal(); // returns the tile value
	    void setNew(); // sets a new tile's value
	    void printVal(); // prints the tile value
	    
	private:
	    int val;
	    void twoORfour(); // intializes value according to the 
	    				  // 90% (2) - 10% (4) distribution
};

#endif
