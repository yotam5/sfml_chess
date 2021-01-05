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

class Piece
{
private:
    //variables
    sf::Texture *texture; //make texture static?
    sf::Sprite sprite;
    std::string name;
    std::pair<int, int> locationOnBoard;

    //functions
public:
    //constructor and destructor
    Piece(int posX, int posY, const sf::Texture *texture, std::string name = "Piece");
    Piece();
    virtual ~Piece();

    std::string getName() const;

    //functions
    static bool validateOnBoard(int x, int y);
    void setName(std::string);
    virtual void render(sf::RenderTarget &target);
    const sf::Vector2f &getPosition() const;
    std::pair<int, int> getPositionOnBoard() const;
    void setPositionOnBoard(int x, int y);

    //calculate all posssible positions
    virtual std::vector<std::pair<int, int>> getPossiblePositions(const Piece* board[8][8]) const = 0; //array
    virtual void setPosition(double x, double y, bool arrayMode = false);
    virtual void initVariables() = 0;
    //change pos and more stuff?
};

#endif