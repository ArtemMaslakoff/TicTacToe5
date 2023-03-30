#ifndef AI_H
#define AI_H



#include "Cage.h"
#include "Drawer.h"
#include "TicTacToe5.h"
#include <vector>
#include <array>

namespace Logic
{
	class AI
	{
	private:
		std::vector<Logic::Coordinate> rhombs;
		std::vector<Logic::Coordinate> squares;
		std::vector<Logic::Coordinate> triangles;
	public:
		AI();

		~AI();

		std::vector<Logic::Coordinate> GetRhombs();
		std::vector<Logic::Coordinate> GetSquares();
		std::vector<Logic::Coordinate> GetTriangles();

		void AddRhomb(Logic::Coordinate coordinate);
		void DeleteRhomb(Logic::Coordinate coordinate);

		void AddSquare(Logic::Coordinate coordinate);
		void DeleteSquare(Logic::Coordinate coordinate);

		void AddTriangle(Logic::Coordinate coordinate);
		void DeleteTriangle(Logic::Coordinate coordinate);

		void SQtoTR(Logic::Coordinate coordinate);

		Logic::Coordinate FindFree(Logic::TicTacToe& game);

		void DoStep(Logic::TicTacToe& game);
		int CheckLineA(std::array<Logic::CageCondition, 7>& line, Logic::Coordinate& coordinate);
		void CheckLine(std::array<Logic::CageCondition, 9>& line, Logic::Coordinate& coordinate, int x, int y);
		void CheckAngle(Logic::Coordinate& coordinate, std::array<std::array<Logic::CageCondition, 13>, 13>& localMap);
		void CheckUnic(Logic::Coordinate& coordinate, std::array<std::array<Logic::CageCondition, 9>, 9>& localMap);
		void Check(std::array<std::array<Logic::CageCondition, 9>, 9> &localMap, Coordinate& coordinate, Logic::TicTacToe& game);
	};
}



#endif /* AI_H */