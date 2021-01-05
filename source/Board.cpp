//board class

#pragma once
#include "../headers/Board.h"

//constructor
Board::Board()
{
    this->initVariables();
    this->initBoard();
    this->initTexture();
    this->board[0][1] = new King(0, 1, this->texturePointer["WhiteKing"]);
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
    for (auto &texture : this->texturePointer)
    {
        delete texture.second;
    }
}

//init variables
void Board::initVariables()
{
}

//check if availabe
bool Board::isEmpty(int x, int y) const
{
    return this->board[y][x] == nullptr; //cuz array
}

//init texture
void Board::initTexture()
{
    for (auto pieceName : this->piecesNames)
    {
        this->texturePointer[pieceName] = new sf::Texture;
        if (!this->texturePointer[pieceName]->loadFromFile(this->assertsFolderName + pieceName + ".png"))
        {
            throw std::invalid_argument("ERROR LOADING " + pieceName + ".png\n");
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
            if (this->board[i][k] != nullptr)
            {
                this->board[i][k]->render(target);
            }
        }
    }
}

//init game
void Board::startGame() //NOTE: need all classes before that
{
    std::array<std::string, 16> order = {
        "Rook", "Knight", "Bishop", "Queen", "King", "Knight", "Bishop", "Rook",
        "Pawn", "Pawn", "Pawn", "Pawn", "Pawn", "Pawn", "Pawn", "Pawn"};
    std::string prefix = "White"; //TODO: implement loading game pieces
}

//click to position on board
int Board::clickToPlace(double value)
{
    if (value < 0 || value > 640)
    {
        return -1;
    }
    int key = (int)value;
    key /= 10;
    int loc = 0;
    for (int i = 8; i < 64 && key >= i; i += 8)
    {
        ++loc;
    }
    return loc;
}

//move piece FIXME
void Board::move(int nx, int ny) //the new position need change
{
    auto l = this->board[0][1]->getPossiblePositions(*board);
    auto p = std::make_pair(nx, ny);
    for (auto k : l)
    {
        if (k == p)
        {
            this->board[nx][ny] = this->board[0][1];
            this->board[0][1] = nullptr;
            this->board[nx][ny]->setPositionOnBoard(nx,ny);
        }
    }
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