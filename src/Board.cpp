#include "../include/Board.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
        // Correct constructor using `this->`
Board::Board(char board[8][8])
{
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            this->board[i][j] = board[i][j]; // Copy each element individually
        }
    }
}
Board::Board(std::string fen){ //fen notation
    int x = 0, y = 0, index = 0;
    while (y < 8)
    {
        if(fen[index] == '/' || x >= 8){
            y++;
            x = 0;
        }
        else if (isdigit(fen[index])){
            int num = fen[index] - '0';
            for (int i = x; i < x + num; i++){
                board[y][i] = '.';
            }
            x = x + num; 
        }
        else
        { // fen[index] is a character
            board[y][x] = fen[index];
            x++;
        }
        index++; 
        std::cout << "x: " << x << " y: " << y << " index: " << index << " \n";
    }
}


void Board::setCell(int x, int y, char set){
    this->board[y][x] = set; 
}

char Board::getCell(int x, int y) const{
    return this->board[y][x]; 
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
      
            if(isupper(board[y1][x1]) == isupper(board[y2][x2])){ //if these are the same color, a piece cannot take a piece of the same color. 
                return false; 
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
