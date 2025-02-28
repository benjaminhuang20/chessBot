#include "../include/Board.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <string>

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

    if(piece == 'P'){ //Black and white pieces are different (this is white)
        if(x1 == x2){ //if it wants to go forware
            if(y1 - y2 == 1){ //if it wants to go 1 square forward
                if (board[y2][x1] != '.'){ //if the square doesn't exist
                    return false; 
                }
            } else if (y1 - y2 == 2 && y1 == WHITE_START_RANK_INDEX){
                if (board[y2][x1] != '.' || board[y2 + 1][x1] != '.'){ //if the square doesn't exist
                    return false; 
                }
            } else {
                return false; 
            }
        } else if ((x1 == x2 + 1 || x1 == x2 - 1) && y1 - y2 == 1){ //if diagonally forward
            if(board[y2][x2] == '.'){
                return false; 
            }
        }
        else {
            return false; 
        }
    }

    if (isupper(board[y1][x1]) == isupper(board[y2][x2]) && board[y2][x2] != '.') 
    { // if these are the same color, a piece cannot take a piece of the same color.
        return false;
    }

    return true; 
}
