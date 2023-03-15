#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Drawer.h"

using namespace sf;
using namespace std;
using namespace Visual;

class GameScene;

// G A M E 

// M A I N
int main()
{
    RenderWindow window(VideoMode(1000, 1000), "Tic Tac Toe 5", Style::Close);

    Drawer drawer;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        Button a;

        drawer.Draw(window);
        window.display();
    }

    return 0;
};