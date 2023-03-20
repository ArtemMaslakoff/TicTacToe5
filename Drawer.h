#ifndef DRAWER_H
#define DRAWER_H



#include "Button.h"
#include "TicTacToe5.h"
#include <array>

namespace Visual
{
	class Drawer
	{
	private:
		Logic::Coordinate coordinate;
		std::array<std::array<Visual::Button, 40>, 40> localTable;
	public:
		Drawer();

		~Drawer();

		Logic::Coordinate GetCoordinate();

		void Draw(sf::RenderWindow& window, Logic::TicTacToe& tictactoe);
		void Check();
	};
}



#endif /* DRAWER_H */