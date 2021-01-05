
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
    this->boardTexture = new sf::Texture;
    if (!this->boardTexture->loadFromFile("./asserts/board1.png"))
    {
        throw std::invalid_argument("ERROR LOADING BOARD\n");
    }
}

//initialize variables
void Game::initVariables()
{
    this->board.setTexture((*this->boardTexture));
    this->board.setPosition(0, 0);
    this->rowChoose = 0;
    this->columnChoose = 0;
    this->EngineBoard = new Board();
}

//destructor
Game::~Game()
{
    for (auto &i : this->textures)
    {
        delete i.second;
    }
    delete EngineBoard; //NOTE: check out segment fault tmporarly
    delete boardTexture;
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
        else if (ev.type == sf::Event::MouseButtonPressed) //works as expected?
        {
            this->handleTurns(); //FIXME segment fault
        }
    }
}

//handle if press on mouse
void Game::handleTurns()
{
    //handle position stuff
    auto MouseData = sf::Mouse::getPosition(*this->window);
    //std::cout << sf::Mouse::getPosition(*this->window).x << std::endl;
    int column = Board::clickToPlace(MouseData.x);
    int row = Board::clickToPlace(MouseData.y);
    if (!EngineBoard->isEmpty(row, column))
    {
        state = CHOOSE_PIECE;
        this->rowChoose = row;
        this->columnChoose = column;
    }
    else if (state == CHOOSE_PIECE /*&& EngineBoard->isEmpty(row, column)*/) //NOTE: it can be nonempty (eaten) need to implement
    {
        state = CHOOSE_PLACE;
    }
    if (state == CHOOSE_PLACE)
    {
        this->EngineBoard->move(row, column, this->rowChoose, this->columnChoose);
        std::cout << "player choose piece and place to put" << std::endl;
        state = WAITING;
    }
}

//run game
void Game::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}