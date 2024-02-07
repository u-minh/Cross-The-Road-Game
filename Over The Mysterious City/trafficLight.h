#pragma once

#include "console.h"
#include <time.h>

using namespace std;

class Traffic_Light
{
private:
	char light[3][3] = { ' ','_',' ',
						'|','o','|',
						' ','|',' ' };
	int mX, mY;
	bool isRed; //checking status of light (is not static since every light has different changing time)
public:
	Traffic_Light();
	Traffic_Light(int, int);
	Traffic_Light(const Traffic_Light&);
	Traffic_Light& operator=(const Traffic_Light&);
	
	void drawLight();
	void setRed(bool); //set light status
	bool stop(); //check if the light is red or not
	void changeLight(int);
};