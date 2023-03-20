#ifndef BUTTON_H
#define BUTTON_H



#include "Coordinate.h"
#include <SFML/Graphics.hpp>
#include <array>

namespace Visual
{
    class Button
    {
    private:
        Logic::Coordinate coordinate;

        int x;
        int y;

        int length;
        int width;
    public:
        Button();
        Button(int Ix, int Iy, int Ilength, int Iwidth, std::array<int, 2> Iarray);
        Button(int Ix, int Iy, int Ilength, int Iwidth, Logic::Coordinate Icoordinate);

        ~Button();

        void SetX(int Ix);
        void SetY(int Iy);
        void SetCoordinate(Logic::Coordinate Icoordinate);
        void SetLength(int Ilength);
        void SetWidth(int Iwidth);

        int GetX();
        int GetY();
        Logic::Coordinate GetCoordinate();
        int GetLength();
        int GetWidth();

        void Draw(sf::RenderWindow& window, std::string file);
        void CheckClick(sf::RenderWindow& window, sf::Event& event);
    };
}



#endif /* BUTTON_H */