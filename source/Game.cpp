
#pragma once
#include "../headers/Game.h"

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
    this->board.setTexture(*textures["BOARD"]);
    this->board.setPosition(0, 0);
    this->test1 = new Piece("name", 0, 0, this->textures["PIECES"]);
    this->EngineBoard = new Board(textures);
}

void Game::initTexture() //jpeg error~
{
    this->textures["BOARD"] = new sf::Texture;
    if (!this->textures["BOARD"]->loadFromFile("./asserts/board1.png"))
    {
        throw std::invalid_argument("ERROR LOADING BOARD\n");
    }
    this->textures["PIECES"] = new sf::Texture;
    if (!this->textures["PIECES"]->loadFromFile("./asserts/WhiteKing.png"))
    {
        throw std::invalid_argument("ERROR LOADING TEST\n");
    }
}

Game::~Game()
{
    for (auto &i : this->textures)
    {
        delete i.second;
    }
    delete EngineBoard;
}


void Game::render()
{
    this->window->clear();
    this->window->draw(board);
    this->test1->render(*this->window);
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