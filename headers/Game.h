#ifndef GAME_H
#define GAME_H

//sfml
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

//c++
#include <map>
#include <iostream>

//mine
#include "../source/Piece.cpp"

class Game
{
private:
    sf::RenderWindow *window;
    void initWindow();

    std::map<std::string, sf::Texture*> textures;
    void initTexture();
    sf::Sprite board;
    Piece *test1;
public:
    Game();
    virtual ~Game();

    void run();
    void update();
    void updatePollEvents();
    void render();
};

#endif