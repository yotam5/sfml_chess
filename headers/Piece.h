//chess piece class
//abstract piece

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#define BOARD_LENGTH 8
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../source/directions.cpp"

#include <string>
#include <vector>

enum Color //player state
{
    BLACK,
    WHITE
};

class Piece
{
private:
    //variables
    sf::Texture *texture; //make texture static?
    sf::Sprite sprite;
    std::string name;
    std::pair<int, int> locationOnBoard;
    Color color;
    //functions
public:
    //constructor and destructor
    Piece(int posX, int posY, const sf::Texture *texture,Color color, std::string name = "Piece");
    Piece();
    virtual ~Piece();

    std::string getName() const;

    //functions
    static bool validateOnBoard(int x, int y);
    void setName(std::string);
    virtual void render(sf::RenderTarget &target);
    const sf::Vector2f &getPosition() const;
    std::pair<int, int> getPositionOnBoard() const;
    void setPositionOnBoard(int row, int column);
    void setColor(Color color);
    Color getColor() const;
    //calculate all posssible positions
    virtual std::vector<std::pair<int, int>> getPossiblePositions(const std::array<std::array<Piece *, 8>, 8> &board) const = 0; //array
    virtual void setPosition(double x, double y, bool arrayMode = false);
    //virtual void initVariables() = 0;
    //change pos and more stuff?
};

#endif