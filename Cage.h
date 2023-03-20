#include "Coordinate.h"

namespace Logic
{
    enum CageCondition
    {
        X = -1,
        FREE,
        O
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