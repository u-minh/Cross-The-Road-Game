#include "truck.h"

cTruck::~cTruck()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            gotoXY(j + GetX(), i + GetY());
            cout << ' ';
        }
    }
}

cTruck::cTruck(int x, int y, int speed)
{
    if (x < 1) mX = 1;
    else mX = x;

    if (y < 1) mY = 1;
    else mY = y;

    if (speed < 1) Speed = 1;
    else Speed = speed;
}

int cTruck::width()
{
    return this->width_;
}

void cTruck::draw()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            gotoXY(j + GetX(), i + GetY());
            cout << truck[i][j];
        }
    }
}
void cTruck::erase()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            gotoXY(j + GetX(), i + GetY());
            cout << ' ';
        }
    }
}

void cTruck::MakeSound()
{
    Music tmp;
    tmp.playCar();
}

void cTruck::Move()
{
    erase();
    color(15, 0);
    SetX(GetX() + GetSpeed());
    draw();
}


