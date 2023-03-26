#ifndef CAGE_H
#define CAGE_H



#include "Coordinate.h"

namespace Logic
{
    enum CageCondition
    {
        X = -1,
        FREE = 0,
        O = 1,
        TR = 3,
        SQ = 4,
        RB = 5
    };

    class Cage
    {
    private:
        Logic::Coordinate coordinate;
        Logic::CageCondition condition;
    public:
        Cage();
        Cage(Logic::Coordinate Icoordinate);
        Cage(Logic::Coordinate Icoordinate, Logic::CageCondition Icondition);

        ~Cage();

        void SetCondition(Logic::CageCondition Icondition);

        Coordinate GetCoordinate();
        CageCondition GetCondition();
    };
}



#endif /* CAGE_H */