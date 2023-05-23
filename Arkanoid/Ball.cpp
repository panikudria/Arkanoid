#include "Ball.h"

Ball::Ball() {
	SetDefaultSettings();
}

void Ball::SetDefaultSettings() {
	defaultSpeed.x = currentSpeed.x = 0.6;
	defaultSpeed.y = currentSpeed.y = 0.6;
	tick = 0;
	bIsMove = false;
	bIsDropped = false;
}

void Ball::SetBorder(float left, float right, float top, float bottom) {
	upper_left_border.x = left;
	upper_left_border.y = top;
	lower_right_border.x = right;
	lower_right_border.y = bottom;
}

// Set the angle of the ball
void Ball::SetDirectionMove(int x, int y) {
	angle_direction = atan2((lower_right_border.y - y), (x - lower_right_border.x / 2));
	currentSpeed.x = cos(angle_direction) * defaultSpeed.x;
	currentSpeed.y = abs(sin(angle_direction)) * defaultSpeed.y;
}

void Ball::ChangeDirection(Coordinate c_block, Size s_block, unsigned int tick) {
	if (tick > this->tick) {
		currentSpeed.x *= ((coordinate.x - currentSpeed.x) > (c_block.x + s_block.width) ||
			(coordinate.x + size.width - currentSpeed.x) < c_block.x) ? -1 : 1;
		currentSpeed.y *= ((coordinate.y - currentSpeed.y) > (c_block.y + s_block.height) ||
			(coordinate.y + size.height - currentSpeed.y) < c_block.y) ? -1 : 1;
		this->tick = tick;
	}
}

//The ball moves when player click the left mouse button
void Ball::SetMove(bool bIsBallMove) {
	this->bIsMove = bIsBallMove;
	defaultSpeed.x = currentSpeed.x;
	defaultSpeed.y = currentSpeed.y;
	bIsDropped = false;
}


void Ball::Move(Coordinate coordinatePlatform, Size sizePlatform) {
	if (bIsMove) {
		// Ball deflects from right  and left edges
		if (coordinate.x + currentSpeed.x < NULL || (coordinate.x + size.width + currentSpeed.x) > lower_right_border.x) {
			currentSpeed.x *= -1;
		}
		// Ball deflects from up edges
		if (coordinate.y + currentSpeed.y < upper_left_border.y) {
			currentSpeed.y *= -1;
		}
		if ((coordinate.y + size.height + currentSpeed.y) >= coordinatePlatform.y) {
			//Ball deflects from player's platform
			if ((coordinate.x + currentSpeed.x + size.width / 2) >= coordinatePlatform.x &&
				(coordinate.x + currentSpeed.x + size.width / 2) <= (coordinatePlatform.x + sizePlatform.width)) {
				currentSpeed.y *= -1;
			}
			else {
				bIsMove = false;
				bIsDropped = true;
			}
		}
		coordinate.x += currentSpeed.x;
		coordinate.y += currentSpeed.y;
	}
}


