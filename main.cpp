//
//  main.cpp
//  2048
//
//  Created by Zach Zager on 5/10/15.
//  Copyright (c) 2015 Zach Zager. All rights reserved.
//

//
// Displays the game's instructions, then loops until the
// player quits.
//

#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include "gameBoard.h" // game board class
#include "termfuncs.h" // includes functions from Tufts'
                       // Intro to Comp Sci course
                       // (namely getachar())

using namespace std;

int main() {

        gameBoard board; // create board object

        // Game Introduction and Directions
        cout << "WELCOME TO THIS 2048 TERMINAL CLONE!\n\n";
        cout << "Directions:\n";
        cout << "To play the game combine identical tiles to get 2048.\n";
        cout << "If a tile equals 2048, YOU WIN.\n";
        cout << "If the board fills up, YOU LOSE.\n";
        cout << "Use the 'w', 'a', 's', and 'd' keys to move the tiles\n";
        cout << "up, down, left, and right respectively.\n";
        cout << "You must press enter after each input.\n";
        cout << "Press any button (and press the 'enter' key) to begin.\n";
        cout << "Press 'q' to quit the game.\n";
        cout << endl;

        char input = ' '; // create input variable

        // loops to run the game
        while (input != 'q') {
                board.printBoard(); // print the board
                cout << "Input: ";
                input = getachar(); //player doesn't have to press enter
                cout << endl;

                if (input == 'q') { // ends the game
                        break;
                } 

                else { // continues the game
                        board.move(input);
                }
        }
        board.printBoard(); // print the board
        return 0;
}




