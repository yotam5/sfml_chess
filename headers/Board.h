//chess board game

//need to implement

#ifndef BOARD_H
#define BOARD_H

#include "../source/Piece.cpp"
#include "../source/King.cpp"
#include "../source/Queen.cpp"


#include <map>
#include <array>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#define BOARD_SIZE 8

//TODO: initialize game and board, give each piece texture, name and position
//TODO: convert board here position to the board 640x640

//board class handle game in array
class Board
{
public:
    Board();
    virtual ~Board();
    void startGame();
    void draw(sf::RenderTarget &target) const;
    static int clickToPlace(double);
    bool move(int rowTo, int columnTo, int rowFrom, int columnFrom);
    bool isEmpty(int x, int y) const;
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
    std::array<std::array<Piece*,8>,8> board;
    std::map<std::string, sf::Texture *> texturePointer;
};

#endif