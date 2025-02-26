#include "../include/Board.h"
#include <iostream>
#include <string>
#include <cmath>
        // Correct constructor using `this->`
Board::Board(char board[8][8])
{
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            this->board[i][j] = board[i][j]; // Copy each element individually
        }
    }
}


void Board::setCell(int row, int col, char set){
    this->board[row][col] = set; 
}

char Board::getCell(int row, int col) const{
    return this->board[row][col]; 
}

bool Board::isPossibleMove(int x1, int y1, int x2, int y2) const {
    char piece = board[y1][x1]; //Piece to move
    if(piece == 'R' || piece == 'r'){
        //first needs to make sure that same x or y bcuz rook goes horizontal or vertical
        if(x1 == x2){
            for (int i = std::min(y1, y2) + 1; i < std::max(y1,y2); i++){
                if(board[i][x1] != '.'){
                    return false; 
                }
            }
        }
        else if (y1 == y2)
        {
            for (int i = std::min(x1, x2) + 1; i < std::max(x1,x2); i++){
                if(board[y1][i] != '.'){
                    return false; 
                }
            }
        }
        else
        {
            return false;
        }
    }

    return true; 
}

void Board::printBoard() const {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            std::cout << board[i][j] << " "; // Copy each element individually
        }
        std::cout << "\n"; 
    }
}
