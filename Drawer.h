#include "Button.h"
#include <array>


namespace Visual
{
	class Drawer
	{
	private:
		Coordinate coordinate;
		array<array<Button, 40>, 40> localTable;
	public:
		Drawer();

		~Drawer();

		void Draw(RenderWindow& window);
		void MoveDrawer();
	};
}