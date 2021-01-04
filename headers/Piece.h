//chess piece class
//abstract piece

#ifndef CHESS_PICE_H
#define CHESS_PICE_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <string>

class Piece
{
private:
    //variables
    sf::Texture *texture; //make texture static?
    sf::Sprite sprite;
    std::string name;
    //functions
public:
    //constructor and destructor
    Piece(std::string name, float posX, float posY, const sf::Texture *texture);
    Piece();
    virtual ~Piece();

    //functions
    virtual std::string getName() const;
    virtual void setName(std::string);
    virtual void render(sf::RenderTarget &target);
    virtual const sf::Vector2f &getPosition() const;
    //change pos and more stuff?
};

#endif