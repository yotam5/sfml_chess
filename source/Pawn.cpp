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
    std::vector<std::pair<int, int>> locations;
    int row, column;
    //NOTE how can i move this is a more "way" of this? 
}
