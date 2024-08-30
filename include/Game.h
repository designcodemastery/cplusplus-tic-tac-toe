#ifndef GAME_H
#define GAME_H

#include <string>

class Game {
public:
    void initialise();
    void displayBoard() const;
    void getUserMove();
    void getComputerMove();
    bool checkWin(char player) const;
    bool checkDraw() const;
    // void switchPlayer();
    void playGame();

private:
    void getPlayerName();
    std::string playerName;
    static const char EMPTY_SPOT = ' '; // Constant for empty spot on the board
    char board[3][3];       // 3x3 game board
    char currentPlayer;     // X or O
    char userSymbol;        // X or O
    char computerSymbol;    // X or O
};

#endif //GAME_H