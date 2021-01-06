
//pawn piece

#ifndef PAWN_H
#define PAWN_H
#include "../source/Piece.cpp"
#include <array>

class Pawn : public Piece
{
public:
    //NOTE implement movment,  solider can move up or down on board problamatic a bit
    Pawn(int posX, int posY, const sf::Texture *texture, Color color, std::string name = "Pawn");
    ~Pawn();
    std::vector<std::pair<int, int>> getPossiblePositions(const std::array<std::array<Piece *, 8>, 8> &board) const;
private:
    static const std::array<std::pair<int, int>, 6> directions;
};

#endif