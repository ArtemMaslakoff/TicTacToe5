#include "Coordinate.h"

using namespace std;

namespace N
{
	Coordinate::Coordinate() : x(0), y(0) {};
	Coordinate::Coordinate(int Ix, int Iy) : x(Ix), y(Iy) {};
	Coordinate::Coordinate(std::array<int, 2> array) : x(array[0]), y(array[1]) {};

	Coordinate::~Coordinate() = default;

	void Coordinate::Set(int Ix, int Iy)
	{
		x = Ix;
		y = Iy;
	};
	void Coordinate::SetX(int Ix)
	{
		x = Ix;
	};
	void Coordinate::SetY(int Iy)
	{
		y = Iy;
	};

	array<int, 2> Coordinate::Get()
	{
		return array<int, 2>{ x, y };
	};
	int Coordinate::GetX()
	{
		return x;
	};
	int Coordinate::GetY()
	{
		return y;
	};

	array<int, 2> Coordinate::ScalarProduct(array<int, 2> Iarray)
	{
		return array<int, 2>{ x * Iarray[0], y* Iarray[1] };
	};

	array<int, 2> Coordinate::ScalarProduct(Coordinate Icoordinate)
	{
		return array<int, 2>{ x * Icoordinate.GetX(), y * Icoordinate.GetY() };
	};

	array<int, 2> Coordinate::RelativeCoordinates(Coordinate Icoordinate)
	{
		return array<int, 2>{ x - Icoordinate.GetX(), y - Icoordinate.GetY() };
	};
}
