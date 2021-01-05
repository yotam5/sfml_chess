
#pragma once
#include "../headers/King.h"

const std::array<std::pair<int, int>, 8> King::directions = {UP, DOWN, LEFT, RIGHT,
                                                             DiagnolDownL, DiagnolDownR, DiagnolUpL, DiagnolUpR};

King::King(int posX, int posY, const sf::Texture *texture, std::string name)
    : Piece(posX, posY, texture, name)
{
}

void King::initVariables()
{
}

King::~King()
{
}

//calculate all posssible positions
std::vector<std::pair<int, int>> King::getPossiblePositions(const Piece board[8][8]) const
{
    std::vector<std::pair<int, int>> locations;
    auto locationOnBoard = Piece::getPositionOnBoard();

    int newX, newY;
    for (auto k : this->directions)
    {
        newX = k.first + locationOnBoard.first;
        newY = k.second + locationOnBoard.second;
        if (Piece::validateOnBoard(newX, newY))
        {
            locations.push_back(std::make_pair(newX, newY));
        }
    }
    return locations;
}