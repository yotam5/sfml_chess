
#pragma once
#include "../headers/King.h"

const std::array<std::pair<int, int>, 8> King::directions = {UP, DOWN, LEFT, RIGHT,
                                                             DiagnolDownL, DiagnolDownR, DiagnolUpL, DiagnolUpR};

King::King(int row, int column, const sf::Texture *texture, std::string name)
    : Piece(row, column, texture, name)
{
}

void King::initVariables()
{
}

//destructor
King::~King()
{
}

//calculate all posssible positions
std::vector<std::pair<int, int>> King::getPossiblePositions(const std::array<std::array<Piece *, 8>, 8> &board) const
{
    std::vector<std::pair<int, int>> locations;
    auto locationOnBoard = Piece::getPositionOnBoard();
    //std::cout << "location is " << locationOnBoard.first << " " << locationOnBoard.second << "\n";
    int row, column;
    for (auto k : this->directions)
    {
        row = locationOnBoard.first + k.first;
        column = locationOnBoard.second + k.second;
        //std::cout << "p" << row << " " << column << "\n";
        if (Piece::validateOnBoard(row, column))
        {
            locations.push_back(std::make_pair(row, column));
        }
    }
    return locations;
}