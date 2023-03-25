#include "PlayerController.h"

using namespace sf;

namespace Visual
{
	PlayerController::PlayerController() {};

	PlayerController::~PlayerController() = default;

	void PlayerController::Check(RenderWindow& window, Event& event, Logic::TicTacToe& tictactoe5, Visual::Drawer drawer, Logic::AI &AI)
	{
		if (/*event.type == event.MouseButtonReleased && */event.mouseButton.button == Mouse::Left && Mouse::getPosition(window).x > 0 && Mouse::getPosition(window).x < 1000 && Mouse::getPosition(window).y > 0 && Mouse::getPosition(window).y < 1000)
		{
			if (tictactoe5.CheckCage(Mouse::getPosition(window).x / 25 - drawer.GetCoordinate().GetX(), Mouse::getPosition(window).y / 25 + drawer.GetCoordinate().GetY()))
			{
				tictactoe5.DoStep(Mouse::getPosition(window).x / 25 - drawer.GetCoordinate().GetX(), Mouse::getPosition(window).y / 25 + drawer.GetCoordinate().GetY());
				AI.DeleteSquare(tictactoe5.GetLastXStep());
				AI.DoStep(tictactoe5);
			}
		}
	};
}