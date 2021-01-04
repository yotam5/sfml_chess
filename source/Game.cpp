
#pragma once
#include "../headers/Game.h"

//init window
void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(640, 640), "Chess",
                                        sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);
}

void Game::update()
{
    this->updatePollEvents();
}

Game::Game()
{
    this->initWindow();
    this->initTexture();
    this->initVariables();
}

//init textures
void Game::initTexture() //jpeg error~
{
    this->textures["Board"] = new sf::Texture;
    if (!this->textures["Board"]->loadFromFile("./asserts/board1.png"))
    {
        throw std::invalid_argument("ERROR LOADING BOARD\n");
    }
    this->textures["PIECES"] = new sf::Texture;
    if (!this->textures["PIECES"]->loadFromFile("./asserts/WhiteKing.png"))
    {
        throw std::invalid_argument("ERROR LOADING TEST\n");
    }
}

//initialize variables
void Game::initVariables()
{
    this->board.setTexture(*textures["Board"]);
    this->board.setPosition(0, 0);
    this->EngineBoard = new Board(textures);
}

//destructor
Game::~Game()
{
    for (auto &i : this->textures)
    {
        delete i.second;
    }
    delete EngineBoard;
}

//render game
void Game::render()
{
    this->window->clear();
    this->window->draw(board);
    this->EngineBoard->draw(*this->window);
    this->window->display();
}

void Game::updatePollEvents()
{
    sf::Event ev;
    while (this->window->pollEvent(ev))
    {
        if (ev.type == sf::Event::Closed)
        {
            this->window->close();
        }
        else if(ev.type == sf::Event::MouseButtonPressed) //works as expected
        {
            //handle position stuff
            std::cout << sf::Mouse::getPosition(*this->window).x << std::endl;
        }
    }
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}