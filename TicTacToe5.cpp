#include "TicTacToe5.h"

using namespace std;

namespace Logic
{
	TicTacToe::TicTacToe()
	{
		playerX.SetActive(true);
		playerO.SetActive(false);
	};

	TicTacToe::~TicTacToe() = default;

	vector<Cage> TicTacToe::GetCages()
	{
		return cages;
	};
	/*vector<Cage> TicTacToe::GetCagesX()
	{

	};
	vector<Cage> TicTacToe::GetCagesO()
	{

	};*/

	void TicTacToe::SwitchPlayer()
	{
		playerO.ChangeActive();
		playerX.ChangeActive();
	};
	void TicTacToe::DoStep(int Ix, int Iy)
	{
		if (playerX.GetActive())
		{
			cages.push_back(Cage(Coordinate(Ix, Iy), CageCondition(X)));
		}
		if (playerO.GetActive())
		{
			cages.push_back(Cage(Coordinate(Ix, Iy), CageCondition(O)));
		}
		SwitchPlayer();
	};
	bool TicTacToe::CheckCage(int Ix, int Iy)
	{
		for (int i = 0; i < cages.size(); i++)
		{
			if (cages[i].GetCoordinate().GetX() == Ix && cages[i].GetCoordinate().GetY() == Iy)
			{
				return false;
			}
		}
		return true;
	};
	CageCondition TicTacToe::FindCage(int Ix, int Iy)
	{
		for (int i = 0; i < cages.size(); i++)
		{
			if (cages[i].GetCoordinate().GetX() == Ix && cages[i].GetCoordinate().GetY() == Iy)
			{
				return cages[i].GetCondition();
			}
		}
		return FREE;
	};
	array<array<CageCondition, 40>, 40> TicTacToe::GetMap(Coordinate Icoordinate)
	{
		array<array<CageCondition, 40>, 40> result {};
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				result[i][j] = FindCage(i - Icoordinate.GetX(), j + Icoordinate.GetY());
			}
		}
		return result;
	};
} 