#include "Cage.h"

namespace Logic
{
    Cage::Cage() : coordinate(Coordinate(0,0)), condition(FREE) {};
    Cage::Cage(Coordinate Icoordinate) : coordinate(Icoordinate), condition(FREE) {};
    Cage::Cage(Coordinate Icoordinate, CageCondition Icondition) : coordinate(Icoordinate), condition(Icondition) {};

    Cage::~Cage() = default;

    void Cage::SetCondition(CageCondition Icondition)
    {
        condition = Icondition;
    };

    Coordinate Cage::GetCoordinate()
    {
        return coordinate;
    };
    CageCondition Cage::GetCondition()
    {
        return condition;
    };
}