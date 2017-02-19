#include "Player.hpp"

Player::Player(float radius):
    m_player(sf::CircleShape(radius))
{
    m_player.setFillColor(sf::Color::Green);
}

void Player::Move(sf::Vector2f offset)
{
    m_player.move(offset);
}

sf::CircleShape Player::GetPlayer()
{
    return m_player;
}
