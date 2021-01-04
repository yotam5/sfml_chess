#ifndef GAME_H
#define GAME_H

//sfml
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

//c++
#include <map>
#include <iostream>

//NOTE: need to include here the source for it to work also use pragma once on classes
#include "../source/Piece.cpp"
#include "../source/Board.cpp"
//make bool turn and draw new after click?

class Game
{
    //friend Board;
private:
    enum States
    {
        CHOOSE_PIECE,
        CHOOSE_PLACE,
        WAITING
    };
    //sfml variables
    sf::RenderWindow *window;
    std::map<std::string, sf::Texture *> textures;
    sf::Sprite board; //display board (sfml)
    sf::Texture *boardTexture;
    //board class
    Board *EngineBoard;

    //initializers
    void initTexture();
    void initWindow();
    void initVariables();

    //update
    void updatePollEvents();
    void update();
    void render();

    //general
    void handleTurns();

    States state = WAITING;
    int xChoosen;
    int yChoosen;
public:
    Game();
    virtual ~Game();
    void run();
};

#endif