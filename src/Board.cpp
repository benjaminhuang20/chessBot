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
                if(board[i][x1] != '.'){ //if it isnt empty it should return false cuz that means theres a piece inbetween them
                    return false; 
                }
            }
        }
        else if (y1 == y2)
        {
            for (int i = std::min(x1, x2) + 1; i < std::max(x1,x2); i++){
                if(board[y1][i] != '.'){ //if it isnt empty it should return false cuz that means theres a piece inbetween them
                    return false; 
                }
            }
        }
        else
        {
            return false;
        }

    }

    if(piece == 'B' || piece == 'b'){
        if(std::abs(x1 - x2) == std::abs(y1-y2)){ //if the y difference and X difference are the same, AKA if they are diagonal
            int currX = std::min(x1, x2) + 1;
            int currY = std::min(y1, y2) + 1; 

            while (currX < std::max(x1,x2) && currY < std::max(y1,y2))
            {
                if(board[currY][currX] != '.') { //if it isnt empty it should return false cuz that means theres a piece inbetween them
                    return false; 
                }
                currX++;
                currY++;
            }
        }
        else
        {
            return false; //if they arent diagonal then boohoo itsfalse now
        }
    }

    if(piece == 'Q' || piece == 'q'){
        if(x1 == x2){
            for (int i = std::min(y1, y2) + 1; i < std::max(y1,y2); i++){
                if(board[i][x1] != '.'){ //if it isnt empty it should return false cuz that means theres a piece inbetween them
                    return false; 
                }
            }
        }
        else if (y1 == y2)
        {
            for (int i = std::min(x1, x2) + 1; i < std::max(x1,x2); i++){
                if(board[y1][i] != '.'){ //if it isnt empty it should return false cuz that means theres a piece inbetween them
                    return false; 
                }
            }
        }
        else if(std::abs(x1 - x2) == std::abs(y1-y2)){ //if the y difference and X difference are the same, AKA if they are diagonal
            int currX = std::min(x1, x2) + 1;
            int currY = std::min(y1, y2) + 1; 

            while (currX < std::max(x1,x2) && currY < std::max(y1,y2))
            {
                if(board[currY][currX] != '.') { //if it isnt empty it should return false cuz that means theres a piece inbetween them
                    return false; 
                }
                currX++;
                currY++;
            }
        }
        else
        {
            return false;
        }
    }

    if (piece == 'K' || piece == 'k'){
        // if(!((std::abs(x1-x2) == 1 || std::abs(y1-y2) == 1) && std::abs(x1 - x2) + std::abs(y1 - y2) <= 2)){
        if((std::abs(x1-x2) != 1 && std::abs(y1-y2) != 1) || std::abs(x1 - x2) + std::abs(y1 - y2) > 2){
            return false; 
        }
    }

    if(piece == 'N' || piece == 'n'){
        if(std::abs(x1 - x2) + std::abs(y1-y2) != 3 || (x1-x2) == 0 || (y1-y2) == 0){ //if the y difference and X difference are the same, AKA if they are diagonal
            return false; //if they arent diagonal then boohoo itsfalse now
        }
    }

    if (isupper(board[y1][x1]) == isupper(board[y2][x2]) && board[y2][x2] != '.')
    { // if these are the same color, a piece cannot take a piece of the same color.
        return false;
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
    char alphabet[] = "ABCDEFGH"; 
    for (int i = 0; i < 8; i++)
    {
        std::cout << alphabet[8 - i - 1] << " "; //the top is H, then G,... for chess coordinates
        for (int j = 0; j < 8; ++j)
        {
            std::cout << board[i][j] << " "; // Copy each element individually
        }
        std::cout << "\n";
    }
    std::cout << "  "; 
    for (int i = 0; i < 8; i++)
    {
        std::cout << i + 1 << " ";
    }

    std::cout << "\n\n"; 
}
