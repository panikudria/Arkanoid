#pragma once
#include "Framework.h"
#include <cstddef>

class Element {


public:
	
	struct Coordinate { 
		float x; 
		float y; };

	struct Size { 
		float width;
		float height; };

	//Element(const char[], Coordinate, Size, bool);
	Element();

	bool SetElement(int x, int y, int w, int h, bool visible, const char path[]);
	bool SetVisible(bool);
	void Draw();
	

	Size const GetSize() { return size; }
	Coordinate const GetCoordinate() { return coordinate; }
	bool const GetVisible() { return bIsVisible; }


	/*bool SetTexture(const char[]);*/

protected:
	

	bool SetCoordinate(float, float);
	bool SetSize(float, float);
	

	Coordinate coordinate;
	Size size;
	bool bIsVisible;
	/*char *texture_path;*/
	Sprite* spriteElement;


};

