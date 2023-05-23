#pragma once

#include<cmath>
#include <iostream>
#include <cstring>

#include "Framework.h"
#include "Element.h"
#include "Platform.h"
#include "Ball.h"
#include "Level.h"
#include "Block.h"
//#include "Ability.h"

class Game : public Framework {
public:
	virtual void PreInit(int& width, int& height, bool& fullscreen);
	virtual bool Init();
	virtual bool Tick();
	virtual void onMouseMove(int x, int y, int xrelative, int yrelative);
	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased);
	virtual void onKeyPressed(FRKey k);
	virtual void onKeyReleased(FRKey k);
	virtual const char* GetTitle() override;
	virtual void Close();

	Game(int, int);
private:
	static const int INTERVAL_PIX = 5;
	static const int MAX_LIVES = 6;

	int widthScreen;
	int heightScreen;
	bool bGameOver = false;
	bool bIsLevelOver = false;
	int pauseTick = 0;		// Pause counter for the Game Over screen.
	int lives = 1;

	Element* background;
	Platform* platform;
	Ball* ball;
	Element* ui;
	Level* level;
	Element* heart[MAX_LIVES];
	Element* lossScreen;
	Element* winScreen;

	 bool SetLives();
	 void DrawLife();
	 void SetVisibleLife();
	 bool SetBallDefault(Ball*);
	 bool SetPlatformDefault(Platform*);
};
