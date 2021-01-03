//chess board game

//need to implement

#ifndef BOARD_H
#define BOARD_H

#include <array>
#include "./Piece.h"
#define BOARD_SIZE 8

class Board
{
public:
    Board();
    virtual ~Board();
    void startGame();
private:
    void initBoard(); 
    void initBoard();
    Piece *arr[BOARD_SIZE][BOARD_SIZE];
};

#endif