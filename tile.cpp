//
//  tile.cpp
//  2048
//
//  Created by Zach Zager on 5/14/15.
//  Copyright (c) 2015 Zach Zager. All rights reserved.
//

#include "tile.h" 

// constructor
tile::tile() {
	
	// sets tile value to 0 (i.e. no tile)
	val = 0;

}

// desctructor
tile::~tile() {

}

// doubles the value of the tile
void tile::doubleVal() {

	val *= 2;

}

// makes tile value 0
bool tile::makeZero() {

	val = 0;

	return true;

}

// assigns new value to tile
bool tile::takeVal(int newVal) {

	val = newVal;

	return true;

}

// returns the tile value
int tile::getVal() {

	return val;

}

// sets a new tile's value.
// Acts as a reinitializer, in a sense.
void tile::setNew() {

	twoORfour();

}

// prints the value of the tile
void tile::printVal() {

	cout << val;
	
}

// randomly generates a 2 (90%) or a 4 (10%)
void tile::twoORfour() {
        
        int dist = rand() % 10;
        
        if (dist == 0) {
                val = 4;
        } else {
                val = 2;
        }
}

