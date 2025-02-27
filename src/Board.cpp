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

void Board::possibleMoves(int x, int y){
    char temp[8][8];
   
    for (int tempY = 0; tempY < 8; tempY++)
    {
        for (int tempX = 0; tempX < 8; tempX++)
        {
            temp[tempY][tempX] = board[tempY][tempX];
            if (isPossibleMove(x, y, tempX, tempY))
            {
                temp[tempY][tempX] = '*';
            }
        }
    }

    Board tempBoard(temp);
    tempBoard.printBoard(); 
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
                // std::cout << "i: " << i << " x1:" << x1 << std::endl; 
            }

        }
        else if (y1 == y2)
        {
            for (int i = std::min(x1, x2) + 1; i < std::max(x1,x2); i++){
                if(board[y1][i] != '.'){
                    std::cout << "it came from here" << i << " " << board[y1][i] << std::endl;
                    return false; 
                }
            }

            
        }
        else
        {
            return false;
        }

        if (isupper(board[y1][x1]) == isupper(board[y2][x2]) && board[y2][x2] != '.')
        { // if these are the same color, a piece cannot take a piece of the same color.
            return false;
        }
    }

    return true; 
}

std::string Board::encodeToFen(){
    std::string fen = "";

    for (int y = 0; y < 8; y++) { 
        int emptyCount = 0;

        for (int x = 0; x < 8; x++) {
            if (board[y][x] == '.') {
                emptyCount++;
            } else {
                if (emptyCount > 0) {
                    fen += std::to_string(emptyCount); 
                    emptyCount = 0;
                }
                fen += board[y][x]; 
            }
        }

        if (emptyCount > 0) {
            fen += std::to_string(emptyCount);
        }

        if (y < 7) {
            fen += "/";
        }
    }
    fen += " w KQkq - 0 1"; 

    return fen;
}

void Board::printBoard() const {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            std::cout << board[i][j] << " "; // Copy each element individually
        }
        std::cout << "\n"; 
    }
}
