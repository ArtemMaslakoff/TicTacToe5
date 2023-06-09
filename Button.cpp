#include "Button.h"

using namespace Logic;
using namespace std;
using namespace sf;

namespace Visual
{
    Button::Button() : x(0), y(0), length(0), width(0), coordinate(Coordinate()) {};
    Button::Button(int Ix, int Iy, int Ilength, int Iwidth, array<int, 2> Iarray) : x(Ix), y(Iy), length(Ilength), width(Iwidth), coordinate(Coordinate(Iarray)) {};
    Button::Button(int Ix, int Iy, int Ilength, int Iwidth, Coordinate Icoordinate) : x(Ix), y(Iy), length(Ilength), width(Iwidth), coordinate(Icoordinate) {};

    Button::~Button() = default;

    void Button::SetX(int Ix)
    {
        x = Ix;
    };
    void Button::SetY(int Iy)
    {
        y = Iy;
    };
    void Button::SetCoordinate(Coordinate Icoordinate)
    {
        coordinate = Icoordinate;
    };
    void Button::SetLength(int Ilength)
    {
        length = Ilength;
    };
    void Button::SetWidth(int Iwidth)
    {
        width = Iwidth;
    };

    int Button::GetX()
    {
        return x;
    };
    int Button::GetY()
    {
        return y;
    };
    Coordinate Button::GetCoordinate()
    {
        return coordinate;
    };
    int Button::GetLength()
    {
        return length;
    };
    int Button::GetWidth()
    {
        return width;
    };

    void Button::Draw(RenderWindow& window, string file)
    {
        Texture texture;
        texture.loadFromFile(file);
        Sprite sprite;
        sprite.setTexture(texture);
        //sprite.setColor(sf::Color(255, 0, 0));
        sprite.setPosition(x * length,y * width);
        window.draw(sprite);
    };
    void Button::CheckClick(RenderWindow& window, Event& event)
    {
        if ((event.type == event.MouseButtonReleased && event.mouseButton.button == Mouse::Left) && (Mouse::getPosition(window).x > x && Mouse::getPosition(window).x < x + length) && (Mouse::getPosition(window).y > y && Mouse::getPosition(window).y < y + width))
        {

        }
    };
}