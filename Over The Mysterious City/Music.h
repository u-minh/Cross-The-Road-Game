#pragma once
#pragma comment(lib, "Winmm.lib")

#ifndef _MUSIC_H_
#define _MUSIC_H_

#include <iostream>
#include <Windows.h>

using namespace std;

static bool MusicMode = false; //music playing status (set to false by default)

class Music
{
public:
	Music()
	{
		mciSendString(LPCWSTR(L"open \"Sounds/theme_Laura-Shigihara.mp3\" type mpegvideo alias Theme"), NULL, 0, NULL);
	}
	void playTheme()
	{
		mciSendString(LPCWSTR(L"play Theme repeat"), NULL, 0, NULL);
	}
	void playSelection()
	{
		mciSendString(LPCWSTR(L"open \"Sounds/select.mp3\" type mpegvideo alias select"), NULL, 0, NULL);
		mciSendStringA(LPCSTR("play select from 10"), NULL, 0, NULL);
	}
	void playImpact()
	{
		mciSendString(LPCWSTR(L"open \"Sounds/impact.mp3\" type mpegvideo alias impact"), NULL, 0, NULL);
		mciSendStringA(LPCSTR("play impact from 10"), NULL, 0, NULL);
	}
	void playBird()
	{
        mciSendString(LPCWSTR(L"open \"Sounds/bird.mp3\" type mpegvideo alias bird"), NULL, 0, NULL);
        mciSendStringA(LPCSTR("play bird from 10"), NULL, 0, NULL);
	}
	void playCar()
	{
        mciSendString(LPCWSTR(L"open \"Sounds/car.mp3\" type mpegvideo alias car"), NULL, 0, NULL);
        mciSendStringA(LPCSTR("play car from 10"), NULL, 0, NULL);
	}
	void playTraffic()
	{
		mciSendString(LPCWSTR(L"open \"Sounds/traffic.mp3\" type mpegvideo alias traffic"), NULL, 0, NULL);
		mciSendStringA(LPCSTR("play traffic from 10"), NULL, 0, NULL);
	}
	void pause() { mciSendString(LPCWSTR(L"pause Theme"), NULL, 0, NULL); }
	void close() { mciSendString(LPCWSTR(L"close Theme"), NULL, 0, NULL); }
	void newPLay()
	{
		close();
		mciSendString(LPCWSTR(L"open \"Sounds/theme_Laura-Shigihara.mp3\" type mpegvideo alias Theme"), NULL, 0, NULL);
		playTheme();
	}
};
#endif _MUSIC_H_
