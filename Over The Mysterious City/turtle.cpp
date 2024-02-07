#include "turtle.h"

cTurtle::~cTurtle()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            gotoXY(j + GetX(), i + GetY());
            cout << ' ';
        }
    }
}

cTurtle::cTurtle (int x, int y, int speed)
    : cAnimal(x, y, speed)
{}

int cTurtle::width()
{
    return this->width_;
}

void cTurtle::draw()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            gotoXY(j + GetX(), i + GetY());
            cout << turtle[i][j];
        }
    }
}

void cTurtle::erase()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            gotoXY(j + GetX(), i + GetY());
            cout << ' ';
        }
    }
}

void cTurtle::MakeSound()
{
    Music tmp;
    tmp.playCar();
}

void cTurtle::Move()
{
    erase();
    color(15, 0);
    SetX(GetX() + GetSpeed());
    draw();
}

