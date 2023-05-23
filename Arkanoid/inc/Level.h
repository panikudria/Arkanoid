#pragma once
#include "Block.h"
#include "Ball.h"

class Level{

public:
	enum class eBlockType {
		NO_BLOCK,
		BLUE,
		GREEN,
		RED
	};

	Level();
	void SetIntervalPix(unsigned short int);
	void SetCoordinateFiled(float left, float right, float top, float bottom);

	int GetBlocksInColumn() { return BLOCKS_IN_COLUMN; }
	int GetBlocksInRow() { return BLOCKS_IN_ROW; }
	eBlockType GetBlockType(int r, int c) { return currentLevel[r][c]; }
	bool LevelWon();

	bool SetLevel();
	bool SetBlocks();
	bool DrawBlocks(Ball*);
	bool AddLevel();

private:
	static const int BLOCKS_IN_COLUMN = 10;
	static const int BLOCKS_IN_ROW = 6;

	Block* block[BLOCKS_IN_ROW][BLOCKS_IN_COLUMN];

	int numOfBlocks, numOfRedBlocks;
	unsigned int numCurrentLevel = 1;
	unsigned short intervalPix;
	Element::Coordinate upper_left_border, lower_right_border;
	Element::Size sizeBlock;


	eBlockType (*currentLevel)[BLOCKS_IN_COLUMN];

	using B = eBlockType;

	eBlockType L1[BLOCKS_IN_ROW][BLOCKS_IN_COLUMN] = {
		{B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK},
		{B::NO_BLOCK, B::NO_BLOCK,B::NO_BLOCK, B::BLUE, B::BLUE, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK},
		{B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK},
		{B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK},
		{B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK},
		{B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK},
	};

	eBlockType L2[BLOCKS_IN_ROW][BLOCKS_IN_COLUMN] = {
		{B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK},
		{B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK},
		{B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK},
		{B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK},
		{B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK},
		{B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK, B::NO_BLOCK},
	};

	/*eBlockType L2[BLOCKS_IN_ROW][BLOCKS_IN_COLUMN] = {
		{B::RED, B::RED, B::RED, B::RED, B::RED, B::RED, B::RED, B::RED, B::RED, B::RED,},
		{B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE},
		{B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE},
		{B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE},
		{B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE},
		{B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE},
	};*/

	eBlockType L3[BLOCKS_IN_ROW][BLOCKS_IN_COLUMN] = {
		{B::RED, B::RED, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::RED, B::RED,},
		{B::RED, B::RED, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::RED, B::RED,},
		{B::RED, B::RED, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::RED, B::RED,},
		{B::RED, B::RED, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::RED, B::RED,},
		{B::RED, B::RED, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::RED, B::RED,},
		{B::RED, B::RED, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::RED, B::RED,},
	};

	eBlockType L4[BLOCKS_IN_ROW][BLOCKS_IN_COLUMN] = {
		{B::RED, B::RED, B::RED, B::RED, B::RED, B::RED, B::RED, B::RED, B::RED, B::RED,},
		{B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE},
		{B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE},
		{B::GREEN, B::GREEN, B::GREEN, B::GREEN, B::GREEN, B::GREEN, B::GREEN, B::GREEN, B::GREEN, B::GREEN},
		{B::BLUE, B::BLUE, B::BLUE, B::GREEN, B::BLUE, B::BLUE, B::GREEN, B::BLUE, B::BLUE, B::BLUE},
		{B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE, B::BLUE},
	};

};

