#include <SFML/Graphics.hpp>
#include <iostream>
#include "TicTacToe5.h"
#include "Drawer.h"


namespace Visual
{
	class PlayerController
	{
	private:
	public:
		PlayerController();

		~PlayerController();

		void Check(sf::RenderWindow& window, sf::Event& event, Logic::TicTacToe& tictactoe5, Visual::Drawer drawer);
	};
}