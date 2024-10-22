//chess board game

//need to implement

#ifndef BOARD_H
#define BOARD_H

#include "../source/Piece.cpp"
#include "../source/King.cpp"
#include "../source/Queen.cpp"
#include "../source/Pawn.cpp"
#include "../source/Rook.cpp"
#include "../source/Bishop.cpp"
#include "../source/Knight.cpp"

#include <map>
#include <array>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#define BOARD_SIZE 8

//board class handle game in array
class Board
{
public:
    Board();
    virtual ~Board();
    void startGame();
    void draw(sf::RenderTarget &target) const;
    static int clickToPlace(double);
    Color getColor(int row, int col) const;

    //booleans
    bool isInChess(Color color) const;
    bool canMakeMoveInChess(Color color, std::pair<int, int> move);
    bool isCheckMate(Color color);
    bool move(int rowTo, int columnTo, int rowFrom, int columnFrom);
    bool isEmpty(int x, int y) const;

    //consts
    const Piece *operator()(int row, int col) const;
    const std::string assertsFolderName = "./asserts/";
    const std::array<std::string, 12> piecesNames = {"BlackBishop",
                                                     "BlackKing",
                                                     "BlackKnight",
                                                     "BlackPawn",
                                                     "BlackQueen",
                                                     "BlackRook",
                                                     "WhiteBishop",
                                                     "WhiteKing",
                                                     "WhiteKnight",
                                                     "WhitePawn",
                                                     "WhiteQueen",
                                                     "WhiteRook"};

private:
    void initBoard();
    void initVariables();
    void initTexture();
    bool doMove(int rowTo, int columnTo, int rowFrom, int columnFrom);
    void redoLastMove(int rowTo, int columnTo, int rowFrom, int columnFrom);
    void implementLastMove(int rowTo, int columnTo, int rowFrom, int columnFrom);

    std::array<std::array<Piece *, 8>, 8> board;
    std::map<std::string, sf::Texture *> texturePointer;
    std::array<Piece *, 2> kingsPointers; //(black, white)
    std::vector<std::tuple<std::string, int, int>> trackMoves;
    bool chess;
    Color currentPlayer;
    Piece *saveTo;
};

#endif