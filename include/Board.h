#ifndef Board_H
#define Board_H


#include <iostream>

class Board {
private:
    char board[8][8]; 
    int value;  // Private member variable

public:
    // Constructor
    Board(char board[8][8]); 

    // Method to set a character at a specific position
    void setCell(int row, int col, char value);

    // Method to get a character from a specific position
    char getCell(int row, int col) const;

    // Method to print the board
    void printBoard() const;
};

#endif