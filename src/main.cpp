#include <iostream>
#include "functions.h"
#include "../include/Board.h"


int main() {
    sayHello();
    char tempBoard[8][8] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    };
    // Board a(tempBoard);
    Board a("r1bk3r/p2pBpNp/n4n2/1p1NP2P/6P1/3P4/P1P1K3/q5b1"); 
    a.printBoard();
    // std::cout << a.isPossibleMove(7,0, 5,0); 
    return 0;
}