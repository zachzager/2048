//
//  gameBoard.cpp
//  2048
//
//  Created by Zach Zager on 5/14/15.
//  Copyright (c) 2015 Zach Zager. All rights reserved.
//

#include "gameBoard.h"

// constructor
gameBoard::gameBoard() {

	// set board dimensions (height and width)
	boardHeight = 4;
	boardWidth = 4;

    // randomly place two tiles with a value of 2 (90%) or 4 (90%)
    newTile();
    newTile();

}

// desctructor
gameBoard::~gameBoard() {

}

// places and sets the value of a new tile
void gameBoard::newTile() {

	// initialize random seed
	srand((int)time(NULL));

	// generate # between 0 and 3 for row and col coordinates
    int row = rand() % 4;
    int col = rand() % 4;

    // ensures no tiles exist at coordinates
    while (board[row][col].getVal() != 0) {
    	row = rand() % 4;
    	col = rand() % 4;
    }

    // sets value to 2 (90%) or 4 (90%)
    board[row][col].setNew();

}

// prints the gameboard
void gameBoard::printBoard() {
    for (int i = 0; i < boardHeight; i++) {
        for (int j = 0; j < boardWidth; j++) {
        	board[i][j].printVal();
        	cout << "	  ";
        }
        cout << endl;
    }
}
						/*			     		 */
						/*	   MOVE FUNCTIONS    */
						/*			     		 */

// calls other move functions
void gameBoard::move(char direction) {
            
    // move tiles up
    if (direction == 'w') {
        moveUp();
    }
        
    // move tiles down
    else if (direction == 's') {
        moveDown();
    }
        
    // move tiles left
    else if (direction == 'a') {
        moveLeft();
    }
        
    // move tiles right
    else if (direction == 'd') {
        moveRight();
    }

}

// slides tiles up
void gameBoard::moveUp() {
	bool shouldAdd = false; // notes if a change has been made to the board

	// checks each tile of the board against tiles above it
	for (int i = 1; i < boardHeight; i++) {
		for (int j = 0; j < boardWidth; j++) {
			int row = i; // row number

			while (board[row][j].getVal() != 0 && // moves through empty tiles
					board[row-1][j].getVal() == 0 && row > 0) { 
				board[row-1][j].takeVal(board[row][j].getVal());
				shouldAdd = board[row][j].makeZero(); // new tile to be added
				row--; // decrement row
			}

			if (row > 0) { // continues if not on the last row
				if (board[row][j].getVal() != 0 && //if tile meets an equal
						board[row-1][j].getVal() == board[row][j].getVal()) {
					board[row-1][j].doubleVal();
					shouldAdd = board[row][j].makeZero();//new tile to be added
				}
			}
		}
	}

	if (shouldAdd) // if a change has been made
		newTile(); // adds new tile 
}

// slides tiles down
void gameBoard::moveDown() {
	bool shouldAdd = false; // notes if a change has been made to the board

	// checks each tile of the board against tiles below it
	for (int i = boardHeight-2; i > -1; i--) {
		for (int j = 0; j < boardWidth; j++) {
			int row = i; // row number

			while (board[row][j].getVal() != 0 && // move through empty tiles
					board[row+1][j].getVal() == 0 && row < boardHeight-1) {
				board[row+1][j].takeVal(board[row][j].getVal());
				shouldAdd = board[row][j].makeZero();//new tile should be added
				row++; // increment row
			}

			if (row < boardHeight-1) { // continues if not on the last row
				if (board[row][j].getVal() != 0 && //if tile meets an == tile
						board[row+1][j].getVal() == board[row][j].getVal()) {
					board[row+1][j].doubleVal();
					shouldAdd = board[row][j].makeZero();//new tile to be added
				}
			}
		}
	}

	if (shouldAdd) // if a change has been made
		newTile(); // adds new tile 
}

// slides tiles left
void gameBoard::moveLeft() {
	bool shouldAdd = false; // notes if a change has been made to the board

	// checks each tile of the board against tiles left of it
	for (int i = 0; i < boardHeight; i++) {
		for (int j = 1; j < boardWidth; j++) {
			int col = j; // column number

			while (board[i][col].getVal() != 0 && // move through empty tiles
					board[i][col-1].getVal() == 0 && col > 0) {
				board[i][col-1].takeVal(board[i][col].getVal());
				shouldAdd = board[i][col].makeZero(); // new tile to be added
				col--; // decrement column
            }

			if (col > 0) { // continues if not on the last column
				if (board[i][col].getVal() != 0 && //if tile meets an == tile
						board[i][col-1].getVal() == board[i][col].getVal()) {
					board[i][col-1].doubleVal();
					shouldAdd = board[i][col].makeZero();//new tile to be added
				}
			}
		}
	}

	if (shouldAdd) // if a change has been made
		newTile(); // adds new tile 
}

// slides tiles right
void gameBoard::moveRight() {
	bool shouldAdd = false; // notes if a change has been made to the board

	// checks each tile of the board against tiles to the right of it
	for (int i = 0; i < boardHeight; i++) {
		for (int j = boardWidth-2; j > -1; j--) {
			int col = j; // column number

			// moves through empty tiles
			while (board[i][col].getVal() != 0 && // move through empty tiles
					board[i][col+1].getVal() == 0 && col < boardWidth-1) {
				board[i][col+1].takeVal(board[i][col].getVal());
				shouldAdd = board[i][col].makeZero(); //new tile to be added
				col++; // increment column
			}

			if (col < boardWidth-1) { // continues if not on the last column
				if (board[i][col].getVal() != 0 && //if tile meets an == tile
						board[i][col+1].getVal() == board[i][col].getVal()) {
					board[i][col+1].doubleVal();
					shouldAdd = board[i][col].makeZero();//new tile to be added
				}
			}
		}
	}

	if (shouldAdd) // if a change has been made
		newTile(); // adds new tile
}


