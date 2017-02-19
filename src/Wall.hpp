#ifndef WALL_HPP
#define WALL_HPP

#include <SFML/Graphics.hpp>

class Wall
{
public:
    Wall(int length);

    std::vector<sf::RectangleShape> GetWall();

private:
    std::vector<sf::RectangleShape> m_wall;
    float m_wallX;
    float m_wallY;
};

#endif // WALL_HPP
