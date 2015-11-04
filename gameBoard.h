 //
//  gameBoard.h
//  2048
//
//  Created by Zach Zager on 5/14/15.
//  Copyright (c) 2015 Zach Zager. All rights reserved.
//

//
// Contains the game board and functions to manipulate it.
//

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */

#include "tile.h"

using namespace std;

class gameBoard {
	public:
	    gameBoard();  		// constructor
	    ~gameBoard(); 		// destructor
	    void newTile();		// initializes a new tile
	    void printBoard();  // prints the board
        void move(char direction); // move function

	private:
		int boardHeight; 	// board height
		int boardWidth; 	// board width
		tile board[4][4]; 	// game board
    
        // move helper functions
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();

};

#endif
