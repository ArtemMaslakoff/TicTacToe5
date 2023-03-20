#ifndef TICTACTOE_H
#define TICTACTOE_H



#include <vector>
#include <array>
#include "Cage.h"
#include "Player.h"

namespace Logic
{
	class TicTacToe
	{
	private:
		std::vector<Cage> cages;

		Player playerX;
		Player playerO;
	public:
		TicTacToe();

		~TicTacToe();

		std::vector<Cage> GetCages();
		/*vector<Cage> GetCagesX();
		vector<Cage> GetCagesO();*/

		void SwitchPlayer();
		void DoStep(int Ix, int Iy);
		bool CheckCage(int Ix, int Iy);
		CageCondition FindCage(int Ix, int Iy);
		std::array<std::array<CageCondition, 40>, 40> GetMap(Coordinate Icoordinate);
	};
}



#endif /* TICTACTOE_H */