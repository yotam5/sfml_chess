
#pragma once //including .cpp need also #pragma etc

#include "../headers/Piece.h"

//https://www.iloveimg.com/crop-image

//constructor
Piece::Piece(int posX, int posY, const sf::Texture *texture, std::string name)
{
    this->setName(name);
    this->sprite.setTexture(*texture);
    this->sprite.setPosition(posY * 80, posX * 80); //NOTE: because of coordinate its (Y,X)
    this->locationOnBoard.first = posX;             //FIXME just for any case remember
    this->locationOnBoard.second = posY;
}

Piece::Piece()
{
}

Piece::~Piece()
{
    //delete this->texture;
}

//set position
void Piece::setPosition(double x, double y, bool arrayMode)
{
    if (!arrayMode)
    {
        this->sprite.setPosition(y * 80, x * 80);
    }
    else
    {
        this->sprite.setPosition(x * 80, y * 80);
    }
}

//get position on board
std::pair<int, int> Piece::getPositionOnBoard() const
{
    return this->locationOnBoard;
}

//set position on board
void Piece::setPositionOnBoard(int x, int y)
{
    this->locationOnBoard.first = x;
    this->locationOnBoard.second = y;
}

//render
void Piece::render(sf::RenderTarget &target)
{
    target.draw(this->sprite);
}

//set name
void Piece::setName(std::string name)
{
    this->name = name;
}

//check if the move on board
bool Piece::validateOnBoard(int x, int y)
{
    if(x >=0 && x < BOARD_LENGTH && y >=0 && y << BOARD_LENGTH)
    {
        return true;
    }
    return false;
}

//get name
std::string Piece::getName() const
{
    return this->name;
}

//get position
const sf::Vector2f &Piece::getPosition() const
{
    return this->sprite.getPosition();
}