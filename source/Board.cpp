//board class

#include "../headers/Board.h"

//constructor
Board::Board(const std::map<std::string, sf::Texture *> texturesPointer)
{
    this->initBoard();
    this->texturePointer = texturesPointer;
    this->board[0][0] = new Piece("soldier", 80, 80, this->texturePointer["PIECES"]);
}

Board::~Board()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int k = 0; k < BOARD_SIZE; k++)
        {
            delete this->board[i][k];
        }
    }
    std::cout << "delted";
}

//draw
void Board::draw(sf::RenderTarget &target) const
{
    this->board[0][0]->render(target);
}

//init game
void Board::startGame() //need firstly all calsses
{
}

//init board
void Board::initBoard()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int k = 0; k < BOARD_SIZE; k++)
        {
            this->board[i][k] = nullptr;
        }
    }
}