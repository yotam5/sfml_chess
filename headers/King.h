//King piece

#ifndef KING_H
#define KING_H
#include "../source/Piece.cpp"
#include <array>

class King : public Piece
{
public:
    King(int posX, int posY, const sf::Texture *texture, Color color, std::string name = "King");
    ~King();
    std::vector<std::pair<int, int>> getPossiblePositions(const std::array<std::array<Piece *, 8>, 8> &board) const;

private:
    static const std::array<std::pair<int, int>, 8> directions;
};

#endif