#include "Element.h"

Element::Element() {
	size.width = NULL;
	size.height = NULL;
	coordinate.x = NULL;
	coordinate.y = NULL;
	bIsVisible = false;
}

bool Element::SetElement(int x, int y, int w, int h, bool visible, const char path[]) {
	spriteElement = createSprite(path);
	if (SetCoordinate(x, y) && (SetSize(w, h)) && (SetVisible(visible)) && spriteElement != nullptr) {
		setSpriteSize(spriteElement, size.width, size.height);
		return true;
	}
	return false;
}

void Element::Draw() {
	if (bIsVisible)
		drawSprite(spriteElement, coordinate.x, coordinate.y);
}

bool Element::SetCoordinate(float x, float y) {
	if (x >= 0. && y >= 0.) {
		coordinate.x = x;
		coordinate.y = y;
		return true;
	}
	
	return false;
}

bool Element::SetSize(float w, float h) {
	if (w > 0. && h > 0.) {
		size.width = w;
		size.height = h;
		return true;
	}

	return false;
}

bool Element::SetVisible(bool visible) {
	bIsVisible = visible;
	return true;
}

