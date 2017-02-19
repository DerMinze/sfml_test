#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player
{
public:
    Player(float radius);

    // Action
    void Move(sf::Vector2f offset);

    // Get
    sf::CircleShape GetPlayer();

private:
    sf::CircleShape m_player;
};

#endif // PLAYER_HPP
