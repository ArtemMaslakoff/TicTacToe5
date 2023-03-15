#ifndef BUTTON_H
#define BUTTON_H



#include "Coordinate.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;
using namespace N;

namespace Visual
{
    class Button
    {
    private:
        Coordinate coordinate;

        int x;
        int y;

        int length;
        int width;
    public:
        Button();
        Button(int Ix, int Iy, int Ilength, int Iwidth, array<int, 2> Iarray);

        ~Button();

        void SetX(int Ix);
        void SetY(int Iy);
        void SetCoordinate(Coordinate Icoordinate);
        void SetLength(int Ilength);
        void SetWidth(int Iwidth);

        int GetX();
        int GetY();
        Coordinate GetCoordinate();
        int GetLength();
        int GetWidth();

        void Draw(RenderWindow& window);
        void CheckClick(RenderWindow& window, Event& event);
    };
}

//class Button
//{
//public:
//    string name;
//
//    int x = 0;
//    int y = 0;
//
//    int length = 0;
//    int width = 0;
//    Button() = default;
//    bool Check(RenderWindow& window, Event& event)
//    {
//        if ((event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left) && (Mouse::getPosition(window).x > x && Mouse::getPosition(window).x < x + length) && (Mouse::getPosition(window).y > y && Mouse::getPosition(window).y < y + width))
//        {
//            return true;
//        }
//        return false;
//    };
//    virtual void DoEvent(GameScene& activeScene, GameScene& notActiveScene, GameTable& gameTable) {};
//};

#endif /* BUTTON_H */