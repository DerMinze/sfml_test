#include "Wall.hpp"

Wall::Wall(int length):
    m_wallX(20),
    m_wallY(20)
{
    for(int i = 0; i < length; i++)
    {
        sf::RectangleShape wall(sf::Vector2f(m_wallX, m_wallY));
        wall.setFillColor(sf::Color::Red);
        wall.setPosition(sf::Vector2f(m_wallX * i, m_wallY));
        m_wall.push_back(wall);
    }
}

std::vector<sf::RectangleShape> Wall::GetWall()
{
    return m_wall;
}
