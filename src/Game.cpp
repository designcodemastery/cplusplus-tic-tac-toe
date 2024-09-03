#include "Game.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>    // For srand() and rand()
#include <ctime>      // For time>

void Game::showSplashScreen() const {
    std::cout << "========================================" << std::endl;
    std::cout << "        Welcome to Tic-Tac-Toe!         " << std::endl;
    std::cout << "        A game of Xs and Os.            " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "       Crafted in C++ by Martin         " << std::endl;
    std::cout << "       2024 - Design Code Mastery       " << std::endl;    
    std::cout << "========================================" << std::endl;
    std::cout << "Press Enter to start the game..." << std::endl;
    std::cin.ignore();  // Wait for user to press Enter
}

// Constructor to initialize the game
Game::Game() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Show the splash screen
    showSplashScreen();

    // Get the challengers name
    getChallengerName();

    // Initialize the game board and prompt for the player's name
    initialize();
}

// Method to initialize or reset the game state
void Game::initialize() {
    // Initialize the board with empty spots
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = EMPTY_SPOT;
        }
    }

    // Randomly decide who goes first
    if (std::rand() % 2 == 0) {
        currentPlayer = userSymbol = 'X';
        computerSymbol = 'O';
    } else {
        currentPlayer = userSymbol = 'O';
        computerSymbol = 'X';
        // If the computer goes first, make the computer's move
        std::cout << std::endl << "The computer gets to move first..." << std::endl;
        int computerMove = getComputerMove();

        updateBoard(computerMove, computerSymbol);
    }

    // Display the initial empty board with legend
    displayBoard();
}

// Method to prompt the user for their name
void Game::getChallengerName() {
    std::cout << "Challenger, please enter your name: ";
    std::getline(std::cin, playerName);
    std::cout << "Welcome, " << playerName << "! Let's play Tic-Tac-Toe!!" << std::endl;
}

// Method to display the current state of the board
void Game::displayBoard() const {
    std::cout << std::endl << "  Tic-Tac-Toe Board" << std::endl;
    std::cout << "  1 | 2 | 3 " << std::endl;
    std::cout << " ---|---|---" << std::endl;
    std::cout << "  4 | 5 | 6 " << std::endl;
    std::cout << " ---|---|---" << std::endl;
    std::cout << "  7 | 8 | 9 " << std::endl << std::endl;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << " " << board[i][j];
            if (j < 2) std::cout << " |";
        }
        std::cout << std::endl;
        if (i < 2) std::cout << "-----------" << std::endl;
    }
    std::cout << std::endl;
}

// Method to manage the game loop
void Game::play() {
    bool gameOver = false;

    while (!gameOver) {
        makeMove();
        displayBoard();

        if (checkWin(currentPlayer)) {
            announceResult();
            gameOver = true;
        } else if (checkDraw()) {
            announceResult();
            gameOver = true;
        } else {
            switchPlayer();
        }
    }

    if (promptReplay()) {
        initialize();  // Restart the game
        play();        // Play the game again
    } else {
        std::cout << std::endl << "Thanks for playing, " << playerName << "! Goodbye!" << std::endl;
    }
}

// Method to handle the current player's move
void Game::makeMove() {
    int moveIndex;
    if (currentPlayer == userSymbol) {
        moveIndex = getMoveIndex();
    } else {
        moveIndex = getComputerMove();
    }
    updateBoard(moveIndex, currentPlayer);
}

// Method to switch turns between players
void Game::switchPlayer() {
    if (currentPlayer == userSymbol) {
        currentPlayer = computerSymbol;
    } else {
        currentPlayer = userSymbol;
    }
}

// Method to get a move from the player
int Game::getMoveIndex() const {
    int moveIndex;
    while (true) {
        std::cout << playerName << ", enter the number of the cell where you want to place your " << userSymbol << ": ";
        std::cin >> moveIndex;
        if (isValidMove(moveIndex)) {
            return moveIndex - 1;  // Adjust for 0-based index
        } else {
            std::cout << "Invalid move. Please try again.\n";
        }
    }
}

// Method to validate if a move is valid
bool Game::isValidMove(int index) const {
    if (index < 1 || index > 9) return false;

    int row = (index - 1) / 3;
    int col = (index - 1) % 3;
    return board[row][col] == EMPTY_SPOT;
}

// Method to update the board with a move
void Game::updateBoard(int index, char symbol) {
    int row = index / 3;
    int col = index % 3;
    board[row][col] = symbol;
}

// Method to check if a player has won
bool Game::checkWin(char symbol) const {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) {
        return true;
    }

    return false;
}

// Method to check if the game is a draw
bool Game::checkDraw() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == EMPTY_SPOT) {
                return false;
            }
        }
    }
    return true;
}

// The computer will randomly choose one of the remaining free cells for its move
int Game::getComputerMove() const {
    // Create a list of available cells
    std::vector<int>availableMoves;
    for (int i = 0; i < 9; ++i) {
        if (isValidMove(i + 1)) {
            availableMoves.push_back(i);
        }
    }

    if (!availableMoves.empty()){
        int randomIndex = std::rand() % availableMoves.size();
        return availableMoves[randomIndex];
    }

    return -1;  // Hopefull should never reach here
}

// Method to announce the game result
void Game::announceResult() const {
    if (checkWin(userSymbol)) {
        std::cout << "Congratulations " << playerName << "! You win!" << std::endl;
    } else if (checkWin(computerSymbol)) {
        std::cout << "The computer wins. Better luck next time, " << playerName << "!" << std::endl;
    } else {
        std::cout << "It's a draw! Well played, " << playerName << "." << std::endl;
    }
}

// Method to prompt the player to play again or quit
bool Game::promptReplay() const {
    char choice;
    std::cout << "Would you like to play again? (y/n): ";
    std::cin >> choice;
    return (choice == 'y' || choice == 'Y');
}