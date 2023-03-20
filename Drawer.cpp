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

	void Drawer::Draw(RenderWindow& window, TicTacToe& tictactoe)
	{
		array<array<CageCondition, 40>, 40> localMap = tictactoe.GetMap(coordinate);
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
		cout << coordinate.GetX() << "   " << coordinate.GetY() << endl;
	}
}