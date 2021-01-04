//board class

#include "../headers/Board.h"

//constructor
Board::Board(const std::map<std::string, sf::Texture *> texturesPointer)
{
    this->initBoard();
    this->texturePointer = texturesPointer;
    this->board[0][1] = new Piece(0, 1, this->texturePointer["PIECES"]);
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
}

//draw
void Board::draw(sf::RenderTarget &target) const
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int k = 0; k < BOARD_SIZE; k++)
        {
            if(this->board[i][k]!=nullptr)
            {
                this->board[i][k]->render(target);
            }
        }
    }}

//init game
void Board::startGame() //need firstly all calsses
{
}

//click to position on board
int Board::clickToPlace(double value)
{
    if(value < 0 || value > 640)
    {
        return -1;
    }
    int key = (int)value;
    key /= 10;
    int loc = 0;
    for(int i = 8; i < 64 && key>= i ;i+=8)
    {
        ++loc;
    }
    return loc;
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