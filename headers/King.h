//King piece

#ifndef KING_H
#define KING_H
#include "./Piece.h"

class King : public Piece
{
public:
    King(int posX, int posY, const sf::Texture *texture, std::string name = "King");
    ~King();
private:
};

#endif