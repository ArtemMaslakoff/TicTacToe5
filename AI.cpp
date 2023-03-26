#include "AI.h"

using namespace std;

namespace Logic
{
	AI::AI() {};

	AI::~AI() = default;

	vector<Logic::Coordinate> AI::GetTriangles()
	{
		return triangles;
	};
	vector<Logic::Coordinate> AI::GetSquares()
	{
		return squares;
	};

	void AI::AddSquare(Logic::Coordinate coordinate)
	{
		bool ind = true;
		for (int i = 0; i < squares.size(); i++)
		{
			if (squares[i].GetX() == coordinate.GetX() && squares[i].GetY() == coordinate.GetY())
			{
				ind = false;
			}
		}
		if (ind)
		{
			squares.push_back(Coordinate(coordinate.GetX(), coordinate.GetY()));
		}
	};
	void AI::DeleteSquare(Logic::Coordinate coordinate)
	{
		for (int i = 0; i < squares.size(); i++)
		{
			if (squares[i].GetX() == coordinate.GetX() && squares[i].GetY() == coordinate.GetY())
			{
				squares.erase(squares.begin() + i);
			}
		}
	};

	void AI::AddTriangle(Logic::Coordinate coordinate)
	{
		bool ind = true;
		for (int i = 0; i < triangles.size(); i++)
		{
			if (triangles[i].GetX() == coordinate.GetX() && triangles[i].GetY() == coordinate.GetY())
			{
				ind = false;
			}
		}
		if (ind)
		{
			triangles.push_back(Coordinate(coordinate.GetX(), coordinate.GetY()));
		}
	};
	void AI::DeleteTriangle(Logic::Coordinate coordinate)
	{
		for (int i = 0; i < triangles.size(); i++)
		{
			if (triangles[i].GetX() == coordinate.GetX() && triangles[i].GetY() == coordinate.GetY())
			{
				triangles.erase(triangles.begin() + i);
			}
		}
	};

	void AI::SQtoTR(Logic::Coordinate coordinate)
	{
		DeleteSquare(coordinate);
		AddTriangle(coordinate);
	};

	Coordinate AI::FindFree(Logic::TicTacToe& game)
	{
		Coordinate result;
		for (int i = 0; i < game.GetCages().size(); i++)
		{
			result = game.GetCages()[i].GetCoordinate();
			if (game.FindCage(result.GetX() + 1, result.GetY()) == FREE)
			{
				result.SetX(result.GetX() + 1);
				result.SetY(result.GetY());
				return result;
			}
		}
		return result;
	};

	void AI::DoStep(Logic::TicTacToe& game)
	{
		//game.DoStep(game.GetLastXStep().GetX() + 1, game.GetLastXStep().GetY() + 1);
		array<array<CageCondition, 9>, 9> localMap = game.GetMapL(game.GetLastXStep());
		Coordinate coordinate = game.GetLastXStep();
		Check(localMap, coordinate);
		
		int num = 0;
		srand(time(NULL));
		if (rhombs.size() != 0)
		{

		}
		else if (squares.size() != 0)
		{
			num = rand() % squares.size();
			game.DoStep(squares[num].GetX(), squares[num].GetY());
			DeleteSquare(squares[num]);
			for (int i = 0; i < squares.size(); i++)
			{
				SQtoTR(squares[i]);
			}
		}
		else if (triangles.size() != 0)
		{
			num = rand() % triangles.size();
			game.DoStep(triangles[num].GetX(), triangles[num].GetY());
			DeleteTriangle(triangles[num]);
		}
		else
		{
			game.DoStep(FindFree(game).GetX(), FindFree(game).GetY());
		}
	};
	void AI::CheckLine(array<CageCondition, 9> &line, Coordinate& coordinate, int x, int y)
	{
		if (line[1] == X && line[2] == X && line[3] == FREE)
		{
			AddSquare(Coordinate(coordinate.GetX() + (-1 * x), coordinate.GetY() + (-1 * y)));
		}

		if (line[1] == X && line[3] == X && line[2] == FREE)
		{
			AddSquare(Coordinate(coordinate.GetX() + (-2 * x), coordinate.GetY() + (-2 * y)));
		}

		if (line[2] == X && line[3] == X)
		{
			if (line[1] == FREE)
			{
				AddSquare(Coordinate(coordinate.GetX() + (-3 * x), coordinate.GetY() + (-3 * y)));
			}
			if (line[5] == FREE)
			{
				AddSquare(Coordinate(coordinate.GetX() + (+1 * x), coordinate.GetY() + (+1 * y)));
			}
		}

		if (line[2] == X && line[5] == X && line[3] == FREE)
		{
			AddSquare(Coordinate(coordinate.GetX() + (-1 * x), coordinate.GetY() + (-1 * y)));
		}

		if (line[3] == X && line[5] == X)
		{
			if (line[2] == FREE)
			{
				AddSquare(Coordinate(coordinate.GetX() + (-2 * x), coordinate.GetY() + (-2 * y)));
			}
			if (line[6] == FREE)
			{
				AddSquare(Coordinate(coordinate.GetX() + (+2 * x), coordinate.GetY() + (+2  * y)));
			}
		}

		if (line[3] == X && line[6] == X && line[5] == FREE)
		{
			AddSquare(Coordinate(coordinate.GetX() + (1 * x), coordinate.GetY() + (1 * y)));
		}

		if (line[5] == X && line[6] == X)
		{
			if (line[3] == FREE)
			{
				AddSquare(Coordinate(coordinate.GetX() + (-1 * x), coordinate.GetY() + (-1 * y)));
			}
			if (line[7] == FREE)
			{
				AddSquare(Coordinate(coordinate.GetX() + (+3 * x), coordinate.GetY() + (+3 * y)));
			}
		}

		if (line[5] == X && line[7] == X && line[6] == FREE)
		{
			AddSquare(Coordinate(coordinate.GetX() + (2 * x), coordinate.GetY() + (2 * y)));
		}

		if (line[6] == X && line[7] == X && line[5] == FREE)
		{
			AddSquare(Coordinate(coordinate.GetX() + (1 * x), coordinate.GetY() + (1 * y)));
		}
	}
	void AI::CheckAngle(Logic::Coordinate& coordinate, array<array<CageCondition, 9>, 9>& localMap)
	{
		/*if ()
		{

		}*/
	};
	void AI::CheckUnic(Logic::Coordinate& coordinate, array<array<CageCondition, 9>, 9>& localMap)
	{
		if (localMap[4][4] == X && localMap[6][6] == X && localMap[6][4] == X && localMap[4][6] == X && localMap[5][5] == FREE)
		{
			AddSquare(Coordinate(coordinate.GetX() + 1, coordinate.GetY() + 1));
		}
		if (localMap[4][4] == X && localMap[2][2] == X && localMap[2][4] == X && localMap[4][2] == X && localMap[3][3] == FREE)
		{
			AddSquare(Coordinate(coordinate.GetX() - 1, coordinate.GetY() - 1));
		}
		if (localMap[4][4] == X && localMap[6][2] == X && localMap[6][4] == X && localMap[4][2] == X && localMap[5][3] == FREE)
		{
			AddSquare(Coordinate(coordinate.GetX() + 1, coordinate.GetY() - 1));
		}
		if (localMap[4][4] == X && localMap[2][6] == X && localMap[2][4] == X && localMap[4][6] == X && localMap[3][5] == FREE)
		{
			AddSquare(Coordinate(coordinate.GetX() - 1, coordinate.GetY() + 1));
		}

		if (localMap[3][3] == X && localMap[4][2] == X && localMap[5][3] == X && localMap[4][4] == X && localMap[4][3] == FREE)
		{
			AddSquare(Coordinate(coordinate.GetX(), coordinate.GetY() - 1));
		}
		if (localMap[3][5] == X && localMap[4][6] == X && localMap[5][5] == X && localMap[4][4] == X && localMap[4][5] == FREE)
		{
			AddSquare(Coordinate(coordinate.GetX(), coordinate.GetY() + 1));
		}
		if (localMap[5][5] == X && localMap[6][4] == X && localMap[5][3] == X && localMap[4][4] == X && localMap[5][4] == FREE)
		{
			AddSquare(Coordinate(coordinate.GetX() + 1, coordinate.GetY()));
		}
		if (localMap[3][3] == X && localMap[2][4] == X && localMap[3][5] == X && localMap[4][4] == X && localMap[3][4] == FREE)
		{
			AddSquare(Coordinate(coordinate.GetX() - 1, coordinate.GetY()));
		}
	};
	void AI::Check(array<array<CageCondition, 9>, 9> &localMap, Coordinate &coordinate)
	{ 
		// HORIZONTAL
		array<CageCondition, 9> line = { localMap[4][0],localMap[4][1],localMap[4][2],localMap[4][3],localMap[4][4],localMap[4][5],localMap[4][6],localMap[4][7],localMap[4][8] };
		CheckLine(line, coordinate, 0, 1);
		// VERTICAL
		line = { localMap[0][4],localMap[1][4],localMap[2][4],localMap[3][4],localMap[4][4],localMap[5][4],localMap[6][4],localMap[7][4],localMap[8][4] };
		CheckLine(line, coordinate, 1, 0);
		// MAINDIAGONAL
		line = { localMap[0][0],localMap[1][1],localMap[2][2],localMap[3][3],localMap[4][4],localMap[5][5],localMap[6][6],localMap[7][7],localMap[8][8] };
		CheckLine(line, coordinate, 1, 1);
		// NOTMAINDIAGONAL
		line = { localMap[8][0],localMap[7][1],localMap[6][2],localMap[5][3],localMap[4][4],localMap[3][5],localMap[2][6],localMap[1][7],localMap[0][8] };
		CheckLine(line, coordinate, -1, 1);
		// ANGLES
		CheckAngle(coordinate, localMap);
		// UNICSITUATIONS
		CheckUnic(coordinate, localMap);
	};
}