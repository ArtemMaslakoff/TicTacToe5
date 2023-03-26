#include "Drawer.h"

using namespace std;
using namespace sf;
using namespace Logic;

namespace Visual
{
	Drawer::Drawer() : coordinate(Coordinate(0,0))
	{
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				localTable[i][j] = Button(i,j,25,25,coordinate);
			}
		}
	};

	Drawer::~Drawer() = default;

	Coordinate Drawer::GetCoordinate()
	{
		return coordinate;
	};

	void Drawer::Draw(RenderWindow& window, TicTacToe& tictactoe, vector<Logic::Coordinate> squares)
	{
		array<array<CageCondition, 40>, 40> localMap = tictactoe.GetMap(coordinate);
		for (int i = 0; i < squares.size(); i++)
		{
			if ((squares[i].GetX() >= 0 + coordinate.GetX()) && (squares[i].GetX() < 40 + coordinate.GetX()) && (squares[i].GetY() >= 0 + coordinate.GetY()) && (squares[i].GetY() < 40 + coordinate.GetY()))
			{
				localMap[(int64_t)(squares[i].GetX() + coordinate.GetX())][(int64_t)(squares[i].GetY() + coordinate.GetY())] = SQ;
			}
		}
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				if (localMap[i][j] == X)
				{
					localTable[i][j].Draw(window, "CageX.png");
				}
				else if (localMap[i][j] == O)
				{
					localTable[i][j].Draw(window, "CageO.png");
				}
				else if (localMap[i][j] == SQ)
				{
					localTable[i][j].Draw(window, "CageSQ.png");
				}
				else if (localMap[i][j] == TR)
				{
					localTable[i][j].Draw(window, "CageTR.png");
				}
				else
				{
					localTable[i][j].Draw(window, "Cage.png");
				}
			}
		}
	}
	void Drawer::Check()
	{
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			coordinate.SetX(coordinate.GetX() + 1);
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			coordinate.SetX(coordinate.GetX() - 1);
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			coordinate.SetY(coordinate.GetY() - 1);
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			coordinate.SetY(coordinate.GetY() + 1);
		}
	}
}