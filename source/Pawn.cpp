//pawn class

#pragma once
#include "../headers/Pawn.h"

const std::array<std::pair<int, int>, 6> Pawn::directions = {UP, DiagnolUpL, DiagnolUpR,
                                                             DOWN, DiagnolDownL, DiagnolDownR};

Pawn::Pawn(int row, int column, const sf::Texture *texture, Color color, std::string name)
    : Piece(row, column, texture, color, name)
{
}

//destructor
Pawn::~Pawn()
{
}

//get all positions that posssible +-
std::vector<std::pair<int, int>> Pawn::getPossiblePositions(const std::array<std::array<Piece *, 8>, 8> &board) const
{
    //NOTE how can i move this is a more "way" of this?
    std::vector<std::pair<int, int>> locations;
    int start = (Piece::getColor() == WHITE) ? 0 : 3;
    int end = (Piece::getColor() == WHITE) ? 3 : 6;
    auto locationOnBoard = Piece::getPositionOnBoard();
    int row, column;
    for (int i = start; i < end; i++)
    {
        auto currentDir = directions[i];
        row = locationOnBoard.first + currentDir.first;
        column = locationOnBoard.second + currentDir.second;
        //std::cout << "p" << row << " " << column << "\n";
        if (Piece::validateOnBoard(row, column))
        {
            if (row != locationOnBoard.first && column != locationOnBoard.second) //if it eats
            {
                if (board[row][column] == nullptr || board[row][column]->getColor() == Piece::getColor())
                {
                    continue;
                }
            }
            else
            {
                if (board[row][column] != nullptr)
                {
                    continue;
                }
                if (locationOnBoard.first == 1 || locationOnBoard.first == 6 &&
                    board[row + currentDir.first][column + currentDir.second] == nullptr)
                {
                    locations.push_back(std::make_pair(row + currentDir.first, column + currentDir.second));
                }
            }
            locations.push_back(std::make_pair(row, column));
        }
    }
    //indicate that it moved //NOTE CAN I DO THIS WITH ROW NUMBER ABOVE 1?
    return locations;
}
