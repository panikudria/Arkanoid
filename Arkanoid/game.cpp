#include "inc/Game.h"


void Game::DrawLife() {
	lives = lives < MAX_LIVES ? lives : MAX_LIVES;
	for (int count = 0; count < lives; count++) {
		heart[count]->Draw();
	}
}

bool Game::SetBallDefault(Ball* b) {

	float x = (widthScreen - ((widthScreen / 70) * 2)) / 2;
	float y = heightScreen - platform->GetSize().height - ((widthScreen / 70) * 2);
	b->SetElement(x, y, ((widthScreen / 70) * 2), ((widthScreen / 70) * 2), true, "data/06-Breakout-Tiles.png");
	b->SetDefaultSettings();
	//TODO Errors
	return true;
}

void Game::SetVisibleLife() {
	for (int count = 0; count < lives; count++) {
		heart[count]->SetVisible(true);
	}
	for (int count = lives; count < MAX_LIVES; count++) {
		heart[count]->SetVisible(false);
	}
}

bool Game::SetPlatformDefault(Platform* p) {
	float x = (widthScreen - (widthScreen / 7)) / 2;
	float y = heightScreen - (heightScreen / 20);
	p->SetElement(x, y, (widthScreen / 7), (heightScreen / 20), true, "data/05-Breakout-Tiles.png");

	//TODO Errors
	return true;
}


Game::Game(int width, int height)	{
	widthScreen = width <= 0 ? 320 : width;
	heightScreen = height <= 0 ? 200 : height;
}


bool Game::SetLives() {
	float x, y;
	bool status = true;
	int d = ui->GetSize().height / 2;
	for (int count = 0; count < MAX_LIVES; count++) {
		x = (ui->GetSize().height / 4.5) + ((ui->GetSize().height / 1.5) + INTERVAL_PIX) * count;
		y = ui->GetSize().height / 4.5;
		heart[count] = new Element();
		status = status && heart[count]->SetElement(x, y, d, d, false, "data/07-Breakout-Tiles.png");
	}
	lives = 1;
	SetVisibleLife();
	return status;
}

		
void Game::PreInit(int& width, int& height, bool& fullscreen) {
	width = widthScreen;
	height = heightScreen;
	fullscreen = false;
}

bool Game::Init() {

	//TODO Errors

	float x, y;

	getScreenSize(widthScreen, heightScreen);
	
	background = new Element();
	if (!background->SetElement(0, 0, widthScreen, heightScreen, true, "data/00-Background.png")) {
		printf("background is not set");
	}

	ui = new Element();
	ui->SetElement(0, 0, widthScreen, (heightScreen / 17), true, "data/00-Background.png");
	
	SetLives();

	level = new Level();
	level->SetIntervalPix(INTERVAL_PIX);
	level->SetCoordinateFiled(0, widthScreen, ui->GetSize().height, heightScreen);
	level->SetBlocks();

	platform = new Platform();
	SetPlatformDefault(platform);
	platform->SetBorder(widthScreen, 0);
	
	ball = new Ball();
	SetBallDefault(ball);
	ball->SetBorder(0, widthScreen, ui->GetSize().height, heightScreen);
	

	lossScreen = new Element();
	lossScreen->SetElement(0, 0, widthScreen, heightScreen, false, "data/10-Breakout-Tiles.png");

	winScreen = new Element();
	winScreen->SetElement(0, 0, widthScreen, heightScreen, false, "data/13-Breakout-Tiles.png");

	bIsLevelOver = false;
	pauseTick = 300;
	//TODO Errors
	return true;
}

void Game::Close() {

}

bool Game::Tick() {
	drawTestBackground();
	if (bIsLevelOver) {
		if (level->LevelWon()) {
			winScreen->SetVisible(true);
			winScreen->Draw();
			bGameOver = !level->AddLevel();
		}
		else if (lives <= 0) {
			lossScreen->SetVisible(true);
			lossScreen->Draw();
			bGameOver = true;
		}
		if (pauseTick == 0) {
			pauseTick = 300;
			if (bGameOver) {
			return true;
			//TODO del
			}
			else {
				level->SetBlocks();
				bIsLevelOver = false;
				SetPlatformDefault(platform);
				SetBallDefault(ball);
				ball->SetMove(false);
			}
		}
		else {
			pauseTick--;
		}
	}
	else {
		background->Draw();
		ui->Draw();
		DrawLife();

		platform->Move();
		platform->Draw();

		// When the ball has fallen, but the player still has a life - 
		// set the initial values for the ball platform to continue the game.
		if (ball->IsDropped()) {
			lives--;
			SetBallDefault(ball);
			SetPlatformDefault(platform);
		}

		ball->Move(platform->GetCoordinate(), platform->GetSize());
		ball->Draw();


		level->DrawBlocks(ball);

		bIsLevelOver = (level->LevelWon() || lives <= 0);

	}
	return false;
}

void Game::onMouseMove(int x, int y, int xrelative, int yrelative) {
	if (!ball->IsMove()) {
		ball->SetDirectionMove(x, y);
	}
}

void Game::onMouseButtonClick(FRMouseButton button, bool isReleased) {
	if (!ball->IsMove()) {
		ball->SetMove(true);
	};
}

void Game::onKeyPressed(FRKey k) {
	if (ball->IsMove()) {
		if (k == FRKey::RIGHT) {
			platform->SetDirection(true, +1);
		}
		else if (k == FRKey::LEFT) {
			platform->SetDirection(true, -1);
		}
	}
}

void Game::onKeyReleased(FRKey k) {
	platform->SetDirection(false);
}

const char* Game::GetTitle() {
	return "Arcanoid";
}