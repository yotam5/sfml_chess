//King piece

#ifndef KING_H
#define KING_H
#include "../source/Piece.cpp"
#include <array>
static std::array<std::pair<int, int>, 8> possible;

class King : public Piece
{
public:
    King(int posX, int posY, const sf::Texture *texture, std::string name = "King");
    ~King();
    std::vector<std::pair<int, int>> getPossiblePositions(const Piece board[8][8] const;
    void initVariables();

private:
    static const std::array<std::pair<int, int>, 8> directions;
};

#endif