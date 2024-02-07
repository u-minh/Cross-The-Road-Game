#pragma once

#ifndef _cTruck_H_
#define _cTruck_H_

#include <iostream>
#include <Windows.h>
#include "vehicle.h"
#include <mmsystem.h>
#include "console.h"
#include "Music.h"

using namespace std;

class cTruck : public cVehicle
{
private:
    const unsigned int width_ = 13;
    const char truck[2][13] = { ' ', '_', '_', '_', '_', '_', '|', 'L', '\\', '_', '_', '_', ' ',
                        '(', '_', ',', '.', '_', '_', '_', '_', '_', ',', '.', '_', ')' };

public:
    cTruck(int, int, int);
    ~cTruck();

    int width(); //get width method
    void draw() override;
    void erase() override;
    void MakeSound() override;
    void Move() override;
};
#endif