#include <iostream>
#include "functions.h"
#include "../include/Board.h"

#define 如果 if 
int userInput()
{
}

int main() {
    sayHello();
    char tempBoard[8][8] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', 'n', '.', 'Q', 'k', '.', '.', '.'},
        {'.', '.', 'P', 'Q', 'q', '.', '.', '.'},
        {'e', '.', '.', '.', '.', '.', '.', '.'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    };
    // Board a(tempBoard);
    // Board a("r1bk3r/p2pBpNp/n4n2/1p1NP2P/6P1/3P4/P1P1K3/q5b1 w KQkq - 0 1");
    Board a(tempBoard);


    // std::cout << a.getCell(4,5); 
    // std::cout << a.isPossibleMove(4, 4, 0, 4) << std::endl;
    // std::cout << a.isPossibleMove(4, 3, 0, 4) << std::endl;
    // a.possibleMoves(4, 4);
    // a.possibleMoves(3, 4);
    // a.possibleMoves(2,3);
    // a.possibleMoves(1,0);
    // a.possibleMoves(4,3);
    // a.possibleMoves(4,6);

    int tempX, tempY; 
    while (true)
    {
        std::cout << "what moves do you want to do? X, Y\n";
        std::cin >> tempX >> tempY; 
        a.possibleMoves(tempX, tempY);
    }
    std::cout << a.isPossibleMove(1,0,3,1); 
    // a.printBoard();
    // std::cout << a.encodeToFen();
    // std::cout << a.isPossibleMove(7,0, 5,0);
    return 0;
}