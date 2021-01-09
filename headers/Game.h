#ifndef GAME_H
#define GAME_H

//sfml
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "../source/Board.cpp"
//c++
#include <map>
#include <iostream>

//NOTE: need to include here the source for it to work also use pragma once on classes

//make bool turn and draw new after click?

class Game
{
    //friend Board;
private:
    enum States //game states
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

    States currentState = WAITING; //first game state
    Color currentPlayer = WHITE; //first to play
    int rowChoose; 
    int columnChoose;
    bool chess = false; //is there any current chess
public:
    Game();
    virtual ~Game();
    void run();
};

#endif