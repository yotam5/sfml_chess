//queen class

#ifndef QUEEN_H
#define QUEEN_H

#include "./Piece.h"

class Queen : public Piece
{
public:
    Queen(int posX, int posY, const sf::Texture *texture,std::string name = "Piece");
    ~Queen();
};

#endif