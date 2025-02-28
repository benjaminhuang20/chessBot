#ifndef Board_H
#define Board_H


#include <iostream>
#include <string>

class Board {
private:
    char board[8][8];
    const int BLACK_START_RANK_INDEX = 1;
    const int WHITE_START_RANK_INDEX = 6; 

public:
    // Constructor
    Board(char board[8][8]);
    Board(std::string fen); 

    // Method to set a character at a specific position
    void setCell(int row, int col, char value);

    // Method to get a character from a specific position
    char getCell(int row, int col) const;

    void possibleMoves(int x, int y);
    bool isPossibleMove(int x1, int y1, int x2, int y2) const;

    std::string encodeToFen(); 

    // Method to print the board
    void printBoard() const;
};

#endif