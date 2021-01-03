#include "../headers/King.h"

King::King(std::string name, float posX, float posY, sf::Texture *texture)
    : Piece(name, posX, posY, texture)
{
}

King::~King()
{
}