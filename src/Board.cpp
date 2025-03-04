#include "../include/Board.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <string>
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
    // explanation: https://www.chess.com/terms/fen-chess
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
        // std::cout << "x: " << x << " y: " << y << " index: " << index << " \n";
    }
}



void Board::setCell(int x, int y, char set){
    this->board[y][x] = set; 
}

char Board::getCell(int x, int y) const{
    return this->board[y][x]; 
}

void Board::printBoard() const {
    char alphabet[] = "ABCDEFGH"; 
    for (int i = 0; i < 8; i++)
    {
        std::cout << 8 - i << " "; //the top is H, then G,... for chess coordinates
        for (int j = 0; j < 8; ++j)
        {
            std::cout << board[i][j] << " "; // Copy each element individually
        }
        std::cout << "\n";
    }
    std::cout << "  "; 
    for (int i = 0; i < 8; i++)
    {
        std::cout << alphabet[i] << " ";
    }

    std::cout << "\n\n"; 
}
