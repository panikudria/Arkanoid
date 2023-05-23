#include "Block.h"

Block::Block() {
    SetDestroy(true);
}

void Block::SetDestroy(bool d) {
    bCanBeDestroyed = d;
}

bool Block::BlockHitCheck(Coordinate c_ball, Size s_ball) {
	if (c_ball.y <= (coordinate.y + size.height) && (c_ball.y + s_ball.height) >= coordinate.y &&
		c_ball.x <= (coordinate.x + size.width) && (c_ball.x + s_ball.width) >= coordinate.x) {

		if (bCanBeDestroyed) {
			SetVisible(false);
		}
		return true;
	}
	return false;
}


