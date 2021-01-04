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
#include "../source/Board.cpp"

class Game
{
    //friend Board;
private:
    sf::RenderWindow *window;
    void initWindow();

    std::map<std::string, sf::Texture *> textures;
    void initTexture();
    sf::Sprite board; //display board (sfml)
    Piece *test1;
    Board *EngineBoard;

public:
    Game();
    virtual ~Game();

    void run();
    void update();
    void updatePollEvents();
    void render();
};

#endif