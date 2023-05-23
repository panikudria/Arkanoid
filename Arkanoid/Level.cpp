#include "Level.h"

Level::Level() {
	numCurrentLevel = 1;
	SetLevel();
}

void Level::SetIntervalPix(unsigned short int pix) {
	intervalPix = pix;
}

void Level::SetCoordinateFiled(float left, float right, float top, float bottom) {
	upper_left_border.x = left;
	upper_left_border.y = top;
	lower_right_border.x = right;
	lower_right_border.y = bottom;
}

bool Level::LevelWon() {
	return (numOfBlocks == 0);
}

bool Level::SetLevel() {
	
	switch (numCurrentLevel) {
	case 1:
		currentLevel = L1;
		break;
	case 2:
		currentLevel = L2;
		break;
	case 3:
		currentLevel = L3;
		break;
	case 4:
		currentLevel = L4;
	default:
		numCurrentLevel = 1;
		return false;
		break;
	}
	return true;
}

bool Level::SetBlocks() {
	numOfBlocks = 0;
	numOfRedBlocks = 0;

	float yBlock, xBlock;
	sizeBlock.width = (lower_right_border.x - (intervalPix * BLOCKS_IN_COLUMN + intervalPix)) / BLOCKS_IN_COLUMN;
	sizeBlock.height = lower_right_border.y / 20;
	for (int row = 0; row < BLOCKS_IN_ROW; row++) {
		yBlock = upper_left_border.y + intervalPix + row * (sizeBlock.height + intervalPix);
		for (int column = 0; column < BLOCKS_IN_COLUMN; column++) {
			xBlock = intervalPix + column * (sizeBlock.width + intervalPix);
			block[row][column] = new Block();
			switch (currentLevel[row][column]) {
			case Level::eBlockType::BLUE:
				block[row][column]->SetElement(  xBlock, yBlock, sizeBlock.width, sizeBlock.height, true, "data/02-Breakout-Tiles.png");
				block[row][column]->SetDestroy(true);
				numOfBlocks++;
				break;
			case Level::eBlockType::GREEN:
				block[row][column]->SetElement(xBlock, yBlock, sizeBlock.width, sizeBlock.height, true, "data/03-Breakout-Tiles.png");
				block[row][column]->SetDestroy(true);
				numOfBlocks++;
				break;
			case Level::eBlockType::RED:
				block[row][column]->SetElement(xBlock, yBlock, sizeBlock.width, sizeBlock.height, true, "data/01-Breakout-Tiles.png");
				block[row][column]->SetDestroy(false);
				numOfRedBlocks++;
				numOfBlocks++;
				break;
			case Level::eBlockType::NO_BLOCK:
				block[row][column]->SetElement(xBlock, yBlock, sizeBlock.width, sizeBlock.height, false, "data/01-Breakout-Tiles.png");
				block[row][column]->SetDestroy(false);
				break;
			default:
				return false;
				break;
			}
		}
	}
	return true;
}

bool Level::DrawBlocks(Ball* ball) {
	for (int row = 0; row < BLOCKS_IN_ROW; row++)
		for (int column = 0; column < BLOCKS_IN_COLUMN; column++) {
			if (block[row][column]->GetVisible()){

				//When the ball hit the block
				if (block[row][column]->BlockHitCheck(ball->GetCoordinate(), ball->GetSize())) {
					
					if (currentLevel[row][column] != eBlockType::RED || (numOfRedBlocks >= numOfBlocks)) {
						currentLevel[row][column] = eBlockType::NO_BLOCK;
						block[row][column]->SetDestroy(true);
						numOfBlocks--;

					}
					
					//The ball reflects from block
					ball->ChangeDirection(block[row][column]->GetCoordinate(), block[row][column]->GetSize(), getTickCount());
				}

				block[row][column]->Draw();
				//Allow red blocks to be broken when all others are broken
				if (!block[row][column]->GetDestroy() && numOfBlocks <= numOfRedBlocks) {
					block[row][column]->SetDestroy(true);
				}

			}
		}
	return true;

}

bool Level::AddLevel() {
	numCurrentLevel++;
	return SetLevel();
}


