#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void Game::getPlayerName() {
    std::cout << "Challenger, please enter your name: ";
    std::getline(std::cin, playerName);
    std::cout << "Welcome, " << playerName << ". Let's play Tic-Tac-Toe!!" << std::endl;
}
void Game::initialise() {
    // Get the players name and welcome them to the game
    getPlayerName();

    // Initialize the board with the EMPTY_SPOT constant
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            board[i][j] = EMPTY_SPOT;
        }        
    }
    displayBoard();
    std::cout << std::endl << "Board Ready..." << std::endl;

    //  Randomly select the starting player
    std::srand(static_cast<unsigned int>(std::time(0)));
    if (std::rand() % 2 == 0)
    {
        userSymbol = 'X';
        computerSymbol = 'O';
        std::cout << playerName << ". You get to go first as 'X'!!" << std::endl;
    } else
    {
        userSymbol = 'O';
        computerSymbol = 'X';
        std::cout << "The computer gets to go first as 'X'!!" << std::endl;       
    }
}

void Game::displayBoard() const {
    // Display the current state of the board
    std::cout << std::endl;
    for (int i = 0; i < 3; ++i) {       // Loop over each row
        for (int j = 0; j < 3; ++j) {   // Loop over each column in the current row
            std::cout << " " << board[i][j];  // Print the board element with spacing
            if (j < 2) std::cout << " |";    // Print column separator except after the last column
        }
        std::cout << std::endl;
        if (i < 2) std::cout << "---+---+---\n";  // Print row separator except after the last row
    }
    std::cout << std::endl;
}

void Game::getUserMove() {
    // Prompt the user to enter a valid move and update the board
    std::cout << "Get Players Move" << std::endl;
}

void Game::getComputerMove() {
    // Determine the computer's move and update the board
    std::cout << "Get Computers Move" << std::endl;
}

bool Game::checkWin(char player) const {
    // Check if the specified player has won
    return true; // Placeholder
}

bool Game::checkDraw() const {
    // Check if the game is a draw
    return true; // Placeholder
}

// void Game::switchPlayer() {
//     // Switch the current player
// }

void Game::playGame() {
    initialise();

    // Main game loop
    while (true) {
        displayBoard();

        if (currentPlayer == userSymbol) {
            getUserMove();
        } else {
            getComputerMove();
        }

        if (checkWin(currentPlayer)) {
            displayBoard();
            std::cout << currentPlayer << " wins!" << std::endl;
            break;
        }

        if (checkDraw()) {
            displayBoard();
            std::cout << "It's a draw!" << std::endl;
            break;
        }

//         switchPlayer();
    }
}