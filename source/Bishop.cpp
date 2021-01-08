//Bishop class

#pragma once
#include "../headers/Bishop.h"

const std::array<std::pair<int, int>, 4> Bishop::directions = {DiagnolUpR, DiagnolUpL,
    DiagnolDownR, DiagnolDownL};

//constructor
Bishop::Bishop(int row, int column, const sf::Texture *texture, Color color, std::string name)
    : Piece(row, column, texture, color, name)
{
}

//destructor
Bishop::~Bishop()
{
}

//calculate all posssible positions
std::vector<std::pair<int, int>> Bishop::getPossiblePositions(const std::array<std::array<Piece *, 8>, 8> &board) const
{
    std::vector<std::pair<int, int>> locations;
    auto locationOnBoard = Piece::getPositionOnBoard();
    //std::cout << "location is " << locationOnBoard.first << " " << locationOnBoard.second << "\n";
    for (auto k : this->directions)
    {
        int row = locationOnBoard.first;
        int column = locationOnBoard.second;

        for (int i = 0; i < BOARD_LENGTH; i++)
        {
            row += k.first;
            column += k.second;
            if (Piece::validateOnBoard(row, column))
            {
                locations.push_back(std::make_pair(row, column));
                if (board[row][column] != nullptr &&
                    board[row][column]->getColor() != Piece::getColor()) //if reached to a solider can move after eat
                {
                    break;
                }
            }
        }
    }
    return locations;
}