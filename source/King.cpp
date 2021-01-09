
#pragma once
#include "../headers/King.h"

const std::array<std::pair<int, int>, 8> King::directions = {UP, DOWN, LEFT, RIGHT,
                                                             DiagnolDownL, DiagnolDownR, DiagnolUpL, DiagnolUpR};

King::King(int row, int column, const sf::Texture *texture, Color color, std::string name)
    : Piece(row, column, texture, color, name)
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
    int row, column;
    for (auto k : this->directions)
    {
        row = locationOnBoard.first + k.first;
        column = locationOnBoard.second + k.second;
        if (Piece::validateOnBoard(row, column))
        {
            locations.push_back(std::make_pair(row, column));
        }
    }
    return locations;
}