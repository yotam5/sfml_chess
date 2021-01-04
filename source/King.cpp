
#pragma once
#include "../headers/King.h"

King::King(int posX, int posY,const sf::Texture *texture, std::string name)
    : Piece(posX, posY, texture, name)
{
}

King::~King()
{
}