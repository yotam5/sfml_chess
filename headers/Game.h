#ifndef GAME_H
#define GAME_H

#define WIDTH 640
#define HEIGHT 640

//sfml
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

//mine
#include "../source/Board.cpp"
#include "../source/Menu.cpp"

//c++
#include <map>
#include <iostream>
#include <unistd.h>

class Game
{
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
    sf::Font font;
    sf::Text text;

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
    Color currentPlayer = WHITE;   //first to play
    int rowChoose;
    int columnChoose;

    bool chess = false;                    //is there any current chess
    vector<string> ops; //game options
    Menu menu;

public:
    Game();
    virtual ~Game();
    void run();
};

#endif