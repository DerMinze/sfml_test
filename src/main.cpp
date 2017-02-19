#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Player.hpp"
#include "Wall.hpp"

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Create wall
    Wall wall(10);

    // Create player
    Player player(10);

    // Load a music to play
    sf::Music music;
    if (!music.openFromFile("resources/m_music.ogg"))
        return EXIT_FAILURE;

    // Play the music
    music.play();

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Up)
                {
                    player.Move(sf::Vector2f(0, -1));
                }
                if(event.key.code == sf::Keyboard::Down)
                {
                    player.Move(sf::Vector2f(0, 1));
                }
                if(event.key.code == sf::Keyboard::Left)
                {
                    player.Move(sf::Vector2f(-1, 0));
                }
                if(event.key.code == sf::Keyboard::Right)
                {
                    player.Move(sf::Vector2f(1, 0));
                }
            default:
                break;
            }
        }
        // Clear screen
        window.clear();

        // Draw wall
        for(auto & w : wall.GetWall())
        {
            window.draw(w);
        }

        // Draw player
        window.draw(player.GetPlayer());

        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
