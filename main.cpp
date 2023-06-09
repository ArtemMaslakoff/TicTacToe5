#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Drawer.h"
#include "PlayerController.h"
#include "TicTacToe5.h"
#include "AI.h"

using namespace sf;
using namespace std;
using namespace Visual;
using namespace Logic;

// M A I N
int main()
{
    RenderWindow window(VideoMode(1000, 1000), "Tic Tac Toe 5", Style::Close);

    TicTacToe game;

    AI ai;

    PlayerController playerController;
    Drawer drawer;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        playerController.Check(window, event, game, drawer, ai);
        drawer.Check();
        drawer.Draw(window, game, ai.GetSquares(), ai.GetTriangles(), ai.GetTriangles());
        window.display();
    }

    return 0;
};