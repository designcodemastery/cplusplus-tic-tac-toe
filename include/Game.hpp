#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>

class Game {
public:
    // Constructor
    Game();

    // Method to start the game loop
    void play();

private:
    static const char EMPTY_SPOT = ' ';
    char board[3][3];  // 3x3 Tic-Tac-Toe board
    char currentPlayer;
    char userSymbol;
    char computerSymbol;
    std::string playerName;

    // Utility functions
    void showSplashScreen() const;          // Displays the splash screen at startup
    void initialize();                      // Initializes or resets the game
    void getChallengerName();               // Prompts the challenger for their name
    void displayBoard() const;              // Displays the current state of the board
    void makeMove();                        // Manages the current player's move
    int getMoveIndex() const;               // Gets the player's move
    bool isValidMove(int index) const;      // Validates a player's move
    void updateBoard(int index, char symbol); // Updates the board with a move
    bool checkWin(char symbol) const;       // Checks if the current player has won
    bool checkDraw() const;                 // Checks if the game is a draw
    void switchPlayer();                    // Switches turns between players
    int getComputerMove() const;            // Calculates the computer's move (simple AI)
    void announceResult() const;            // Announces the result of the game
    bool promptReplay() const;              // Asks the player if they want to play again
};

#endif // GAME_H