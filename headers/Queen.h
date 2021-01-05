//queen class

#ifndef QUEEN_H
#define QUEEN_H

#include "./Piece.h"
#include "../source/directions.cpp"

class Queen : public Piece
{
public:
    Queen(int posX, int posY, const sf::Texture *texture, Color color, std::string name = "Queen");
    ~Queen();
    std::vector<std::pair<int, int>> getPossiblePositions(const std::array<std::array<Piece *, 8>, 8> &board) const;

private:
    static const std::array<std::pair<int, int>, 8> directions;
};

#endif