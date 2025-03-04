#include "../include/Board.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <string>


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

std::string Board::encodeMoveToPGN(int x1, int y1, int x2, int y2){
    char piece = board[y1][x1];
    char coordAlphabet[] = "abcdefgh";
    std::string toReturn = "";
    if (piece == 'p' || piece == 'P')
    {
        if(x1 == x2) { //if it is moving forward
            //no disambiguation needed
            toReturn += coordAlphabet[x1];
            toReturn += std::to_string(8 - y2); //cuz these are indexes so they are 1 off 
            return toReturn;
        } else { //Otherwise it has to be diagonal. disambiguation needed
            toReturn += coordAlphabet[x1];
            toReturn += 'x';
            toReturn += coordAlphabet[x2];
            toReturn += std::to_string(8 - y2);
            return toReturn; 

        }
        
    }

    return toReturn; //returns value in all cases
}
