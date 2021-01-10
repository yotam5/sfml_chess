
#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <vector>

#define DIVISOR 2.3
class Menu
{
public:
    Menu(int width, int height, std::vector<std::string> menuTexts,
         sf::RenderWindow *window, int textSize = 50, std::string imageName = "None");
    Menu();
    ~Menu();

    void draw(sf::RenderTarget &target);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return seletedItemIndex; }
    void run(int &); //run menu until play or quit()
private:
    int seletedItemIndex;
    sf::Font font;
    std::vector<sf::Text> menu;
    sf::RenderWindow *window;
    sf::Event event;
    sf::Texture texture;
    sf::Sprite background;
};
