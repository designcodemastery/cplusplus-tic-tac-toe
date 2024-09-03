# Tic-Tac-Toe Game Architecture

## Overview

The Tic-Tac-Toe game is a console application implemented in C++. The game features a player vs. computer setup where the player competes against a simple AI opponent. The game is designed to be run from the command line.

## File Structure

- **`main.cpp`**: The entry point for the application.
- **`Game.cpp`**: Contains the implementation of the `Game` class.
- **`Game.hpp`**: Header file for the `Game` class.

## Classes and Methods

### `Game` Class

The `Game` class encapsulates the functionality of the Tic-Tac-Toe game. It manages the game board, handles player moves, and determines the game outcome.

#### Public Methods

- **`Game()`**: Constructor that initializes the game, shows a splash screen, and sets up the initial state.
- **`void play()`**: Starts and manages the game loop. Handles player and computer moves and checks for game end conditions.

#### Private Methods

- **`void showSplashScreen() const`**: Displays a welcome message and instructions to the user.
- **`void initialize()`**: Initializes or resets the game board and sets up the initial conditions, including deciding who goes first.
- **`void getChallengerName()`**: Prompts the user for their name and displays a welcome message.
- **`void displayBoard() const`**: Displays the current state of the Tic-Tac-Toe board.
- **`void makeMove()`**: Manages the move for the current player (either user or computer).
- **`int getMoveIndex() const`**: Gets the move index from the user.
- **`bool isValidMove(int index) const`**: Checks if a move is valid.
- **`void updateBoard(int index, char symbol)`**: Updates the board with the given move.
- **`bool checkWin(char symbol) const`**: Checks if the given symbol has won the game.
- **`bool checkDraw() const`**: Checks if the game has ended in a draw.
- **`void switchPlayer()`**: Switches the turn between the user and the computer.
- **`int getComputerMove() const`**: Determines the computer's move using a simple random choice algorithm.
- **`void announceResult() const`**: Announces the result of the game (win, loss, or draw).
- **`bool promptReplay() const`**: Asks the player if they want to play another game.

## Main Entry Point

The `main.cpp` file contains the `main` function, which serves as the entry point of the application. It creates an instance of the `Game` class and starts the game loop by calling the `play()` method.

```cpp
#include "Game.hpp"

int main() {
    Game game;
    game.play();
    
    return 0;
}
```