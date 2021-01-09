//Knight_H class

#ifndef KNIGHT_H
#define KNIGHT_H
#include "../source/Piece.cpp"
#include <array>

class Knight: public Piece
{
public:
    Knight(int posX, int posY, const sf::Texture *texture, Color color, std::string name = "Knight");
    ~Knight();
    std::vector<std::pair<int, int>> getPossiblePositions(const std::array<std::array<Piece*,8>,8> &board) const;

private:
    static const std::array<std::pair<int, int>, 4> directions;
};

#endif