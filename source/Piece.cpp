
#pragma once //including .cpp need also #pragma etc

#include "../headers/Piece.h"

//https://www.iloveimg.com/crop-image

//constructor
Piece::Piece(int row, int column, const sf::Texture *texture,Color color, std::string name)
{
    this->setName(name);
    this->sprite.setTexture(*texture);
    this->sprite.setPosition(column * 80, row * 80); 
    this->locationOnBoard.first = row;               
    this->locationOnBoard.second = column;
    this->color = color;
}

Piece::Piece()
{
}

Piece::~Piece()
{
    //delete this->texture;
}

//set position
void Piece::setPosition(double row, double column, bool arrayMode)
{
    if (!arrayMode)
    {
        this->sprite.setPosition(column * 80, row * 80);
    }
    else
    {
        this->sprite.setPosition(row * 80, column * 80);
    }
}

//set color
void Piece::setColor(Color color)
{
    this->color = color;
}

//get Color
Color Piece::getColor() const
{
    return this->color;
}

//get position on board
std::pair<int, int> Piece::getPositionOnBoard() const
{
    return this->locationOnBoard;
}

//set position on board
void Piece::setPositionOnBoard(int row, int column)
{
    this->locationOnBoard.first = row;
    this->locationOnBoard.second = column;
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
bool Piece::validateOnBoard(int x, int y) //FIXME
{
    if (x >= 0 && x < BOARD_LENGTH && y >= 0 && y < BOARD_LENGTH)
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