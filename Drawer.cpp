#include "Drawer.h"

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

	void Drawer::Draw(RenderWindow& window)
	{
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				localTable[i][j].Draw(window);
			}
		}
	}
}