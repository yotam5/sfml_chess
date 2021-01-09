//knight

//Knight class

#pragma once
#include "../headers/Knight.h"

const std::array<std::pair<int, int>, 4> Knight::directions = {UP, DOWN, LEFT, RIGHT};

//constructor
Knight::Knight(int row, int column, const sf::Texture *texture, Color color, std::string name)
    : Piece(row, column, texture, color, name)
{
}

//destructor
Knight::~Knight()
{
}

//calculate all posssible positions
std::vector<std::pair<int, int>> Knight::getPossiblePositions(const std::array<std::array<Piece *, 8>, 8> &board) const
{
    std::vector<std::pair<int, int>> locations;
    auto locationOnBoard = Piece::getPositionOnBoard();
    for (auto k : this->directions)
    {
        int row = locationOnBoard.first + k.first * 2;
        int column = locationOnBoard.second + k.second * 2;

        for (auto option : this->directions)
        {
            if (k == UP && option == DOWN || option == UP && k == DOWN ||
                k == LEFT && option == DOWN || option == LEFT && k == RIGHT)
            {
                continue;
            }
            row += option.first;
            column += option.second;
            if (Piece::validateOnBoard(row, column))
            {
                if (board[row][column] != nullptr &&
                    board[row][column]->getColor() != Piece::getColor() 
                    || board[row][column] == nullptr) 
                {
                    locations.push_back(std::make_pair(row, column));
                }
            }
            row -= option.first;
            column -= option.second;
        }
    }
    return locations;
}