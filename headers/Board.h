//chess board game

//need to implement

#ifndef BOARD_H
#define BOARD_H

#include "../source/Piece.cpp"
#include <map>
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
    Board(std::map<std::string,sf::Texture*> texturesPointer); //pointer to the textures
    virtual ~Board();
    void startGame();
    void draw(sf::RenderTarget &target) const;
    static int clickToPlace(double);
private:
    void initBoard(); 
    Piece *board[BOARD_SIZE][BOARD_SIZE];
    std::map<std::string, sf::Texture *> texturePointer;
};

#endif