#include "./Piece.h"

//King piece

#ifndef KING_H
#define KING_H

class King : public Piece
{
public:
    King(std::string name, float posX, float posY, const sf::Texture *texture);
    ~King();
private:
};

#endif