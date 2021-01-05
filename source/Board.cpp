//board class

#pragma once
#include "../headers/Board.h"

//constructor
Board::Board()
{
    this->initVariables();
    this->initBoard();
    this->initTexture();
    this->board[0][1] = new King(0, 1, this->texturePointer["WhiteKing"],WHITE);
    this->board[4][4] = new Queen(4,4,this->texturePointer["BlackQueen"],BLACK);
}

//destructor
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
bool Board::isEmpty(int row, int column) const
{
    if (row >= 0 && column >= 0 && row <= this->board.size() && column <= this->board.size())
        return this->board[row][column] == nullptr; //cuz array
    else 
        throw std::invalid_argument("ERROR IsEmpty out of range\n");
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

//overload subscript
const Piece* Board::operator()(int row, int col) const
{
    return this->board[row][col];
}

//get color in place
Color Board::getColor(int row, int col) const
{
    return this->board[row][col]->getColor();
}

//move piece one board return boolean if move has been done
bool Board::move(int rowTo, int columnTo, int rowFrom, int columnFrom) //the new position need change
{
    auto l = this->board[rowFrom][columnFrom]->getPossiblePositions(board);
    auto p = std::make_pair(rowTo, columnTo); //NOTE the column is the x and row in y is opposite to click
    //std::cout << "move to " << p.first << " " << p.second << "\n";
    for (auto k : l)
    {
        if (k == p)
        {
            std::cout << rowTo << columnTo <<"f"<<std::endl;
            if(this->board[rowTo][columnTo] != nullptr) //NOTE make this a function for general eat cases
            {
                delete this->board[rowTo][columnTo];
                this->board[rowTo][columnTo] = nullptr;
                std::cout << "the queen ate" << std::endl;
            }
            this->board[rowTo][columnTo] = this->board[rowFrom][columnFrom];
            this->board[rowTo][columnTo]->setPosition(rowTo, columnTo);
            this->board[rowTo][columnTo]->setPositionOnBoard(rowTo, columnTo);
            this->board[rowFrom][columnFrom] = nullptr;
            return true;
        }
    }
    return false;
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