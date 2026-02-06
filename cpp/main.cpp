#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <iostream>
unsigned int MAZE_X = 224;
unsigned int MAZE_Y = 248;


// main game loop
int main()
{
    /* ----- USE TO CHECK VERSION OF SFML ----- */
    // std::cout << "Installed SFML Version: "
    //           << SFML_VERSION_MAJOR << "."
    //           << SFML_VERSION_MINOR << "."
    //           << SFML_VERSION_PATCH << std::endl;


    // Init window the size of the maze
    sf::RenderWindow window(sf::VideoMode({4 * MAZE_X, 4 * MAZE_Y}), "SFML Window");

    // load sprite in from sprite sheet
    sf::Texture texture;
    if (!texture.loadFromFile("..\\shared\\Pacman_Sprites_Sounds\\Sprites\\Pac-Man_General_Sprites.png"))
        return 0;
    sf::Sprite maze(texture, sf::IntRect(0, 0, 224, 248));
    maze.setScale(4.0f, 4.0f);
    sf::Sprite Pacman(texture, sf::IntRect(457, 0, 16, 16));
    Pacman.setScale(4.0f, 4.0f);

    // Create a sound buffer, and load the intro sound into that buffer
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("..\\shared\\Pacman_Sprites_Sounds\\Sounds\\start.wav"))
    {
        return -1;
    }

    // initialize the music with a timer for clean loops
    sf::Sound intro_sound;
    intro_sound.setBuffer(buffer);
    sf::Clock pauseTimer;

    // music restart is based on a timer, hence setLoop is set to false
    intro_sound.setLoop(false);
    intro_sound.play();

    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed){
                window.close();
                break;
            }
            if (event.type == sf::Event::KeyReleased){
                if        (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up){
                    // Set Pac-Man Velocity up
                     
                } else if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left){
                    // Set Pac-Man Velocity up

                } else if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down){

                } else if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right){

                }
            }
            
        }

        // --- Sound Looping Logic ---
        if (intro_sound.getStatus() == sf::Sound::Playing)
        {
            // While music is playing, keep the timer at zero
            pauseTimer.restart();
        }
        else if (intro_sound.getStatus() == sf::Sound::Stopped)
        {
            // The music has stopped, so the timer is now ticking up.
            // Check if 2 seconds have passed
            if (pauseTimer.getElapsedTime().asSeconds() > 2.0f)
            {
                intro_sound.play();
            }
        }

        // Clear screen
        window.clear();

        // Draw the sprites
        window.draw(maze);
        window.draw(Pacman);

        // Update the window
        window.display();
    }

    return 0;
}