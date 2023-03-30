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

		Logic::Coordinate lastXStep;
		Logic::Coordinate lastOStep;

		Player playerX;
		Player playerO;
	public:
		TicTacToe();

		~TicTacToe();

		std::vector<Cage> GetCages();
		Logic::Coordinate GetLastXStep();

		void SwitchPlayer();
		void DoStep(int Ix, int Iy);
		bool CheckCage(int Ix, int Iy);
		CageCondition FindCage(int Ix, int Iy);
		std::array<std::array<CageCondition, 40>, 40> GetMap(Coordinate Icoordinate);
		std::array<std::array<CageCondition, 9>, 9> GetMapL(Coordinate Icoordinate);
		std::array<std::array<CageCondition, 13>, 13> GetMapB(Coordinate Icoordinate);
	};
}



#endif /* TICTACTOE_H */