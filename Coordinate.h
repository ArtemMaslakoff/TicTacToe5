#ifndef COORDINATE_H
#define COORDINATE_H



#include <iostream>
#include <array>

namespace Logic
{
	class Coordinate
	{
	private:
		int x;
		int y;
	public:
		Coordinate();
		Coordinate(int Ix, int Iy);
		Coordinate(std::array<int, 2>);

		~Coordinate();

		void Set(int Ix, int Iy);
		void SetX(int Ix);
		void SetY(int Iy);

		std::array<int, 2> Get();
		int GetX();
		int GetY();

		std::array<int, 2> ScalarProduct(std::array<int, 2>);
		//std::array<int, 2> ScalarProduct(Logic::Coordinate Icoordinate);
		//std::array<int, 2> RelativeCoordinates(Logic::Coordinate Icoordinate);
	};
}



#endif /* COORDINATE_H */