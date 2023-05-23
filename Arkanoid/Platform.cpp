#include"Platform.h"

void Platform::Move() {
	if (bIsMove && (GetCoordinate().x + direction * speed) >= l_border &&
		(GetCoordinate().x + direction * speed + GetSize().width) <= r_border) {
		float x = GetCoordinate().x;
		x += direction * speed;
		SetCoordinate(x, GetCoordinate().y);
	}
}

void Platform::SetBorder(float r, float l) {
	r_border = r;
	l_border = l;
}

void Platform::SetDirection(bool bIsMove, int direction) {
	this->direction = direction;
	this->bIsMove = bIsMove;
}
