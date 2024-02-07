#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <thread>
#include <Windows.h>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 30
#define WIN_WIDTH 95

#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define UP_ARROW 72
#define DOWN_ARROW 80

#define ENTER_KEY 13
#define ESCAPE_KEY 27

#pragma execution_character_set( "utf-8" )

class Console
{
public:
	void initGame();
};

void color(int, int);
void gotoXY(int, int);
void FixConsoleWindow();

void SetColor(WORD);
void SetWindowSize(SHORT, SHORT);
void SetScreenBufferSize(SHORT, SHORT);
void SetCursor(bool, DWORD);

void DisableSelection();
void DisableResizeWindow();
void DisableCtrButton(bool, bool, bool);

void ShowScrollbar(BOOL);
void ChangeConsoleFontSize(SHORT);

void clrscr();