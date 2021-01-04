
#pragma once //including .cpp need also #pragma etc

#include "../headers/Piece.h"

//https://www.iloveimg.com/crop-image

//constructor
Piece::Piece(std::string name, float posX, float posY, const sf::Texture *texture)
{
    this->setName(name);
    this->sprite.setTexture(*texture);
    this->sprite.setPosition(posX, posY);
}

Piece::Piece()
{

}

Piece::~Piece()
{
    //delete this->texture;
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