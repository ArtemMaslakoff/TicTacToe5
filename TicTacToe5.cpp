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
	Coordinate TicTacToe::GetLastXStep()
	{
		return lastXStep;
	};

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
			lastXStep = Coordinate(Ix, Iy);
		}
		if (playerO.GetActive())
		{
			cages.push_back(Cage(Coordinate(Ix, Iy), CageCondition(O)));
			lastOStep = Coordinate(Ix, Iy);
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
	array<array<CageCondition, 9>, 9> TicTacToe::GetMapL(Coordinate Icoordinate)
	{
		array<array<CageCondition, 9>, 9> result{};
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				result[i][j] = FindCage(Icoordinate.GetX() - 4 + i,Icoordinate.GetY() - 4 + j);
			}
		}
		return result;
	};
	array<array<CageCondition, 13>, 13> TicTacToe::GetMapB(Coordinate Icoordinate)
	{
		array<array<CageCondition, 13>, 13> result{};
		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				result[i][j] = FindCage(Icoordinate.GetX() - 6 + i, Icoordinate.GetY() - 6 + j);
			}
		}
		return result;
	};
} 