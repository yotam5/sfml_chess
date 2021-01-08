//Rook piece

#ifndef ROOK_H
#define ROOK_H

#include "../source/Piece.cpp"
#include <array>

class Rook : public Piece
{
public:
    Rook(int posX, int posY, const sf::Texture *texture, Color color, std::string name = "Rook");
    ~Rook();
    std::vector<std::pair<int, int>> getPossiblePositions(const std::array<std::array<Piece*,8>,8> &board) const;

private:
    static const std::array<std::pair<int, int>, 4> directions;
};

#endif