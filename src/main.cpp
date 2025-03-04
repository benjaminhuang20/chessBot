#include <iostream>
#include <vector>
#include <array>
#include <chrono>
#include "functions.h"
#include "../include/Board.h"



int main() {
    sayHello();
    char tempBoard[8][8] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'.', '.', '.', 'Q', '.', '.', '.', '.'},
        {'.', 'n', '.', 'Q', 'p', '.', '.', '.'},
        {'.', '.', 'P', 'Q', 'q', '.', 'r', '.'},
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
    // while (true)
    // {
        // std::cout << "what moves do you want to do? X, Y\n";
        // std::cin >> tempX >> tempY; 
        // a.possibleMoves(tempX, tempY);
    // }
    std::cout << a.getCell(2,3);


    auto start = std::chrono::high_resolution_clock::now(); // Start time
    std::vector<std::array<int, 2>>  b = a.possibleMovesEfficient(3,2);

    for (int i = 0; i < b.size(); i++){
        a.setCell(b[i][0], b[i][1],'*');
    }
    std::cout << "\n";
    a.printBoard();

    auto end = std::chrono::high_resolution_clock::now(); // End timer
    std::chrono::duration<double> duration = end - start; // Compute duration

    std::cout << "Execution time for Efficient: " << duration.count() << " seconds\n";


    std::cout << a.encodeMoveToPGN(2, 3, 3, 4);
    // std::cout << a.isPossibleMove(1, 0, 3, 1);
    // a.printBoard();
    // std::cout << a.encodeToFen();
    // std::cout << a.isPossibleMove(7,0, 5,0);
    return 0;
}